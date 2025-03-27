#ifndef FULL_FRAME_REDRAW_STRATEGY_H
#define FULL_FRAME_REDRAW_STRATEGY_H

#include "renderingstrategy.h"
#include <iostream>
using namespace std;

class FullFrameStrategy : public RenderingStrategy {
    void render(DisplayGrid& grid, vector<Position> dirtyCells, TerminalApp& terminal) override;
};

#endif