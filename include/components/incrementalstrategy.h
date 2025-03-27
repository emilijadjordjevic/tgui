#ifndef INCREMENTAL_RENDERING_STRATEGY_H
#define INCREMENTAL_RENDERING_STRATEGY_H

#include "renderingstrategy.h"
#include <iostream>
using namespace std;

class IncrementalRenderingStrategy : public RenderingStrategy {
    void render(DisplayGrid& grid, vector<Position> dirtyCells, TerminalApp& terminal) override;
};

#endif