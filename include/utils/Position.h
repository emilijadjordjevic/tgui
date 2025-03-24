#ifndef POSITION_H
#define POSITION_H

#include <iostream>
using namespace std;

class Position {
private:
    int x;
    int y;
public:
    Position();
    Position(int, int);
    ~Position();

    int getX() const;
    int getY() const;

    void setX(int);
    void setY(int);
    bool operator==(const Position&);
    void print() const;
};

#endif