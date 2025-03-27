#include "incrementalstrategy.h"

void IncrementalRenderingStrategy::render(DisplayGrid& grid, vector<Position> dirtyCells, TerminalApp& terminal) {
    for (auto p : dirtyCells) {
        terminal.drawText(p, (*grid.getCell(p)));
    }

    dirtyCells.clear();
}