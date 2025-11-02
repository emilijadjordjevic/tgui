#ifndef PADDING_H
#define PADDING_H

#include "node_decorator.h"
#include "spacing_decorator.h"

class Padding : public SpacingDecorator {
public:
    Padding(Element, int top, int right, int bottom, int left);
    Padding(Element, int padding);

    void computeRequirement() override;
    // void render(Bitmap&) override; 
    int getLayer() const override;
};

#endif