#include "elements/node.h"

Node::Node() : _parent(nullptr), _box(), _constraints(), _origin() {}

Node::Node(Size size) : _parent(nullptr), _box(), _constraints(), _origin() {
    _constraints.setPrefSize(size);
}

void Node::computeRequirement() {
    Size prefSize = _constraints.getPrefSize(); 
    Size minSize = _constraints.getMinSize();

    prefSize.setWidth(max(prefSize.getWidth(), minSize.getWidth()));

    prefSize.setHeight(max(prefSize.getHeight(), minSize.getHeight()));

    _box.setSize(prefSize);
}

void Node::setParent(Element element) {
    this->_parent = element;
}

Size Node::getRequiredSize() const {
    return _box.getRequiredSize();
}

void Node::setOrigin(Point p) {
    this->_box.setOrigin(p);
}

void Node::ComputeMinSize() {
    _constraints.setMinimumSize({0, 0});
}

void Node::layout(Box& box) {
    _box = box;
}

Constraints Node::getConstraints() const {
    return _constraints;
}

ostream& operator<<(ostream& os, const Node& node) {
    os << "Position(x, y): (" << node._box.getOrigin().getX() << ", " << node._box.getOrigin().getY() << ") SIZE: (width, height) (" << node._box.getRequiredSize().getWidth() << ", " << node._box.getRequiredSize().getHeight() << ")" << endl;
}