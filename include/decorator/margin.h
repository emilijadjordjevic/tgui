#ifndef MARGIN_H
#define MARGIN_H
#include "node_decorator.h"
#include "spacing_decorator.h"

class Margin : public SpacingDecorator {
public:
    Margin(Element, int top, int right, int bottom, int left);
    Margin(Element, int margin);

    // void layout(Box&) override;
    int getLayer() const override;
};

#endif