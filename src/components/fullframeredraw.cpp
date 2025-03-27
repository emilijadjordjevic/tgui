#include "fullframeredraw.h"

void FullFrameStrategy::render(DisplayGrid& grid, vector<Position> dirtyCells, TerminalApp& terminal) {
    vector<vector<DisplayCell*>> displayGrid = grid.getGrid();

    for (size_t i = 0; i < grid.getRows(); i++)
    {
        for (size_t j = 0; j < grid.getCols(); j++)
        {
            DisplayCell* current = grid.getCell(j, i);
            if (current->isDirty()) {
                terminal.drawText(i, j, (*current));
                current->changeCellState();
            }
        }
        
    }
    
}