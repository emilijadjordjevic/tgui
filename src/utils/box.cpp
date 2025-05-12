#include "utils/box.h"

Box::Box() : _origin(), _size() {}

// Box::Box(Point&& other) : _origin(move(other)), _size() {}

Box::Box(Point& other) : _origin(other), _size() {}

// Box::Box(Size&& other) : _size(move(other)), _origin() {}

Box::Box(Size& other) : _size(other), _origin() {}

// Box::Box(Point&& point, Size&& size) : _origin(move(point)), _size(move(size)) {}

Box::Box(Point& point, Size& size) : _origin(point), _size(size) {}

bool Box::isRightOf(const Box& other) const {
    return _origin.isRightOf(other._origin);
}

bool Box::isLeftOf(const Box& other) const {
    return _origin.isLeftOf(other._origin);
}

bool Box::isAbove(const Box& other) const {
    return _origin.isAbove(other._origin);
}

bool Box::isBelow(const Box& other) const {
    return _origin.isBelow(other._origin);
}

bool Box::contains(const Box& other) const {
    return !(isRightOf(other) || isLeftOf(other) || isAbove(other) || isBelow(other));
}

void Box::setSize(Size s) {
    this->_size = s;
}

int Box::getHeight() const {
    return _size.getHeight();
}

int Box::getWidth() const {
    return _size.getWidth();
}


Size Box::getRequiredSize() const {
    return _size;
}

Point Box::getOrigin() const {
    return _origin;
}

Box& Box::operator=(Box& other) {
    if (this != &other) {
        this->_size = other._size;
        this->_origin = other._origin;
    }

    return *this;
}

void Box::setOrigin(Point p) {
    this->_origin = p;
}

Box::Box(const Point& point, const Size& size) : _origin(point), _size(size) {}

