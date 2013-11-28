// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_RENDERER_HOST_PEPPER_PEPPER_BROKER_MESSAGE_FILTER_H_
#define CHROME_BROWSER_RENDERER_HOST_PEPPER_PEPPER_BROKER_MESSAGE_FILTER_H_

#include "base/compiler_specific.h"
#include "googleurl/src/gurl.h"
#include "ppapi/c/pp_instance.h"
#include "ppapi/host/resource_message_filter.h"

namespace content {
class BrowserPpapiHost;
}

namespace ppapi {
namespace host {
struct HostMessageContext;
}
}

namespace chrome {

// This filter handles messages for the PepperBrokerHost on the UI thread.
class PepperBrokerMessageFilter : public ppapi::host::ResourceMessageFilter {
 public:
  PepperBrokerMessageFilter(PP_Instance instance,
                            content::BrowserPpapiHost* host);

 private:
  virtual ~PepperBrokerMessageFilter();

  // ppapi::host::ResourceMessageFilter overrides.
  virtual scoped_refptr<base::TaskRunner> OverrideTaskRunnerForMessage(
      const IPC::Message& message) OVERRIDE;
  virtual int32_t OnResourceMessageReceived(
      const IPC::Message& msg,
      ppapi::host::HostMessageContext* context) OVERRIDE;

  int32_t OnIsAllowed(ppapi::host::HostMessageContext* context);

  int render_process_id_;
  GURL document_url_;

  DISALLOW_COPY_AND_ASSIGN(PepperBrokerMessageFilter);
};

}  // namespace chrome

#endif  // CHROME_BROWSER_RENDERER_HOST_PEPPER_PEPPER_BROKER_MESSAGE_FILTER_H_