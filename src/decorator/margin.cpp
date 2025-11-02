#include "decorator/margin.h"

Margin::Margin(Element e, int top, int right, int bottom, int left) : SpacingDecorator(e, top, right, bottom, left) {}

Margin::Margin(Element e, int margin) : SpacingDecorator(e, margin) {}

// void Margin::layout(Box& box) {
//     _box = box;

//     Box newBox;
//     Size newSize = _element->getRequiredSize();
//     newSize.increase(-(_left + _right), -(_top + _bottom));
//     newBox.setSize(newSize);
//     newBox.setOrigin({box.getOrigin().getX() + _left, box.getOrigin().getY() + _top});

//     _element->layout(newBox);
// }

// void Margin::render(Bitmap& map) {
//     _element->render(map);
// } 

int Margin::getLayer() const {
    return static_cast<int>(NodeLayer::Margin);
}
