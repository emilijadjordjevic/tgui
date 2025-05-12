#include "elements/vbox.h"
#include "utils/box_layout_helper.h"
using namespace box_layout;

VBox::VBox(Size size) : IContainer(size) {}

VBox::VBox(Size size, Elements elements) : IContainer(size, elements) {}

VBox::VBox(Elements elements) : IContainer(elements) {}

void VBox::computeRequirement() {
    
    for (auto& element : _elements) {
        element->computeRequirement();

        int currentHeight = _constraints.getMinHeight();
        int currentWidth = _constraints.getMinWidth();

        _constraints.setMinHeight(currentHeight + element->getRequiredSize().getHeight());
        if (element->getRequiredSize().getWidth() > _constraints.getMinWidth()) 
            _constraints.setMinWidth(element->getRequiredSize().getWidth());
    }
}

void VBox::layout(Box& box) {
    Node::layout(box);

    vector<BoxHelper> helpers; 
    for (auto& element : _elements) {
        BoxHelper b(element->getRequiredSize().getHeight(), element->getFlexGrowY(), element->getFlexShrinkY());

        helpers.push_back(b);
    }

    int targetSize = getRequiredSize().getHeight();

    compute(helpers, targetSize);

    Point currentPoint(_box.getOrigin());
 
    for (int i = 0; i < _elements.size(); i++) {
        Box b(currentPoint, Size(min(getRequiredSize().getWidth(), _elements[i]->getRequiredSize().getWidth()), helpers[i].minSize));
        _elements[i]->layout(b);
        currentPoint.move(0, helpers[i].minSize);
    }
}