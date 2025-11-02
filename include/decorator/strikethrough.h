#ifndef STRIKETHROUGH_H
#define STRIKETHROUGH_H

#include "node_decorator.h"

class Striketrough : public Decorator {
public:
    Striketrough(Element e);

    void render(Bitmap&) override; 
    int getLayer() const override;
};

#endif