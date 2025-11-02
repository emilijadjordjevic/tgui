#include "elements/node.h"

Node::Node() : _parent(nullptr), _box(), _constraints(), _origin() { this->ComputeMinSize(); }

Node::Node(Size size) : _parent(nullptr), _box(), _constraints(), _origin() {
    _constraints.setPrefSize(size);
    this->ComputeMinSize();
}

void Node::computeRequirement() {
    Size prefSize = _constraints.getPrefSize(); 
    Size minSize = _constraints.getMinSize();

    _constraints.setRequiredWidth(max(prefSize.getWidth(), minSize.getWidth()));

    _constraints.setRequiredHeight(max(prefSize.getHeight(), minSize.getHeight()));

    // _box.setSize(prefSize);
}

void Node::setRequiredSize(Size s) {
    _constraints.setRequiredSize(s);
}

void Node::setParent(Element element) {
    this->_parent = element;
}

Size Node::getRequiredSize() const {
    return _constraints.getRequiredSize();
}

void Node::setOrigin(Point p) {
    this->_box.setOrigin(p);
}

void Node::ComputeMinSize() {
    _constraints.setMinimumSize({1, 1});
}

void Node::layout(Box& box) {
    _box = box;
}

Constraints Node::getConstraints() const {
    return _constraints;
}

ostream& operator<<(ostream& os, const Node& node) {
    os << "Position(x, y): (" << node._box.getOrigin().getX() << ", " << node._box.getOrigin().getY() << ") SIZE: (width, height) (" << node._box.getRequiredSize().getWidth() << ", " << node._box.getRequiredSize().getHeight() << ")" << endl;

    return os;
}

void Node::setFlexGrow(double growX, double growY) {
    _constraints.flexGrowX(growX);
    _constraints.flexGrowY(growY);
}

void Node::setFlexGrowY(double grow) {
    _constraints.flexGrowY(grow);
}

void Node::setFlexGrowX(double grow) {
    _constraints.flexGrowX(grow);
}

double Node::getFlexGrowY() const {
    return _constraints.flexGrowY();
}

double Node::getFlexGrowX() const {
    return _constraints.flexGrowX();
}

void Node::setFlexShrink(double shrinkX, double shrinkY) {
    _constraints.flexShrinkX(shrinkX);
    _constraints.flexShrinkY(shrinkY);
}

void Node::setFlexShrinkX(double shrink) {
    _constraints.flexShrinkX(shrink);
}


void Node::setFlexShrinkY(double shrink) {
    _constraints.flexShrinkY(shrink);
}

double Node::getFlexShrinkY() const {
    return _constraints.flexShrinkY();
}

double Node::getFlexShrinkX() const {
    return _constraints.flexShrinkX();
}

int Node::getBoxHeight() const {
    return _box.getHeight();
}

int Node::getBoxWidth() const {
    return _box.getWidth();
}

Point Node::getOrigin() const {
    return _box.getOrigin();
}


