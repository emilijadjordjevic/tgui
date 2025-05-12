#ifndef STRIKETHROUGH_H
#define STRIKETHROUGH_H

#include "node_decorator.h"

class Striketrough : public Decorator {
public:
    Striketrough(Element e);
    Striketrough(Element e);
    void computeRequirement() override;
    void ComputeMinSize() override;
    void render(Bitmap&) override; 
    int getLayer() const override;
};

#endif