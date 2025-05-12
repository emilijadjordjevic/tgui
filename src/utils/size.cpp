#include "utils/size.h"

Size::Size() : _width(0), _height(0) {}

Size::Size(int width, int height) : _width(width), _height(height) {}

Size::Size(const Size& size) : _width(size._width), _height(size._height) {}

Size::~Size() {}

void Size::setWidth(int width) {
    _width = width;
}

void Size::setHeight(int height) {
    _height = height;
}

int Size::getWidth() const {
    return _width;
}

int Size::getHeight() const {
    return _height;
}

int Size::area() const {
    return _width * _height;
}

ostream& operator<<(ostream& os, const Size& size) {
    os << "width: " << size._width << " height: " << size._height << endl;

    return os;
}

bool Size::operator==(const int other) const {
    return this->_width == other || this->_height == other;
}

bool Size::operator!=(const int other) const {
    return this->_width != other || this->_height != other;
}

bool Size::operator==(const Size& other) {
    return _width == other.getWidth() && _height == other.getHeight();
}

Size Size::operator+(Size other) {
    Size newSize;
    newSize.setWidth(other._width + this->_width);
    newSize.setHeight(other._width + this->_width);
    return newSize;
}

void Size::increase(int width, int height) {
    _width += width;
    _height += height;
}