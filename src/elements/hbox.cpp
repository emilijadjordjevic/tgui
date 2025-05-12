#include "elements/hbox.h"
#include "utils/box_layout_helper.h"

HBox::HBox(Size size) : IContainer(size) {}

HBox::HBox(Size size, Elements elements) : IContainer(size, elements) {}

HBox::HBox(Elements elements) : IContainer(elements) {}

void HBox::computeRequirement() {
    for (auto& child : _elements) {
        child->computeRequirement();

        int currentWidth = _constraints.getMinWidth();
        int currentHeight = _constraints.getMinHeight();
        _constraints.setMinWidth(child->getRequiredSize().getWidth() + currentWidth);

        if (currentHeight < child->getRequiredSize().getHeight()) _constraints.setMinHeight(child->getRequiredSize().getHeight());
    }
}

void HBox::layout(Box& box) {
    Node::layout(box);

    vector<BoxHelper> helpers;
    for (auto& child : _elements) {
        Size size = child->getRequiredSize();
        helpers.push_back(BoxHelper(size.getWidth(), child->getFlexGrowX(), child->getFlexShrinkX()));
    }
    
    int target = _box.getRequiredSize().getWidth();

    box_layout::compute(helpers, target);

    Point currentPoint(0, 0);
    for (int i = 0; i < helpers.size(); i++) {
        Box box(Point(currentPoint), Size(helpers[i].minSize, _box.getRequiredSize().getHeight()));
        _elements[i]->layout(box);
        cout << "minsize: " << helpers[i].minSize  << "i: " << i << " " << _box.getRequiredSize().getHeight() << endl;
        currentPoint.move(helpers[i].minSize, 0);
    }
} 