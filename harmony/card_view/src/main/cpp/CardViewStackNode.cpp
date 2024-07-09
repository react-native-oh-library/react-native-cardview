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

#include "CardViewStackNode.h"
#include "NativeNodeApi.h"
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <memory>

namespace rnoh {
float maxElevation{10.0};
float cardElevation{0.0};


CardViewStackNode::CardViewStackNode()
    : ArkUINode(NativeNodeApi::getInstance()->createNode(ArkUI_NodeType::ARKUI_NODE_STACK)) {}

void CardViewStackNode::insertChild(ArkUINode &child, std::size_t index) {
    maybeThrow(NativeNodeApi::getInstance()->addChild(m_nodeHandle, child.getArkUINodeHandle()));
    }

    void CardViewStackNode::removeChild(ArkUINode &child) {
        maybeThrow(NativeNodeApi::getInstance()->removeChild(m_nodeHandle, child.getArkUINodeHandle()));
    }
    
    CardViewStackNode &CardViewStackNode::setBackgroundColor(int const &backgroundcolor) {
        ArkUI_NumberValue indexValue[] = {{.i32 = backgroundcolor}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_BACKGROUND_COLOR, &indexItem));
        return *this;
    }
    CardViewStackNode &CardViewStackNode::setCornerRadius(const float &radius) {
        ArkUI_NumberValue indexValue[] = {{.f32 = radius}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_BORDER_RADIUS, &indexItem));
        return *this;
    }
    CardViewStackNode &CardViewStackNode::setCardElevation(const float &elevation) {
        if (elevation > maxElevation) {
            cardElevation = maxElevation;
        } else {
            cardElevation = elevation;
        }
        ArkUI_NumberValue indexValue[] = {{.f32 = cardElevation}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_SHADOW, &indexItem));
        return *this;
    }
    CardViewStackNode &CardViewStackNode::setCardMaxElevation(const float &MaxElevation) {
        maxElevation = MaxElevation;
        return *this;
    }
} // namespace rnoh