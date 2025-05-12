#include "core/bitmap.h"
#include "screen/terminal.h"

Bitmap::Bitmap() : _mapSize(0, 0) {
    clear();
}

Bitmap::Bitmap(Size size) : _mapSize(size) {
    clear();
}

void Bitmap::resize(Size s) {
    _mapSize = s;
    clear();
}

void Bitmap::clear() {
    _pixels.resize(_mapSize.getHeight());

    for (int y = 0; y < _mapSize.getHeight(); y++) {
        _pixels[y].resize(_mapSize.getWidth());

        for (int x = 0; x < _mapSize.getWidth(); x++) {
            _pixels[y][x] = make_unique<Pixel>();
            _pixels[y][x]->setChar('-');
        }
    }
}

Pixel& Bitmap::pixelAt(int i, int j) const {
    return *_pixels.at(i).at(j);
}

void Bitmap::setPixel(Pixel& pixel, int i, int j) {
    if (inBounds(i, j)) {
        _pixels[i][j] = make_unique<Pixel>(pixel);
    }
}

void Bitmap::setChar(char c, int i, int j) {
    pixelAt(i, j).setChar(c);
}

int Bitmap::width() const {
    if (_pixels.empty()) return 0;

    return _pixels.at(0).size();
}

int Bitmap::height() const {
    return _pixels.size();
}

void Bitmap::printBitmap() const {
    for (int i = 0; i < height(); i++) {
        for ( int j = 0; j < width(); j++) {
            cout << Terminal::drawChar(pixelAt(i, j).getChar(), i, j);
            // cout << pixelAt(i, j).getChar() << std::flush;
        }
        // cout << endl;
    }
}



