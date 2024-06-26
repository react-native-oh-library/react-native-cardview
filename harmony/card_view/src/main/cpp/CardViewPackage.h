#ifndef HARMONY_CARDVIEW_SRC_MAIN_CPP_CARDVIEWPACKAGE_H
#define HARMONY_CARDVIEW_SRC_MAIN_CPP_CARDVIEWPACKAGE_H
#include "RNOH/Package.h"
#include "CardViewComponentInstance.h"
#include "CardViewDescriptor.h"
#include "CardViewJSIBinder.h"
#include "CardViewNapiBinder.h"
#include "glog/logging.h"

namespace rnoh {

class CardViewPackageComponentInstanceFactoryDelegate : public ComponentInstanceFactoryDelegate {
public:
    using ComponentInstanceFactoryDelegate::ComponentInstanceFactoryDelegate;
    ComponentInstance::Shared create(ComponentInstance::Context ctx) override {
        DLOG(INFO) << "CardViewPackage CardViewPackageComponentInstanceFactoryDelegate ComponentInstance";
        if (ctx.componentName == "RNCardView") {
            DLOG(INFO) << "CardViewPackage CardViewPackageComponentInstanceFactoryDelegate componentName";
            return std::make_shared<CardViewComponentInstance>(std::move(ctx));
        }
        return nullptr;
    }
};

class CardViewPackage : public Package {
public:
    CardViewPackage(Package::Context ctx) : Package(ctx) { DLOG(INFO) << "CardViewPackage CardViewPackage"; }
    ComponentInstanceFactoryDelegate::Shared createComponentInstanceFactoryDelegate() override {
        DLOG(INFO) << "CardViewPackage ComponentInstanceFactoryDelegate";
        if (std::make_shared<CardViewPackageComponentInstanceFactoryDelegate>() != nullptr) {
            DLOG(INFO) << "CardViewPackage CardViewPackageComponentInstanceFactoryDelegate";
            return std::make_shared<CardViewPackageComponentInstanceFactoryDelegate>();
        }
    }

    std::vector<facebook::react::ComponentDescriptorProvider> createComponentDescriptorProviders() override {
        DLOG(INFO) << "CardViewPackage ComponentDescriptorProvider";
        return {facebook::react::concreteComponentDescriptorProvider<facebook::react::RNCardViewComponentDescriptor>()};
    }

    ComponentJSIBinderByString createComponentJSIBinderByName() override {
        DLOG(INFO) << "CardViewPackage ComponentJSIBinderByString";
        return {{"RNCardView", std::make_shared<CardViewJSIBinder>()}};
    }

    ComponentNapiBinderByString createComponentNapiBinderByName() override {
        DLOG(INFO) << "CardViewPackage ComponentNapiBinderByString";
        return {{"RNCardView", std::make_shared<CardViewNapiBinder>()}};
    }
};
} // namespace rnoh
#endif