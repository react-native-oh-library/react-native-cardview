#include "CardViewComponentInstance.h"
#include "Props.h"
#include "CardViewStackNode.h"

namespace rnoh {
CardViewComponentInstance::CardViewComponentInstance(Context context) : CppComponentInstance(std::move(context)) {}

void CardViewComponentInstance::onChildInserted(ComponentInstance::Shared const &childComponentInstance,
                                                std::size_t index) {
    //      CppComponentInstance::onChildInserted(childComponentInstance, index);
    m_stackNode.insertChild(childComponentInstance->getLocalRootArkUINode(), index);
}

void CardViewComponentInstance::onChildRemoved(ComponentInstance::Shared const &childComponentInstance) {
    m_stackNode.removeChild(childComponentInstance->getLocalRootArkUINode());
};

CardViewStackNode &CardViewComponentInstance::getLocalRootArkUINode() { return m_stackNode; }


void CardViewComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
    CppComponentInstance::onPropsChanged(props);
    LOG(INFO) << "[wj] <CardViewComponentInstance::onPropsChanged> Entered with props.";
    if (auto p = std::dynamic_pointer_cast<const facebook::react::RNCardViewProps>(props)) {
        this->backgroundcolor = p->backgroundcolor;
        this->cornerRadius = p->cornerRadius;
        this->cardElevation = p->cardElevation;
        this->cardMaxElevation = p->cardMaxElevation;
        this->useCompatPadding = p->useCompatPadding;
        this->cornerOverlap = p->cornerOverlap;
         LOG(INFO) << "[wj] <CardViewComponentInstance::onPropsChanged> Successfully cast props, backgroundcolor: "
                   << p->backgroundcolor;
        LOG(INFO) << "[wj] <CardViewComponentInstance::onPropsChanged> Successfully cast props, cornerRadius: "
                  << p->cornerRadius;
        LOG(INFO) << "[wj] <CardViewComponentInstance::onPropsChanged> Successfully cast props, cardElevation: "
                  << p->cardElevation;
        LOG(INFO) << "[wj] <CardViewComponentInstance::onPropsChanged> Successfully cast props, cardMaxElevation: "
                  << p->cardMaxElevation;
        LOG(INFO) << "[wj] <CardViewComponentInstance::onPropsChanged> Successfully cast props, useCompatPadding: "
                  << p->useCompatPadding;
        LOG(INFO) << "[wj] <CardViewComponentInstance::onPropsChanged> Successfully cast props, cornerOverlap: "
                  << p->cornerOverlap;
        this->getLocalRootArkUINode().setBackgroundColor(p->backgroundcolor);
        this->getLocalRootArkUINode().setCornerRadius(p->cornerRadius);
        this->getLocalRootArkUINode().setCardElevation(p->cardElevation);
        this->getLocalRootArkUINode().setCardMaxElevation(p->cardMaxElevation);
        this->getLocalRootArkUINode().setUseCompatPadding(p->useCompatPadding);
        this->getLocalRootArkUINode().setCornerOverlap(p->cornerOverlap);
    } else {
        LOG(WARNING) << "[wj] <CardViewComponentInstance::onPropsChanged> Failed to cast props to RNCardViewProps.";
    }
}
void CardViewComponentInstance::getNapiProps(facebook::react::Props::Shared props) {
    auto p = std::dynamic_pointer_cast<const facebook::react::RNCardViewProps>(props);

    this->backgroundcolor = p->backgroundcolor;
    this->cornerRadius = p->cornerRadius;
    this->cardElevation = p->cardElevation;
    this->cardMaxElevation = p->cardMaxElevation;
    this->useCompatPadding = p->useCompatPadding;
    this->cornerOverlap = p->cornerOverlap;
}
} // namespace rnoh