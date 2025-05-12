#ifndef BOLD_H
#define BOLD_H

#include "node_decorator.h"
using Element = shared_ptr<Node>;

class Bold : public Decorator {
public:
    Bold(Element e);

    void computeRequirement() override;
    void ComputeMinSize() override;
    void render(Bitmap&) override; 
    int getLayer() const override;
};

#endif