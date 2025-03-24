#include "core/DisplayGrid.h"

DisplayGrid::DisplayGrid(int rows, int cols) : size(cols, rows) {
    grid.resize(rows, vector<DisplayCell*>(cols, nullptr));
}

DisplayGrid::DisplayGrid(Size size) : size(size) {
    grid.resize(size.getHeight(), vector<DisplayCell*>(size.getWidth(), nullptr));
}

DisplayGrid::~DisplayGrid() = default;

int DisplayGrid::getRows() const {
    return grid.size();
}

DisplayCell* DisplayGrid::getCell(int row, int col) {
    if(!isInBounds(row, col)) {
        throw out_of_range("scope of vector out of range");
    }

    return grid.at(row).at(col);
}

void DisplayGrid::setCell(int row, int col, DisplayCell* cell) {
    if (isInBounds(row, col)) {
        grid[row][col] = cell;
    }
}

int DisplayGrid::getCols() const {
    return grid.empty() ? 0 : grid[0].size();
}

void DisplayGrid::setCell(const Position& pos, DisplayCell* cell) {
    this->setCell(pos.getY(), pos.getX(), cell);
}

void DisplayGrid::setCell(const Position& pos, char ch, int bgColor, int fgColor) {
    this->getCell(pos)->setChar(ch).setBackgroundColor(bgColor).setForegroundColor(fgColor);
}

DisplayCell* DisplayGrid::getCell(const Position& pos) {
    return this->getCell(pos.getY(), pos.getX());
}







