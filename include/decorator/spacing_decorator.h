#ifndef SPACING_DECORATOR_H
#define SPACING_DECORATOR_H

#include "node_decorator.h"

class SpacingDecorator : public Decorator {
protected:
    int _left;
    int _right;
    int _top;
    int _bottom;
public:
    SpacingDecorator(Element, int spacing);
    SpacingDecorator(Element, int top, int right, int bottom, int left);

    virtual void computeRequirement() override;
    virtual void layout(Box&) override;
    virtual void render(Bitmap&) override;
    virtual int getLayer() const override = 0;
};

#endif