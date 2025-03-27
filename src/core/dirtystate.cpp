#include "dirtystate.h"

bool DirtyState::dirty() const {
    return true;
}

unique_ptr<CellState> DirtyState::nextState() const {
    return make_unique<CleanState>();
}