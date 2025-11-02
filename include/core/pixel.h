#ifndef PIXEL_H
#define PIXEL_H

#include "utils/point.h"
#include <iostream>
using namespace std;

enum TextStyle {
    NONE = 0,
    UNDERLINE = 1 << 0,
    BOLD = 1 << 1,
    STRIKETHROUGH = 1 << 2,
    ITALIC = 1 << 3,
};


class Pixel {
private:
    char _ch;
    int _bgColor;
    int _fgColor;
    int _textStyle;
public:
    Pixel();
    Pixel(char, int, int);
    ~Pixel();

    void setChar(char);
    void setBackgroundColor(int);
    void setForeGroundColor(int);

    void setTextStyle(int style);
    void addTextStyle(TextStyle);
    void removeTextStyle(TextStyle);
    bool hasTextStyle(TextStyle style) const;
    int getTextStyle() const;

    char getChar() const;
    int getBackgroundColor() const;
    int getForeGroundColor() const;

    bool operator==(const Pixel&);
};

#endif