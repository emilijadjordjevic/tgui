#ifndef DISPLAY_GRID_H
#define DISPLAY_GRID_H

#include <iostream>
#include <vector>
#include "DisplayCell.h"
#include "Size.h"
#include "utils/Position.h"
using namespace std;

class DisplayGrid {
private:
    Size size;
    vector<vector<DisplayCell*>> grid;
    inline bool isInBounds(int row, int col) const {
        return row >= 0 && row < getRows() && col >= 0 && col < getCols();
    }
public:
    DisplayGrid(int, int);
    DisplayGrid(Size);
    ~DisplayGrid();

    int getRows() const;
    int getCols() const;
    void setCell(int, int, DisplayCell*);
    void setCell(const Position&, DisplayCell*);
    void setCell(const Position&, char, int, int);
    DisplayCell* getCell(int, int);
    DisplayCell* getCell(const Position&);
    vector<vector<DisplayCell*>> getGrid() const;
};

#endif