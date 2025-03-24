#include "core/DisplayCell.h"

DisplayCell::DisplayCell(char c, int backgroundColor, int foregorundColor) : c(c), backgroundColor(backgroundColor), foregroundColor(foregorundColor), dirty(false) {}

DisplayCell::~DisplayCell() {}

bool DisplayCell::operator==(const DisplayCell& other) const {
    return c == other.c && this->backgroundColor == other.backgroundColor && this->foregroundColor == other.foregroundColor;
}

DisplayCell& DisplayCell::setChar(char c) {
    this->c = c;
    return *this;
}

DisplayCell& DisplayCell::setBackgroundColor(int bgCol) {
    this->backgroundColor = bgCol;
    return *this;
}

DisplayCell& DisplayCell::setForegroundColor(int fgCol) {
    this->foregroundColor = fgCol;
    return *this;
}