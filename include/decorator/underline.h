#ifndef UNDERLINE_H
#define UNDERLINE_H

#include "node_decorator.h"

class Underline : public Decorator {
public:
    Underline(Element e);
    Underline(Element e);
    void computeRequirement() override;
    void ComputeMinSize() override;
    void render(Bitmap&) override; 
    int getLayer() const override;
};



#endif