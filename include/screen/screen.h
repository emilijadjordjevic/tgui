#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <memory>
#include "core/bitmap.h"
#include "utils/box.h"
#include "terminal.h"
#include "elements/node.h"
using namespace std;

class Node;
using BitmapPtr = unique_ptr<Bitmap>;
using Root = shared_ptr<Node>;

class Screen {
private:
    BitmapPtr _pixels;
    Box _viewport;
    Terminal& terminal;
    Root root;
public:
    Screen(Size);
    Screen(Screen&);
    ~Screen();
    // rawmode, alternate screen, hide cursor
    void init();
    void setRoot(Root);
    // void resize(const Size&);
    void resize();
    void render();
    string print();
    string updateStyle(Pixel&);
    Size getSize() const;
};

#endif