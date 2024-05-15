
#ifndef HARMONY_CARDVIEW_SRC_MAIN_CPP_CARDVIEWNAPIBINDER_H
#define HARMONY_CARDVIEW_SRC_MAIN_CPP_CARDVIEWNAPIBINDER_H
#include "RNOHCorePackage/ComponentBinders/ViewComponentNapiBinder.h"
#include "Props.h"
#include "glog/logging.h"
namespace rnoh {

class CardViewNapiBinder : public ViewComponentNapiBinder {
public:
    napi_value createProps(napi_env env, facebook::react::ShadowView const shadowView) override {
        napi_value napiViewProps = ViewComponentNapiBinder::createProps(env, shadowView);
        auto propsObjBuilder = ArkJS(env).getObjectBuilder(napiViewProps);
        LOG(INFO) << "CardViewNapiBinder  RNCardView";
        if (auto props = std::dynamic_pointer_cast<const facebook::react::RNCardViewProps>(shadowView.props)) {
            return ArkJS(env)
                .getObjectBuilder(napiViewProps)
                //                        .addProperty("",props->)
                .addProperty("backgroundColor", props->backgroundColor)
                .addProperty("cornerRadius", props->cornerRadius)
                .addProperty("cardElevation", props->cardElevation)
                .addProperty("cardMaxElevation", props->cardMaxElevation)
                .addProperty("useCompatPadding", props->useCompatPadding)
                .addProperty("cornerOverlap", props->cornerOverlap)
                .build();
            LOG(INFO) << "CardViewNapiBinder RNCardViewProps";
        }
        return napiViewProps;
    };
};
} // namespace rnoh
#endif