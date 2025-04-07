#include "utils/point.h"

Point::Point() : _x(0), _y(0) {}

Point::Point(int x, int y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY()) {}

double Point::distanceTo(const Point& other) {
    return hypot(_x - other._x, _y - other._y);
}

void Point::move(int dx, int dy) {
    _x += dx;
    _y += dy;
}

int Point::getX() const {
    return _x;
}

int Point::getY() const {
    return _y;
}

void Point::setX(int x) {
    _x = x;
}

void Point::setY(int y) {
    _y = y;
}

bool Point::operator==(const Point& other) {
    return _x == other._x && _y == other._y;
}

bool Point::operator!=(const Point& other) {
    return !(*this == other);
}

Point& Point::operator=(Point&& other) noexcept {
    if (this != &other) {
        _x = std::move(other._x);
        _y = std::move(other._y);
    }

    return *this;
}

ostream& operator<<(ostream& os, const Point& p) {
    os << "x: " << p.getX() << " y: " << p.getY() << endl;

    return os;
}

bool Point::isAbove(const Point& other) const {
    return _y > other._y;
}

bool Point::isBelow(const Point& other) const {
    return _y < other._y;
}

bool Point::isRightOf(const Point& other) const {
    return _x < other._x;
}

bool Point::isLeftOf(const Point& other) const {
    return _x > other._x;
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        this->_x = other._x;
        this->_y = other._y;
    }

    return *this;
}