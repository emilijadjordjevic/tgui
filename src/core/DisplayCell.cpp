#include "core/DisplayCell.h"
#include "terminalDrawEngine.h"

DisplayCell::DisplayCell(char c, int backgroundColor, int foregorundColor) : c(c), backgroundColor(backgroundColor), foregroundColor(foregorundColor), cellState(make_unique<CleanState>()) {}

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

bool DisplayCell::isDirty() const {
    return cellState->dirty();
}

void DisplayCell::changeCellState() {
    cellState = cellState->nextState();
}

void DisplayCell::draw(Position p) {
}

int DisplayCell::getBackgroundColor() const {
    return backgroundColor;
}

int DisplayCell::getForegroundColor() const {
    return foregroundColor;
}

char DisplayCell::getChar() const {
    return c;
}

// DisplayCell& DisplayCell::operator=(const DisplayCell& other) {
//     if (other == (*this)) {

//     } 
// }