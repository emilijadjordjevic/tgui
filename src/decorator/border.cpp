#include "decorator/border.h"

Border::Border(Element e, int topBorder, int rightBorder, int bottomBorder, int leftBorder) : SpacingDecorator(e, topBorder, rightBorder, bottomBorder, leftBorder) {}

Border::Border(Element e, char c, int topBorder, int rightBorder, int bottomBorder, int leftBorder) : SpacingDecorator(e, topBorder, rightBorder, bottomBorder, leftBorder), _optional(c) {}

Border::Border(Element e, int border) : SpacingDecorator(e, border) {};
// void Border::computeRequirement() {
//     _element->computeRequirement();
//     Size newSize = _element->getRequiredSize();
//     newSize.increase(_leftBorder + _rightBorder, _topBorder + _bottomBorder);
//     setRequiredSize(newSize);
// }

// void Border::ComputeMinSize() {
//     Size minSize = {2,2};
//     this->setRequiredSize(_element->getRequiredSize() + minSize);
// }

int Border::getLayer() const {
    return static_cast<int>(NodeLayer::Border);
}

// void Border::layout(Box& box) {
//     this->_box = box;

//     Box newBox;
//     newBox.setSize({box.getWidth() - _left - _right, box.getHeight() - _top - _bottom});
//     // cout << "originX: " << box.getOrigin().getX() + _leftBorder << " ORiginY: " << box.getOrigin().getY() + _topBorder << endl;
//     newBox.setOrigin({box.getOrigin().getX() + _left, box.getOrigin().getY() + _top});

//     _element->layout(newBox);
// }

void Border::render(Bitmap& map) {
    _element->render(map);

    Point origin = _box.getOrigin();
    int y0 = origin.getY();
    int x0 = origin.getX();

    int y1 = _box.getHeight() - _bottom;
    int x1 = _box.getWidth() - _right;

    //crtamo top boredr
    for (int i = y0; i < _top + y0; i++) {
        for (int j = x0; j < _box.getWidth(); j++) {
            map.setChar(_optional, i, j);
        }
    }

    //crtamo bottom border
    for (int i = y1; i < _bottom + y1; i++) {
        for (int j = x0; j < _box.getWidth(); j++) {
            map.setChar(_optional, i, j);
        }
    }

    //crtamo levi border
    for (int i = y0 + _top; i < y1; i++) {
        for (int j = x0; j < x0 + _left; j++) {
            map.setChar(_optional, i, j);
        }
    }

    //crtamo desni broder
    cout << "y0 + _topBorder: " << y0 + _top << endl;
    cout << "x1: " << x1 <<endl;
    for (int i = y0 + _top; i < y1; i++) {
        for (int j = x1; j < x1 + _right; j++) {
            map.setChar(_optional, i, j);
        }
    }
}