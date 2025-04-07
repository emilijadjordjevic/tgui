#include "utils/constraints.h"

Constraints::Constraints() : minSize(), maxSize(), prefSize() {}

Constraints::~Constraints() {}

void Constraints::setMinimumSize(Size size) {
    minSize = size;
}

void Constraints::setMaximumSize(Size size) {
    maxSize = size;
}

void Constraints::setPrefSize(Size size) {
    prefSize = size;
}

void Constraints::setMinWidth(int size) {
    minSize.setWidth(size);
}

void Constraints::setMaxWidth(int size) {
    maxSize.setWidth(size);
}

void Constraints::setPrefWidth(int size) {
    prefSize.setWidth(size);
}

void Constraints::setMinHeight(int size) {
    minSize.setHeight(size);
}

void Constraints::setMaxHeight(int size) {
    maxSize.setHeight(size);
}

void Constraints::setPrefHeight(int size) {
    prefSize.setHeight(size);
}

int Constraints::getMinWidth() const {
    return minSize.getWidth();
}

int Constraints::getMinHeight() const {
    return minSize.getHeight();
}

int Constraints::getPrefHeight() const {
    return prefSize.getHeight();
}

int Constraints::getPrefWidth() const {
    return prefSize.getWidth();
}

int Constraints::getMaxWidth() const {
    return maxSize.getWidth();
}

int Constraints::getMaxHeight() const {
    return maxSize.getHeight();
}

Size Constraints::getMinSize() const {
    return minSize;
}

Size Constraints::getPrefSize() const {
    return prefSize;
}

Size Constraints::getMaxSize() const {
    return maxSize;
}

int Constraints::flexGrowY() const {
    return flex_grow_y;
}

int Constraints::flexGrowX() const {
    return flex_grow_x;
}

int Constraints::flexShrinkX() const {
    return flex_shrink_x;
}

int Constraints::flexSHrinkY() const {
    return flex_shrink_y;
}

void Constraints::flexGrowY(int num) {
    flex_grow_y = num;
}

void Constraints::flexGrowX(int num) {
    flex_grow_x = num;
}

void Constraints::flexShrinkX(int num) {
    flex_shrink_x = num;
}

void Constraints::flexSHrinkY(int num) {
    flex_shrink_y = num;
}

