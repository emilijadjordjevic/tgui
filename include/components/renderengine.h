#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

#include <iostream>
#include <vector>
#include <memory>
#include "DisplayGrid.h"
#include "DisplayCell.h"
#include "renderingstrategy.h"
using namespace std;

class RenderEngine {
private:
    DisplayGrid& grid;
    vector<Position> dirtyCells;
    unique_ptr<RenderEngine> renderEngine;
public:
    RenderEngine(DisplayGrid&);
    ~RenderEngine();

    void makeDirty(Position);
    void render();
    void changeStrategy(RenderingStrategy*);
};

#endif