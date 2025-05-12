#ifndef BOX_H
#define BOX_H

#include "utils/size.h"
#include "utils/point.h"

class Box {
private:
    Point _origin;
    Size _size;
public:
    Box();
    // Box(Point&&);
    Box(Point&);
    // Box(Size&&);
    Box(Size&);
    // Box(Point &&, Size&&);
    Box(const Point& point, const Size& size);
    Box(Point &, Size&);

    bool isRightOf(const Box&) const;
    bool isLeftOf(const Box&) const;
    bool isAbove(const Box&) const;
    bool isBelow(const Box&) const;
    bool contains(const Box&) const;

    int getHeight() const;
    int getWidth() const;

    void setSize(Size);
    void setOrigin(Point);

    Size getRequiredSize() const;
    Point getOrigin() const;

    Box& operator=(Box&);
};

#endif