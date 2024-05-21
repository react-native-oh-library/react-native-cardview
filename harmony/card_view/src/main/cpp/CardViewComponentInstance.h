
#ifndef HARMONY_CARDVIEWCOMPONENTINSTANCE_H
#define HARMONY_CARDVIEWCOMPONENTINSTANCE_H
#include "RNOH/CppComponentInstance.h"
#include "CardViewStackNode.h"
#include "ShadowNodes.h"
#include "Props.h"

namespace rnoh {
class CardViewComponentInstance : public CppComponentInstance<facebook::react::RNCardViewShadowNode> {
private:
    CardViewStackNode m_stackNode;

    int backgroundcolor{0};
    float cornerRadius{0.0};
    float cardElevation{0.0};
    float cardMaxElevation{0.0};
    bool useCompatPadding{false};
    bool cornerOverlap{false};

public:
    CardViewComponentInstance(Context context);

    void onChildInserted(ComponentInstance::Shared const &childComponentInstance, std::size_t index) override;

    void onChildRemoved(ComponentInstance::Shared const &childComponentInstance) override;

    CardViewStackNode &getLocalRootArkUINode() override;

    void onPropsChanged(SharedConcreteProps const &props) override;

    void getNapiProps(facebook::react::Props::Shared const props);
};
} // namespace rnoh
#endif