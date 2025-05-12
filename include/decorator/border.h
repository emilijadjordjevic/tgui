#ifndef BORDER_H
#define BORDER_H
#include "node_decorator.h"

class Border : public Decorator {
private:
    char optional;
    int _topBorder;
    int _bottomBorder;
    int _leftBorder;
    int _rightBorder;
public:
    Border(Element e, int topBorder = 0, int rightBorder = 0, int bottomBorder = 0, int leftBorder = 0);
    Border(Element e, char c, int topBorder = 0, int rightBorder = 0, int bottomBorder = 0, int leftBorder = 0);
    void computeRequirement() override;
    void ComputeMinSize() override;
    void layout(Box&) override;
    void render(Bitmap&) override; 
    int getLayer() const override;
};

#endif

