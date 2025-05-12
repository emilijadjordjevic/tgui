#include "decorator/padding.h"

Padding::Padding(Element e, int top, int right, int bottom, int left) : Decorator(e), _left(left), _right(right), _top(top), _bottom(bottom) {}

Padding::Padding(Element e, int padding) : Decorator(e), _left(padding), _right(padding), _top(padding), _bottom(padding) {}

void Padding::computeRequirement() {
    _element->computeRequirement();

    Size elementSize = _element->getRequiredSize();
    // elementSize.increase(_left + _right, _top + _bottom);

    setRequiredSize(elementSize);
}

void Padding::ComputeMinSize() {

}

void Padding::layout(Box& box) {
    _box = box;

    Box newBox;
    Size newSize = _element->getRequiredSize();
    int width = max(0, newSize.getWidth() - (_left + _right));
    int height = max(0, newSize.getHeight() - (_top + _bottom));
    newSize.setWidth(width);
    newSize.setHeight(height);

    newBox.setSize(newSize);
    newBox.setOrigin({box.getOrigin().getX() + _left, box.getOrigin().getY() + _top});

    _element->layout(newBox);
}


void Padding::render(Bitmap& map) {
    _element->render(map);
}

int Padding::getLayer() const {
    return static_cast<int>(NodeLayer::BoxStyle);
}