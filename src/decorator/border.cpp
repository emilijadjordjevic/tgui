#include "decorator/border.h"

Border::Border(Element e, int topBorder, int rightBorder, int bottomBorder, int leftBorder) : Decorator(e), _topBorder(topBorder), _rightBorder(rightBorder), _leftBorder(leftBorder), _bottomBorder(bottomBorder) {}

Border::Border(Element e, char c, int topBorder, int rightBorder, int bottomBorder, int leftBorder) : Decorator(e), _topBorder(topBorder), _rightBorder(rightBorder), _leftBorder(leftBorder), _bottomBorder(bottomBorder), optional(c) {}

void Border::computeRequirement() {
    _element->computeRequirement();
    Size newSize = _element->getRequiredSize();
    newSize.increase(_leftBorder + _rightBorder, _topBorder + _bottomBorder);
    setRequiredSize(newSize);
}

void Border::ComputeMinSize() {
    Size minSize = {2,2};
    this->setRequiredSize(_element->getRequiredSize() + minSize);
}

int Border::getLayer() const {
    return static_cast<int>(NodeLayer::Border);
}

void Border::layout(Box& box) {
    this->_box = box;

    Box newBox;
    newBox.setSize({box.getWidth() - _leftBorder - _rightBorder, box.getHeight() - _topBorder - _bottomBorder});
    // cout << "originX: " << box.getOrigin().getX() + _leftBorder << " ORiginY: " << box.getOrigin().getY() + _topBorder << endl;
    newBox.setOrigin({box.getOrigin().getX() + _leftBorder, box.getOrigin().getY() + _topBorder});

    _element->layout(newBox);
}

void Border::render(Bitmap& map) {
    _element->render(map);

    Point origin = _box.getOrigin();
    int y0 = origin.getY();
    int x0 = origin.getX();

    int y1 = _box.getHeight() - _bottomBorder;
    int x1 = _box.getWidth() - _rightBorder;
    cout << "ELEMENT HEIGHT: " << _element->getConstraints().getRequiredHeight();

    //crtamo top boredr
    for (int i = y0; i < _topBorder + y0; i++) {
        for (int j = x0; j < _box.getWidth(); j++) {
            map.setChar(optional, i, j);
        }
    }

    //crtamo bottom border
    for (int i = y1; i < _bottomBorder + y1; i++) {
        for (int j = x0; j < _box.getWidth(); j++) {
            map.setChar(optional, i, j);
        }
    }

    //crtamo levi border
    for (int i = y0 + _topBorder; i < y1; i++) {
        for (int j = x0; j < x0 + _leftBorder; j++) {
            map.setChar(optional, i, j);
        }
    }

    //crtamo desni broder
    cout << "y0 + _topBorder: " << y0 + _topBorder << endl;
    cout << "x1: " << x1 <<endl;
    for (int i = y0 + _topBorder; i < y1; i++) {
        for (int j = x1; j < x1 + _rightBorder; j++) {
            map.setChar(optional, i, j);
        }
    }
}