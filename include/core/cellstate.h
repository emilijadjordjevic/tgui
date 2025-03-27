#ifndef CELL_STATE_H
#define CELL_STATE_H

#include <iostream>
#include <memory>
using namespace std;

class CellState {
public:
    virtual bool dirty() const = 0;
    virtual unique_ptr<CellState> nextState() const = 0;
};

#endif