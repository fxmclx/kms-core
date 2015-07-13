/*
 * (C) Copyright 2015 Kurento (http://kurento.org/)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifndef __KMS_SDP_SESSION_H__
#define __KMS_SDP_SESSION_H__

#include <gst/gst.h>
#include "sdpagent/kmssdpagent.h"

G_BEGIN_DECLS
/* #defines don't like whitespacey bits */
#define KMS_TYPE_SDP_SESSION \
  (kms_sdp_session_get_type())
#define KMS_SDP_SESSION(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),KMS_TYPE_SDP_SESSION,KmsSdpSession))
#define KMS_SDP_SESSION_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),KMS_TYPE_SDP_SESSION,KmsSdpSessionClass))
#define KMS_IS_SDP_SESSION(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),KMS_TYPE_SDP_SESSION))
#define KMS_IS_SDP_SESSION_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),KMS_TYPE_SDP_SESSION))
#define KMS_SDP_SESSION_CAST(obj) ((KmsSdpSession*)(obj))

typedef struct _KmsSdpSession KmsSdpSession;
typedef struct _KmsSdpSessionClass KmsSdpSessionClass;
typedef struct _KmsSdpSessionPrivate KmsSdpSessionPrivate;

struct _KmsSdpSession
{
  GstBin parent;

  KmsSdpSessionPrivate *priv;
};

struct _KmsSdpSessionClass
{
  GstBinClass parent_class;
};

GType kms_sdp_session_get_type (void);

KmsSdpSession * kms_sdp_session_new ();
GstSDPMessage * kms_sdp_session_generate_offer (KmsSdpSession * self);
GstSDPMessage * kms_sdp_session_process_offer (KmsSdpSession * self, GstSDPMessage * offer);
void kms_sdp_session_process_answer (KmsSdpSession * self, GstSDPMessage * answer);
SdpMessageContext * kms_sdp_session_get_local_sdp_ctx (KmsSdpSession * self);
SdpMessageContext * kms_sdp_session_get_remote_sdp_ctx (KmsSdpSession * self);
SdpMessageContext * kms_sdp_session_get_neg_sdp_ctx (KmsSdpSession * self);
void kms_sdp_session_set_use_ipv6 (KmsSdpSession * self, gboolean use_ipv6);
void kms_sdp_session_set_addr (KmsSdpSession *self, const gchar * addr);

G_END_DECLS
#endif /* __KMS_SDP_SESSION_H__ */
