import React from 'react';
import { Platform, Keyboard } from 'react-native';
import { I18nManager } from 'react-native';

import type * as ReactNative from 'react-native';

import type { NativeProps as CardViewProps } from '@react-native-oh-tpl/react-native-cardview/src/CardViewNativeComponent';
import CardViewView from '@react-native-oh-tpl/react-native-cardview/src/CardViewNativeComponent';


export class CardView extends React.Component<CardViewProps> {
  private isScrolling = false;
  cardView: React.ElementRef<typeof CardViewView> | null = null;
  
  render() {
    return (
      <CardViewView
        {...this.props}
      />
    );
  }
}