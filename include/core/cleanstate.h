#ifndef CLEAN_STATE_H
#define CLEAN_STATE_H

#include <iostream>
#include "cellstate.h"
#include "dirtystate.h"
using namespace std;

class CleanState : public CellState {
public:
    bool dirty() const override;
    unique_ptr<CellState> nextState() const;
};

#endif