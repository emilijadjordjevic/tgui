#ifndef NODE_DECORATOR_H
#define NODE_DECORATOR_H

#include "elements/node.h"
using Element = shared_ptr<Node>;

class Decorator : public Node {
protected:
    Element _element;
public:
    Decorator(Element);

    virtual void computeRequirement() override;
    virtual void ComputeMinSize() override;
    virtual void layout(Box&) override;
    virtual void render(Bitmap&) override = 0;   
    virtual int getLayer() const override = 0;
};

#endif