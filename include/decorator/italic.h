#ifndef ITALIC_H
#define ITALIC_H

#include "node_decorator.h"

class Italic : public Decorator {
public:
    Italic(Element);

    void computeRequirement() override;
    void ComputeMinSize() override;
    void render(Bitmap&) override; 
    int getLayer() const override;
};

#endif