import React from 'react';
import type { NativeProps as CardViewProps } from './CardViewNativeComponent';
import CardViewView from './CardViewNativeComponent';

export declare class CardView extends React.Component<CardViewProps> {
    cardView: React.ElementRef<typeof CardViewView> | null;
    render(): JSX.Element;
}