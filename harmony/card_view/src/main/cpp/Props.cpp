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

#include "Props.h"
#include <react/renderer/core/PropsParserContext.h>
#include <react/renderer/core/propsConversions.h>

namespace facebook {
namespace react {
RNCardViewProps::RNCardViewProps(const PropsParserContext &context, const RNCardViewProps &sourceProps,
                                 const RawProps &rawProps)
    : ViewProps(context, sourceProps, rawProps),
      backgroundcolor(convertRawProp(context, rawProps, "backgroundcolor", sourceProps.backgroundcolor, 0)),
      cornerRadius(convertRawProp(context, rawProps, "cornerRadius", sourceProps.cornerRadius, {0.0})),
      cardElevation(convertRawProp(context, rawProps, "cardElevation", sourceProps.cardElevation, {0.0})),
      cardMaxElevation(convertRawProp(context, rawProps, "cardMaxElevation", sourceProps.cardMaxElevation, {0.0})),
      useCompatPadding(convertRawProp(context, rawProps, "useCompatPadding", sourceProps.useCompatPadding, {false})),
      cornerOverlap(convertRawProp(context, rawProps, "cornerOverlap", sourceProps.cornerOverlap, {true})) {}

} // namespace react
} // namespace facebook