#include "elements/hbox.h"
#include "utils/box_layout_helper.h"

HBox::HBox(Size size) : IContainer(size) {
    // setFlexGrowX(1);
    setFlexShrinkX(1);
}

HBox::HBox(Size size, Elements elements) : IContainer(size, elements) {
    // setFlexGrowX(1);
    setFlexShrinkX(1);
}

HBox::HBox(Elements elements) : IContainer(elements) {
    // setFlexGrowX(1);
    setFlexShrinkX(1);
}

void HBox::computeRequirement() {
    cout << "currently in hbox" << endl;
    for (auto& child : _elements) {
        child->computeRequirement();
        cout << child << endl;
        int currentWidth = _constraints.getMinWidth();
        int currentHeight = _constraints.getMinHeight();
        // _constraints.setMinWidth(child->getRequiredSize().getWidth() + currentWidth);
        _constraints.setRequiredWidth(child->getRequiredSize().getWidth() + currentWidth);

        // if (currentHeight < child->getRequiredSize().getHeight()) _constraints.setMinHeight(child->getRequiredSize().getHeight());
        if (currentHeight < child->getRequiredSize().getHeight()) _constraints.setRequiredHeight(child->getRequiredSize().getHeight());

        // cout <<"CONTAINER REQ SIZE W: " << getRequiredSize().getWidth() << "H: " << getRequiredSize().getHeight() << endl;
    }
}

void HBox::layout(Box& box) {
    Node::layout(box);
    // cout << box << endl;
    // cout << "MY BOX LAYOUT: " << "H: " << box.getHeight() << " W: " << box.getWidth() << endl;

    vector<BoxHelper> helpers;
    for (auto& child : _elements) {
        Size size = child->getRequiredSize();
        // cout << "REQ SIZE: H: " << size.getHeight() << " W: " << size.getWidth() << endl;
        helpers.push_back(BoxHelper(size.getWidth(), child->getFlexGrowX(), child->getFlexShrinkX()));
    }
    
    int target = _box.getRequiredSize().getWidth();

    box_layout::compute(helpers, target);

    Point currentPoint(box.getOrigin());
    for (int i = 0; i < helpers.size(); i++) {
        Box box(Point(currentPoint), Size(helpers[i].minSize, _box.getRequiredSize().getHeight()));
        _elements[i]->layout(box);
        cout << "minsize: " << helpers[i].minSize  << "i: " << i << " " << _box.getRequiredSize().getHeight() << endl;
        currentPoint.move(helpers[i].minSize, 0);
    }
} 