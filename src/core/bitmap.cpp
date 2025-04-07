#include "core/bitmap.h"

Bitmap::Bitmap() : _mapSize(0, 0) {
    clear();
}

Bitmap::Bitmap(Size size) : _mapSize(size) {
    clear();
}

void Bitmap::clear() {
    _pixels.resize(_mapSize.getHeight());

    for (int y = 0; y < _mapSize.getHeight(); y++) {
        _pixels[y].resize(_mapSize.getWidth());

        for (int x = 0; x < _mapSize.getWidth(); x++) {
            _pixels[y][x] = make_unique<Pixel>();
        }
    }
}

Pixel Bitmap::pixelAt(int x, int y) const {
    return *_pixels.at(y).at(x);
}

void Bitmap::setPixel(Pixel& pixel, int x, int y) {
    if (inBounds(x, y)) {
        _pixels[y][x] = make_unique<Pixel>(pixel);
    }
}


