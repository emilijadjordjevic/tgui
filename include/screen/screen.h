#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <memory>
#include "core/bitmap.h"
#include "utils/box.h"
#include "utils/size.h"
using namespace std;

using BitmapPtr = unique_ptr<Bitmap>;

class Screen {
private:
    BitmapPtr _pixels;
    Box _viewport;
public:
    Screen();
    Screen(Size, Point);
    Screen(Box);

    void render();
    string print();
    string updateStyle(Pixel&);
};

#endif