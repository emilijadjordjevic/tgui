#ifndef RENDERING_STRATEGY_H
#define RENDERING_STRATEGY_H

#include "Position.h"
#include "terminalApp.h"
#include "DisplayGrid.h"
#include <iostream>
#include <vector>
using namespace std;

class RenderingStrategy {
public:
    virtual void render(DisplayGrid& grid, vector<Position> dirtyCells, TerminalApp& terminal) = 0;
};

#endif