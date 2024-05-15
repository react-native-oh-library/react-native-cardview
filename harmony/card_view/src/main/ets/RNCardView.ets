// import { Descriptor, ComponentBuilderContext, ViewBaseProps, Tag } from 'rnoh';
// import { RNComponentFactory, RNOHContext, RNViewBase } from 'rnoh'


import {
  Descriptor,
  ComponentBuilderContext,
  RNComponentFactory,
  RNViewBase,
  RNOHContext,
  ViewBaseProps,
  ColorSegments,
  convertColorSegmentsToString,
  Tag,
} from '@rnoh/react-native-openharmony'

export const CENTERED_TEXT_TYPE: string = "RNCardView"

// export type CardViewProps = ViewBaseProps & {
//   text: string
// }

export type CardViewDescriptor = Descriptor<"RNCardView", ViewBaseProps>


@Component
export struct RTNCardView {
  ctx!: RNOHContext
  tag: number = 0
  @BuilderParam buildCustomComponent: (componentBuilderContext: ComponentBuilderContext) => void
  @State descriptor: CardViewDescriptor = {} as CardViewDescriptor
  private unregisterDescriptorChangesListener?: () => void = undefined

  aboutToAppear() {
    this.descriptor = this.ctx.descriptorRegistry.getDescriptor<CardViewDescriptor>(this.tag)
    this.unregisterDescriptorChangesListener = this.ctx.descriptorRegistry.subscribeToDescriptorChanges(this.tag,
      (newDescriptor) => {
        this.descriptor = (newDescriptor as CardViewDescriptor)
      }
    )
  }

  aboutToDisappear() {
    this.unregisterDescriptorChangesListener?.()
  }

  build() {
    RNViewBase({ ctx: this.ctx, tag: this.tag }) {
      // Text(this.descriptor.props.transform)
      // .fontColor("red")
      // .fontSize(12)
      // .textAlign(TextAlign.Center)
      // .width("100%")
      // .height("100%")
    }
  }
}
