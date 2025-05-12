#ifndef MARGIN_H
#define MARGIN_H
#include "node_decorator.h"

class Margin : public Decorator {
private:
    int _top;
    int _left;
    int _bottom;
    int _right;
public:
    Margin(Element, int top, int right, int bottom, int left);
    Margin(Element, int margin);

    void computeRequirement() override;
    void ComputeMinSize() override;
    void layout(Box&) override;
    void render(Bitmap&) override; 
    int getLayer() const override;
};

#endif