import type * as React from 'react';
import codegenNativeComponent from 'react-native/Libraries/Utilities/codegenNativeComponent';
import type { HostComponent, ViewProps } from 'react-native';
import type {
  Float,
  Int32,
  WithDefault,
} from 'react-native/Libraries/Types/CodegenTypes';

export interface NativeProps extends ViewProps {
  backgroundColor1?:Int32;   //卡片的背景色
  cornerRadius?:Float;  //卡片的圆角大小
  cardElevation?: Float;  //阴影的大小
  cardMaxElevation?: Float;  //阴影的最大高度
  useCompatPadding?: WithDefault<boolean, false>; //是否设置内边距
  cornerOverlap?: WithDefault<boolean, true>;   //使内容不会与圆角重叠
}


export default codegenNativeComponent<NativeProps>(
  'RNCardView'
) as HostComponent<NativeProps>;