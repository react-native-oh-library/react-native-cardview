/**
 * MIT License
 *
 * Copyright (C) 2024 Huawei Device Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "NativeNodeApi.h"
#include <glog/logging.h>

namespace rnoh {

ArkUI_NativeNodeAPI_1* NativeNodeApi::getInstance() {
#ifdef C_API_ARCH
  static ArkUI_NativeNodeAPI_1* INSTANCE = nullptr;
  if (INSTANCE == nullptr) {
    OH_ArkUI_GetModuleInterface(
        ARKUI_NATIVE_NODE, ArkUI_NativeNodeAPI_1, INSTANCE);
    if (INSTANCE == nullptr) {
      DLOG(FATAL) << "Failed to get native node API instance.";
    }
  }
  return INSTANCE;
#endif
}

} // namespace rnoh