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

#include "CardViewComponentInstance.h"
#include "Props.h"
#include "CardViewStackNode.h"

namespace rnoh {
CardViewComponentInstance::CardViewComponentInstance(Context context) : CppComponentInstance(std::move(context)) {}

void CardViewComponentInstance::onChildInserted(ComponentInstance::Shared const &childComponentInstance,
                                                std::size_t index) {
    m_stackNode.insertChild(childComponentInstance->getLocalRootArkUINode(), index);
}

void CardViewComponentInstance::onChildRemoved(ComponentInstance::Shared const &childComponentInstance) {
    m_stackNode.removeChild(childComponentInstance->getLocalRootArkUINode());
};

CardViewStackNode &CardViewComponentInstance::getLocalRootArkUINode() { return m_stackNode; }

void CardViewComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
    CppComponentInstance::onPropsChanged(props);
    if (auto p = std::dynamic_pointer_cast<const facebook::react::RNCardViewProps>(props)) {
        this->backgroundcolor = p->backgroundcolor;
        this->cornerRadius = p->cornerRadius;
        this->cardElevation = p->cardElevation;
        this->cardMaxElevation = p->cardMaxElevation;
        this->getLocalRootArkUINode().setBackgroundColor(p->backgroundcolor);
        this->getLocalRootArkUINode().setCornerRadius(p->cornerRadius);
        this->getLocalRootArkUINode().setCardElevation(p->cardElevation);
        this->getLocalRootArkUINode().setCardMaxElevation(p->cardMaxElevation);
    }
}
void CardViewComponentInstance::getNapiProps(facebook::react::Props::Shared props) {
    auto p = std::dynamic_pointer_cast<const facebook::react::RNCardViewProps>(props);
    this->backgroundcolor = p->backgroundcolor;
    this->cornerRadius = p->cornerRadius;
    this->cardElevation = p->cardElevation;
    this->cardMaxElevation = p->cardMaxElevation;
}
}