#include "elements/container.h"

IContainer::IContainer(Size size) : Node(size) {}

IContainer::IContainer(Elements elements) {
    _elements = elements;
}

IContainer::IContainer(Size size, Elements elements) : Node(size) {
    _elements = elements;
}

void IContainer::render(Bitmap& screen) {
    for (Element& e : _elements) {
        e->render(screen);
    }
}

int IContainer::getLayer() const {
    return static_cast<int>(NodeLayer::Content);
}

void IContainer::add(const Element& e) {
    _elements.push_back(e);
}

int IContainer::getLayer() const {
    return static_cast<int>(NodeLayer::Content);
}

ostream& operator<<(ostream& os, const IContainer& container) {
    for (auto& child : container._elements) {
        os << *child;
    }

    return os;
}