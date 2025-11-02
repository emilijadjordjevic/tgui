#ifndef BORDER_H
#define BORDER_H
#include "node_decorator.h"
#include "spacing_decorator.h"

class Border : public SpacingDecorator {
private:
    char _optional;
public:
    Border(Element e, int topBorder = 0, int rightBorder = 0, int bottomBorder = 0, int leftBorder = 0);
    Border(Element e, char c, int topBorder = 0, int rightBorder = 0, int bottomBorder = 0, int leftBorder = 0);
    Border(Element e, int border);

    void render(Bitmap&) override; 
    int getLayer() const override;
};

#endif

