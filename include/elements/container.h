#ifndef ICONTAINER_H
#define ICONTAINER_H

#include "elements/node.h"
class IContainer;
class Node;
using Elements = vector<shared_ptr<Node>>;

class IContainer : public Node {
protected:
    Elements _elements;
public:
    IContainer(Size);
    // IContainer(Elements); 
    // IContainer(Size, Elements);

    void add(const Element&);
    void render(Screen&) override;
};

#endif