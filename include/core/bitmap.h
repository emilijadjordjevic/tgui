#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <vector>
#include <memory>
#include "pixel.h"
#include "utils/size.h"
#include "utils/box.h"
using namespace std;
using PixelElement = unique_ptr<Pixel>;
using Pixels = vector<vector<PixelElement>>;

class Bitmap {
private:
    Pixels _pixels;
    Size _mapSize;
    inline bool inBounds(int x, int y) {
        return x <= _mapSize.getWidth() && x >= 0 && y <= _mapSize.getHeight() && y >= 0;
    }
protected:
    Box stencil_;
public:
    Bitmap();
    Bitmap(Size);

    void clear();
    void setPixel(Pixel&, int, int);
    Pixel pixelAt(int, int) const;
};

#endif