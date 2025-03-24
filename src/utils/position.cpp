#include "utils/Position.h"

Position::Position() : x(0), y(0) {}

Position::Position(int x, int y) : x(x), y(y) {}

Position::~Position() {}

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

void Position::setX(int newX) {
    x = newX;
}

void Position::setY(int newY) {
    y = newY;
}

void Position::print() const {
    cout << "X: " << x << " Y: " << y << " ";
}

bool Position::operator==(const Position &other) {
    return (x == other.x) && (y == other.y);
}

