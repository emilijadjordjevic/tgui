#ifndef PADDING_H
#define PADDING_H

#include "node_decorator.h"

class Padding : public Decorator {
private:
    int _top;
    int _bottom;
    int _left;
    int _right;
public:
    Padding(Element, int top, int right, int bottom, int left);
    Padding(Element, int padding);

    void computeRequirement() override;
    void ComputeMinSize() override;
    void layout(Box&) override;
    void render(Bitmap&) override; 
    int getLayer() const override;
};

#endif