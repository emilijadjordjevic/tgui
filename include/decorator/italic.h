#ifndef ITALIC_H
#define ITALIC_H

#include "node_decorator.h"

class Italic : public Decorator {
public:
    Italic(Element);

    void render(Bitmap&) override; 
    int getLayer() const override;
};

#endif