#include "decorator/spacing_decorator.h"

SpacingDecorator::SpacingDecorator(Element e, int spacing) : Decorator(e), _left(spacing), _right(spacing), _top(spacing), _bottom(spacing) {}

SpacingDecorator::SpacingDecorator(Element e, int top, int right, int bottom, int left) : Decorator(e), _top(top), _bottom(bottom), _right(right), _left(left) {}

void SpacingDecorator::computeRequirement() {
    _element->computeRequirement();
    Size newSize = _element->getRequiredSize();
    newSize.increase(_left + _right, _top + _bottom);
    setRequiredSize(newSize);
}

void SpacingDecorator::layout(Box& box) {
    this->_box = box;

    Box newBox;
    newBox.setSize({box.getWidth() - _left - _right, box.getHeight() - _top - _bottom});
    newBox.setOrigin({box.getOrigin().getX() + _left, box.getOrigin().getY() + _top});

    _element->layout(newBox);
}

void SpacingDecorator::render(Bitmap& map) {
    _element->render(map);
}
