#ifndef DIRTY_STATE_H
#define DIRTY_STATE_H

#include <iostream>
#include "cellstate.h"
#include "cleanstate.h"
using namespace std;

class DirtyState : public CellState {
public:
    bool dirty() const override;
    unique_ptr<CellState> nextState() const;
};

#endif