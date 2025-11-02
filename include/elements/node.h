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

enum class NodeLayer {
    //textlabel, prohgress bar, button, conatiner..
    Content = 0, //textlabel, prohgress bar, button, conatiner..
    //dekoratori - bold, italic strkie
    InlineStyle = 1, //dekoratori - bold, italic strkie
    //padding
    BoxStyle = 2, // padding
    //border
    Border = 3, // border
    //margin
    Margin = 4 // margin
};

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
    virtual void render(Bitmap&) = 0; 
    virtual int getLayer() const = 0;

    void setParent(Element);
    void setOrigin(Point);
    void setRequiredSize(Size);
    void setFlexGrow(double, double);
    void setFlexGrowY(double);
    void setFlexGrowX(double);

    void setFlexShrink(double, double);
    void setFlexShrinkX(double);
    void setFlexShrinkY(double);

    Constraints getConstraints() const;
    Size getRequiredSize() const;
    Point getOrigin() const;
    int getBoxHeight() const;
    int getBoxWidth() const;
    double getFlexGrowY() const;
    double getFlexGrowX() const;
    double getFlexShrinkY() const;
    double getFlexShrinkX() const;

    friend ostream& operator<<(ostream&, const Node&); 
};

#endif