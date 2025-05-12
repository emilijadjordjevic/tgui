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

void Pixel::setTextStyle(int style) {
    _textStyle = style;
}

void Pixel::addTextStyle(TextStyle style) {
    _textStyle |= style;
}

void Pixel::removeTextStyle(TextStyle style) {
    _textStyle &= ~style;
}

bool Pixel::hasTextStyle(TextStyle style) const {
    return (_textStyle & style) != 0;
}

int Pixel::getTextStyle() const {
    return _textStyle;
}




