#include "decorator/margin.h"

Margin::Margin(Element e, int top, int right, int bottom, int left) : Decorator(e), _top(top), _left(left), _right(right), _bottom(bottom) {}

Margin::Margin(Element e, int margin) : Decorator(e), _top(margin), _left(margin), _right(margin), _bottom(margin) {}

void Margin::computeRequirement() {
    _element->computeRequirement();

    Size newSize = _element->getRequiredSize();
    newSize.increase(_left + _right, _top + _bottom);

    setRequiredSize(newSize);
}

void Margin::ComputeMinSize() {

}

void Margin::layout(Box& box) {
    _box = box;

    Box newBox;
    Size newSize = _element->getRequiredSize();
    newSize.increase(-(_left + _right), -(_top + _bottom));
    newBox.setSize(newSize);
    newBox.setOrigin({box.getOrigin().getX() + _left, box.getOrigin().getY() + _top});

    _element->layout(newBox);
}

void Margin::render(Bitmap& map) {
    _element->render(map);
} 

int Margin::getLayer() const {
    return static_cast<int>(NodeLayer::Margin);
}
