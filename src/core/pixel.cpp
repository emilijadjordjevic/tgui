#include "core/pixel.h"

Pixel::Pixel() {}

Pixel::~Pixel() {}

Pixel::Pixel(char ch, int bgCol, int fgCol) : _ch(ch), _bgColor(bgCol), _fgColor(fgCol) {}

int Pixel::getBackgroundColor() const {
    return _bgColor;
}

int Pixel::getForeGroundColor() const {
    return _fgColor;
}

char Pixel::getChar() const {
    return _ch;
}

void Pixel::setBackgroundColor(int bgCol) {
    _bgColor = bgCol;
} 

void Pixel::setForeGroundColor(int fgCol) {
    _fgColor = fgCol;
}

void Pixel::setChar(char c) {
    _ch = c;
}

bool Pixel::operator==(const Pixel& other) {
    return this->_ch == other.getChar() && this->_bgColor == other.getBackgroundColor() && this->_fgColor == other.getForeGroundColor();
} 




