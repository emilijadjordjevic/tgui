#ifndef PIXEL_H
#define PIXEL_H

#include "utils/point.h"
#include <iostream>
using namespace std;

class Pixel {
private:
    char _ch;
    int _bgColor;
    int _fgColor;
public:
    Pixel();
    Pixel(char, int, int);
    ~Pixel();

    void setChar(char);
    void setBackgroundColor(int);
    void setForeGroundColor(int);

    char getChar() const;
    int getBackgroundColor() const;
    int getForeGroundColor() const;

    bool operator==(const Pixel&);
};

#endif