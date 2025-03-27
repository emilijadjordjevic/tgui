#include "cleanstate.h"

bool CleanState::dirty() const {
    return false;
}

unique_ptr<CellState> CleanState::nextState() const {
    return make_unique<DirtyState>();
}