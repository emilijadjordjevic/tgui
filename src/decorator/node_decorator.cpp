#include "decorator/node_decorator.h"

Decorator::Decorator(Element e) : Node() {
    _element = e;
    setFlexGrow(1,1);
}

void Decorator::computeRequirement() {
    _element->computeRequirement();
    setRequiredSize(_element->getRequiredSize());
}

void Decorator::layout(Box& box) {
    this->_box = box;
    _element->layout(box);
}