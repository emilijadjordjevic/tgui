#include "elements/container.h"

IContainer::IContainer(Size size) : Node(size) {}

void IContainer::render(Screen& screen) {
    for (Element& e : _elements) {
        e->render(screen);
    }
}

void IContainer::add(const Element& e) {
    _elements.push_back(e);
}