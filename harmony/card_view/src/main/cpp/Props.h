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

#ifndef HARMONY_CARDVIEW_SRC_MAIN_CPP_PROPS_H
#define HARMONY_CARDVIEW_SRC_MAIN_CPP_PROPS_H

#include "ReactCommon/TurboModule.h"
#include <react/renderer/components/view/ViewProps.h>
#include <react/renderer/core/PropsParserContext.h>
namespace facebook {
namespace react {

class JSI_EXPORT RNCardViewProps final : public ViewProps {
 public:
  RNCardViewProps() = default;
  RNCardViewProps(const PropsParserContext &context, const RNCardViewProps &sourceProps, const RawProps &rawProps);

#pragma mark - Props
  
  Float cornerRadius{0.0};  
  Float  cardElevation{0.0}; 
  Float cardMaxElevation{0.0}; 
  bool useCompatPadding{false}; 
  bool cornerOverlap{true};
  int backgroundcolor{0};
};
} // namespace react
} // namespace facebook

#endif