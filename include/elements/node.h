#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <memory>
#include <vector>
#include "utils/box.h"
#include "utils/constraints.h"
#include "screen/screen.h"

class Node;
class IContainer;
using namespace std;
using Element = shared_ptr<Node>;

class Node {
protected:
    Element _parent;
    Box _box;
    Constraints _constraints;
    Point _origin;
public:
    Node();
    Node(Size); //pref size

    virtual void computeRequirement();
    virtual void ComputeMinSize();
    virtual void layout(Box&);
    virtual void render(Screen&) = 0; 

    void setParent(Element);
    Size getRequiredSize() const;
    void setOrigin(Point);
    Constraints getConstraints() const;

    friend ostream& operator<<(ostream&, const Node&); 
};

#endif