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

#ifndef HARMONY_CARDVIEW_SRC_MAIN_CPP_CARDVIEWPACKAGE_H
#define HARMONY_CARDVIEW_SRC_MAIN_CPP_CARDVIEWPACKAGE_H
#include "RNOH/Package.h"
#include "CardViewComponentInstance.h"
#include "CardViewDescriptor.h"
#include "CardViewJSIBinder.h"
#include "CardViewNapiBinder.h"

namespace rnoh {

class CardViewPackageComponentInstanceFactoryDelegate : public ComponentInstanceFactoryDelegate {
public:
    using ComponentInstanceFactoryDelegate::ComponentInstanceFactoryDelegate;
    ComponentInstance::Shared create(ComponentInstance::Context ctx) override {
        if (ctx.componentName == "RNCardView") {
            return std::make_shared<CardViewComponentInstance>(std::move(ctx));
        }
        return nullptr;
    }
};

class CardViewPackage : public Package {
public:
    CardViewPackage(Package::Context ctx) : Package(ctx) { }
    ComponentInstanceFactoryDelegate::Shared createComponentInstanceFactoryDelegate() override {
        if (std::make_shared<CardViewPackageComponentInstanceFactoryDelegate>() != nullptr) {
            return std::make_shared<CardViewPackageComponentInstanceFactoryDelegate>();
        }
    }

    std::vector<facebook::react::ComponentDescriptorProvider> createComponentDescriptorProviders() override {
        return {facebook::react::concreteComponentDescriptorProvider<facebook::react::RNCardViewComponentDescriptor>()};
    }

    ComponentJSIBinderByString createComponentJSIBinderByName() override {
        return {{"RNCardView", std::make_shared<CardViewJSIBinder>()}};
    }

    ComponentNapiBinderByString createComponentNapiBinderByName() override {
        return {{"RNCardView", std::make_shared<CardViewNapiBinder>()}};
    }
};
} // namespace rnoh
#endif