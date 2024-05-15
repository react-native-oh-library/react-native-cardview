> 模板版本：v0.1.3

<p align="center">
  <h1 align="center"> <code>@react-native-cardview</code> </h1>
</p>
<p align="center">
    <a href="https://github.com/Kishanjvaghela/react-native-cardview/tree/master">
        <img src="https://img.shields.io/badge/platforms-android%20|%20ios%20|%20windows%20|%20macos%20|%20web%20|%20harmony%20-lightgrey.svg" alt="Supported platforms" />
    </a>
    <a href="https://github.com/Kishanjvaghela/react-native-cardview/blob/master/LICENSE">
        <img src="https://img.shields.io/npm/l/@react-native-cardview/async-storage.svg" alt="License" />
    </a>
</p>

> [!tip] [Github 地址](https://github.com/react-native-oh-library/async-storage)

## 安装与使用

请到三方库的 Releases 发布地址查看配套的版本信息：[@react-native-oh-tpl/react-native-cardview> Releases](https://github.com/react-native-oh-tpl/react-native-cardview/releases)，并下载适用版本的 tgz 包。

进入到工程目录并输入以下命令：

> [!TIP] # 处替换为 tgz 包的路径

<!-- tabs:start -->

#### **npm**

```bash
npm install @react-native-oh-tpl/react-native-cardview@file:#
```

#### **yarn**

```bash
yarn add @react-native-oh-tpl/react-native-cardview@file:#
```

<!-- tabs:end -->

下面的代码展示了这个库的基本使用场景：

> [!WARNING] 使用时 import 的库名不变。

```js
import CardView from '@react-native-oh-tpl/react-native-cardview'
<CardView
          cardElevation={2}
          cardMaxElevation={2}
          cornerRadius={5}>
          <Text>
              Elevation 0
          </Text>
</CardView>
```

## Link

目前鸿蒙暂不支持 AutoLink，所以 Link 步骤需要手动配置。

首先需要使用 DevEco Studio 打开项目里的鸿蒙工程 `harmony`

### 引入原生端代码

目前有两种方法：

1. 通过 har 包引入（在 IDE 完善相关功能后该方法会被遗弃，目前首选此方法）；
2. 直接链接源码。

方法一：通过 har 包引入

> [!TIP] har 包位于三方库安装路径的 `harmony` 文件夹下。

打开 `entry/oh-package.json5`，添加以下依赖

```json
"dependencies": {
    "rnoh": "file:../rnoh",
    "rnoh-async-storage": "file:../../node_modules/@react-native-oh-tpl/react-native-cardview/harmony/card_view.har"
  }
```

点击右上角的 `sync` 按钮

或者在终端执行：

```bash
cd entry
ohpm install
```

方法二：直接链接源码

> [!TIP] 源码位于三方库安装路径的 `harmony` 文件夹下。

打开 `entry/oh-package.json5`，添加以下依赖

```json
"dependencies": {
    "rnoh": "file:../rnoh",
    "rnoh-async-storage": "file:../../node_modules/@react-native-oh-tpl/react-native-cardview/harmony/card_view"
  }
```

打开终端，执行：

```bash
cd entry
ohpm install --no-link
```

### 配置 CMakeLists 和引入 AsynStoragePackge

打开 `entry/src/main/cpp/CMakeLists.txt`，添加：

```diff
project(rnapp)
cmake_minimum_required(VERSION 3.4.1)
set(RNOH_APP_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(OH_MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../oh_modules")
set(RNOH_CPP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../react-native-harmony/harmony/cpp")

add_subdirectory("${RNOH_CPP_DIR}" ./rn)

# RNOH_BEGIN: manual_package_linking_1
add_subdirectory("../../../../sample_package/src/main/cpp" ./sample-package)
+ add_subdirectory("${OH_MODULES}/@react-native-oh-tpl/react-native-cardview/src/main/cpp" ./card-view)
# RNOH_END: add_package_subdirectories

add_library(rnoh_app SHARED
    "./PackageProvider.cpp"
    "${RNOH_CPP_DIR}/RNOHAppNapiBridge.cpp"
)

target_link_libraries(rnoh_app PUBLIC rnoh)

# RNOH_BEGIN: link_packages
target_link_libraries(rnoh_app PUBLIC rnoh_sample_package)
+ target_link_libraries(rnoh_app PUBLIC rnoh_card_view)
# RNOH_END: link_packages
```

打开 `entry/src/main/cpp/PackageProvider.cpp`，添加：

```diff
#include "RNOH/PackageProvider.h"
#include "SamplePackage.h"
+ #include "CardViewPackage.h"

using namespace rnoh;

std::vector<std::shared_ptr<Package>> PackageProvider::getPackages(Package::Context ctx) {
    return {
      std::make_shared<SamplePackage>(ctx),
+     std::make_shared<CardViewPackage>(ctx)
    };
}
```

### 运行

点击右上角的 `sync` 按钮

或者在终端执行：

```bash
cd entry
ohpm install
```

然后编译、运行即可。

## 兼容性

要使用此库，需要使用正确的 React-Native 和 RNOH 版本。另外，还需要使用配套的 DevEco Studio 和 手机 ROM。

请到三方库相应的 Releases 发布地址查看 Release 配套的版本信息：[@react-native-oh-tpl/react-native-cardview Releases](https://github.com/react-native-oh-tpl/react-native-cardview/releases)

## API

> [!tip] "Platform"列表示该属性在原三方库上支持的平台。

> [!tip] "HarmonyOS Support"列为 yes 表示 HarmonyOS 平台支持该属性；no 则表示不支持；partially 表示部分支持。使用方法跨平台一致，效果对标 iOS 或 Android 的效果。

| Name                   | Description                                                                                                | Type     | Required | Platform | HarmonyOS Support |
| ---------------------- | ---------------------------------------------------------------------------------------------------------- | -------- | -------- | -------- | ----------------- |
| `cornerRadius`         | An attribute to set the elevation of the card.                                                             | function | No       | All      | yes               |
| `cardElevation`        | An attribute to support shadow on pre-lollipop device in android.                                          | function | No       | All      | yes               |
| `cardMaxElevation`     | An attribute to set the radius of the card.                                                                | function | No       | All      | yes               |
| `useCompatPadding`     | CardView adds additional padding to draw shadows on platforms before Lollipop.                             | function | No       | All      | yes               |
| `cornerOverlap`        | On pre-Lollipop platforms, CardView does not clip the bounds of the Card for the rounded corners.          | function | No       | All      | yes               |
| `backgroundColor`      | The background color of the card.                                                                          | function | No       | All      | yes               |

## 遗留问题

## 其他

## 开源协议

