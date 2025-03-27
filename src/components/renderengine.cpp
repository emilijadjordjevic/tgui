#include "renderengine.h"

RenderEngine::RenderEngine() {}

    ~RenderEngine();

    void makeDirty(Position);
    void render();
    void changeStrategy(RenderingStrategy*);