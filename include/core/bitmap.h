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
    inline bool inBounds(int x, int y) { //width - jMAx, i < broj redova - visina, j < broj kolona - width -> x = j, y = i
        return y <= _mapSize.getWidth() && y >= 0 && x <= _mapSize.getHeight() && x >= 0;
    }
protected:
    Box stencil_;
public:
    Bitmap();
    Bitmap(Size);

    void clear();
    void setPixel(Pixel&, int, int);
    void setChar(char, int, int);
    Pixel& pixelAt(int, int) const;

    int width() const;
    int height() const;
    void printBitmap() const;
    void resize(Size);
};

#endif