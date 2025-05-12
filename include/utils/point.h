#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int _x;
    int _y;
public:
    Point();
    Point(int, int);
    Point(const Point&);

    double distanceTo(const Point&);
    void move(int dx, int dy);

    int getX() const;
    int getY() const;

    void setX(int);
    void setY(int);

    // Point operator+(const Point&);
    // Point operator-(const Point&);

    bool operator==(const Point&);
    bool operator!=(const Point&);
    // bool operator>(const Point&);
    // bool operator<(const Point&);
    // bool operator>=(const Point &);
    // bool operator<=(const Point &);
    Point& operator=(const Point&);
    bool isAbove(const Point&) const;
    bool isBelow(const Point&) const;
    bool isRightOf(const Point&) const;
    bool isLeftOf(const Point&) const;

    Point& operator=(Point&&) noexcept;

    friend ostream& operator<<(ostream&, const Point&);
};

#endif