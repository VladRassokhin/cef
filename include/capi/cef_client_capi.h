// Copyright (c) 2021 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=4cfcac55d2a1dee466a2a0753f30fb34a78ef3b2$
//

#ifndef CEF_INCLUDE_CAPI_CEF_CLIENT_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_CLIENT_CAPI_H_
#pragma once

#include "include/capi/cef_audio_handler_capi.h"
#include "include/capi/cef_base_capi.h"
#include "include/capi/cef_context_menu_handler_capi.h"
#include "include/capi/cef_dialog_handler_capi.h"
#include "include/capi/cef_display_handler_capi.h"
#include "include/capi/cef_download_handler_capi.h"
#include "include/capi/cef_drag_handler_capi.h"
#include "include/capi/cef_find_handler_capi.h"
#include "include/capi/cef_focus_handler_capi.h"
#include "include/capi/cef_jsdialog_handler_capi.h"
#include "include/capi/cef_keyboard_handler_capi.h"
#include "include/capi/cef_life_span_handler_capi.h"
#include "include/capi/cef_load_handler_capi.h"
#include "include/capi/cef_media_access_handler_capi.h"
#include "include/capi/cef_process_message_capi.h"
#include "include/capi/cef_render_handler_capi.h"
#include "include/capi/cef_request_handler_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
// Implement this structure to provide handler implementations.
///
typedef struct _cef_client_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Return the handler for audio rendering events.
  ///
  struct _cef_audio_handler_t*(CEF_CALLBACK* get_audio_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for context menus. If no handler is provided the default
  // implementation will be used.
  ///
  struct _cef_context_menu_handler_t*(CEF_CALLBACK* get_context_menu_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for dialogs. If no handler is provided the default
  // implementation will be used.
  ///
  struct _cef_dialog_handler_t*(CEF_CALLBACK* get_dialog_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for browser display state events.
  ///
  struct _cef_display_handler_t*(CEF_CALLBACK* get_display_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for download events. If no handler is returned downloads
  // will not be allowed.
  ///
  struct _cef_download_handler_t*(CEF_CALLBACK* get_download_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for drag events.
  ///
  struct _cef_drag_handler_t*(CEF_CALLBACK* get_drag_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for find result events.
  ///
  struct _cef_find_handler_t*(CEF_CALLBACK* get_find_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for focus events.
  ///
  struct _cef_focus_handler_t*(CEF_CALLBACK* get_focus_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for media access permissions requests. If no handler is
  // provided media access will be denied by default.
  ///
  struct _cef_media_access_handler_t*(CEF_CALLBACK* get_media_access_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for JavaScript dialogs. If no handler is provided the
  // default implementation will be used.
  ///
  struct _cef_jsdialog_handler_t*(CEF_CALLBACK* get_jsdialog_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for keyboard events.
  ///
  struct _cef_keyboard_handler_t*(CEF_CALLBACK* get_keyboard_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for browser life span events.
  ///
  struct _cef_life_span_handler_t*(CEF_CALLBACK* get_life_span_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for browser load status events.
  ///
  struct _cef_load_handler_t*(CEF_CALLBACK* get_load_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for off-screen rendering events.
  ///
  struct _cef_render_handler_t*(CEF_CALLBACK* get_render_handler)(
      struct _cef_client_t* self);

  ///
  // Return the handler for browser request events.
  ///
  struct _cef_request_handler_t*(CEF_CALLBACK* get_request_handler)(
      struct _cef_client_t* self);

  ///
  // Called when a new message is received from a different process. Return true
  // (1) if the message was handled or false (0) otherwise. Do not keep a
  // reference to or attempt to access the message outside of this callback.
  ///
  int(CEF_CALLBACK* on_process_message_received)(
      struct _cef_client_t* self,
      struct _cef_browser_t* browser,
      struct _cef_frame_t* frame,
      cef_process_id_t source_process,
      struct _cef_process_message_t* message);
} cef_client_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_CLIENT_CAPI_H_
