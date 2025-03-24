#include "utils/Size.h"

Size::Size(int width, int height) : width(width), height(height) {}

Size::~Size() {}

Size::Size() : width(0), height(0) {}

int Size::getHeight() const {
    return height;
}

int Size::getWidth() const {
    return width;
}

void Size::setHeight(int height) {
    this->height = height;
}

void Size::setWidth(int width) {
    this->width = width;
}

bool Size::operator==(const Size &other) {
    return other.getHeight() == height && other.getWidth() == width;
}

bool Size::operator>(const Size& other) {
    return this->getHeight() >= other.getHeight() && this->getWidth() >= other.getWidth();
}

bool Size::operator>(int num) {
    return this->getWidth > num;
}

Size Size::operator+(const Size& other) {
    return {this->getWidth() + other.getWidth(), this->getHeight() + other.getHeight()};
}
