import { PropTypes } from 'prop-types';
import React, { Component } from 'react';
import {
  requireNativeComponent,
  View,
  PixelRatio,
  Platform
} from 'react-native';
var iface = {
  name: 'CardView',
  propTypes: {
    cornerRadius: PropTypes.number,
    cardElevation: PropTypes.number,
    cardMaxElevation: PropTypes.number,
    ...View.propTypes // include the default view properties
  }
};

const RNCardView = requireNativeComponent('RNCardView', iface);
class CardView extends Component {
  render() {
   
      return <RNCardView {...this.props}>{this.props.children}</RNCardView>;
    
  }
}

export default CardView;
