#include "screen/screen.h"
#include  <sstream>
#include <csignal>
#include <sys/ioctl.h>
#include <unistd.h>

Screen::Screen(Size size) : terminal(Terminal::getInstance()), _viewport(size), _pixels(make_unique<Bitmap>(size)) {
    init();
}

Screen::Screen(Screen& other)
    : terminal(Terminal::getInstance()),
      _viewport(other._viewport),
      _pixels(make_unique<Bitmap>(other.getSize())) {
        this->setRoot(other.root);
        init();
    }

Screen::~Screen() {
    terminal.cleanup();
    cout << "destruktor" << endl;
}

Size Screen::getSize() const {
    return _viewport.getRequiredSize();
}

void Screen::resize() {
    Size size = terminal.getSize();
    _viewport.setSize(size);
    _pixels->resize(size);
    root->layout(_viewport);
    root->render(*_pixels);
    print();
}

void Screen::init() {
    terminal.init();
    terminal.setTerminalSize(_viewport.getHeight(), _viewport.getWidth());
}

void Screen::render() {
    root->computeRequirement();
    root->layout(_viewport);
    root->render(*_pixels);
}

void Screen::setRoot(Root root) {
    this->root = root;
}

string Screen::print() {
    _pixels->printBitmap();
    // stringstream stream;
    // for (int i = 0; i < _pixels->height(); i++) {
    //     for (int j = 0; j < _pixels->width(); i++) {
    //         Pixel pixel = _pixels->pixelAt(i, j);
    //         stream << terminal.drawChar(pixel.getChar(), i, j, pixel.getBackgroundColor(), pixel.getForeGroundColor());
    //     }
    // }

    // return stream.str();
    return "";
}

string Screen::updateStyle(Pixel& p) {
    return "";
}

// void Screen::resize() {
//     Size size = terminal.getSize();
//     _viewport.setSize(size);
// }