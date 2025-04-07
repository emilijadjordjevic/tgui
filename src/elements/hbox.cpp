#include "elements/hbox.h"
#include "utils/box_layout_helper.h"

HBox::HBox(Size size) : IContainer(size) {}

HBox::HBox(Size size, Elements elements) : IContainer(size){
    _elements = elements;
}

void HBox::computeRequirement() {
    for (auto& child : _elements) {
        child->computeRequirement();

        int currentWidth = _constraints.getMinWidth();
        int currentHeight = _constraints.getMinHeight();
        _constraints.setMinHeight(child->getRequiredSize().getWidth() + currentWidth);

        if (currentHeight < child->getRequiredSize().getHeight()) _constraints.setMinHeight(child->getRequiredSize().getHeight());
    }
}

void HBox::layout(Box& box) {
    Node::layout(box);

    vector<BoxHelper> helpers;
    for (auto& child : _elements) {
        Size size = child->getRequiredSize();
        helpers.push_back(BoxHelper(size.getWidth(), child->getConstraints().flexGrowX(), child->getConstraints().flexShrinkX()));
    }
    
    int target = _constraints.getMinWidth();

    box_layout::compute(helpers, target);

    Point currentPoint(0, 0);
    for (int i = 0; i < helpers.size(); i++) {
        Box box(Point(currentPoint), Size(helpers[i].minSize, _constraints.getMinHeight()));
        _elements[i]->layout(box);
    }
} 