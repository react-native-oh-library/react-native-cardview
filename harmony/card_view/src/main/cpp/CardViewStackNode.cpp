#include "CardViewStackNode.h"
#include "NativeNodeApi.h"
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <memory>

namespace rnoh {
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
        ArkUI_NumberValue indexValue[] = {5,0, {.f32 = elevation}, {.f32 = elevation},ARKUI_SHADOW_TYPE_COLOR,static_cast<float>(0XFF7080BB),0};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_CUSTOM_SHADOW, &indexItem));
        return *this;
    }
    CardViewStackNode &CardViewStackNode::setCardMaxElevation(const float &MaxElevation) {
        ArkUI_NumberValue indexValue[] = {0, 0, {.f32 = MaxElevation}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_TRANSFORM_CENTER, &indexItem));
        return *this;
    }
    CardViewStackNode &CardViewStackNode::setUseCompatPadding(bool const  &padding) {
        if (!padding) {
            return *this;
      }
        ArkUI_NumberValue indexValue[] = {{static_cast<float>(padding)}};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_PADDING, &indexItem));
        return *this;
    }
    CardViewStackNode &CardViewStackNode::setCornerOverlap(bool const &overlap) {
        if (!overlap) {
            return *this;
       }
        ArkUI_NumberValue indexValue[] = {ARKUI_BLEND_MODE_NONE,BLEND_APPLY_TYPE_FAST};
        ArkUI_AttributeItem indexItem = {indexValue, sizeof(indexValue) / sizeof(ArkUI_NumberValue)};
        maybeThrow(NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_BLEND_MODE, &indexItem));
        return *this;
    }
} // namespace rnoh