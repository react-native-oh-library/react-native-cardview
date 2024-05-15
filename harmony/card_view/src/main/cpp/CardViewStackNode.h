#pragma once

#include "RNOH/arkui/ArkUINode.h"
#include "RNOH/arkui/StackNode.h"
#include <react/renderer/graphics/Color.h>

namespace rnoh {

class CardViewStackNode : public ArkUINode {
public:
    CardViewStackNode();

    void insertChild(ArkUINode &child, std::size_t index);
    void removeChild(ArkUINode &child);

    CardViewStackNode &setBackgroundColor(int const &);
    CardViewStackNode &setCornerRadius(const float &);
    CardViewStackNode &setCardElevation(const float &);
    CardViewStackNode &setCardMaxElevation(const float &);
    CardViewStackNode &setUseCompatPadding(bool const &);
    CardViewStackNode &setCornerOverlap(bool const &);
};

} // namespace rnoh