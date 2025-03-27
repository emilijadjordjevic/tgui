#ifndef DISPLAY_CELL_H
#define DISPLAY_CELL_H

#include <iostream>
#include <memory>
#include "cleanstate.h"
#include "dirtystate.h"
#include "Position.h"
using namespace std;

class DisplayCell {
private:
    char c;
    int backgroundColor;
    int foregroundColor;
    unique_ptr<CellState> cellState;
public:
    DisplayCell(char, int, int);
    ~DisplayCell();

    bool operator==(const DisplayCell&) const;
    // DisplayCell& operator=(const DisplayCell&);
    DisplayCell& setChar(char c);
    DisplayCell& setBackgroundColor(int);
    DisplayCell& setForegroundColor(int);

    int getBackgroundColor() const;
    int getForegroundColor() const;
    char getChar() const;
    bool isDirty() const;
    void changeCellState();
    void draw(Position);
};

#endif