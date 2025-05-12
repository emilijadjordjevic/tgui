#ifndef COMPONENT_DecoratorFunction_H
#define COMPONENT_DecoratorFunction_H
// #include "elements/node.h"
#include "utils/factory.h"
#include <functional>

using DecoratorFunction = function<Element(Element)>;

namespace tgui {
    Element operator|(Element, DecoratorFunction);
    DecoratorFunction compose(DecoratorFunction, DecoratorFunction);
    DecoratorFunction operator|(DecoratorFunction, DecoratorFunction);

    DecoratorFunction border(char c, int topBorder, int rightBorder, int bottomBorder, int leftBorder);
    DecoratorFunction border(int topBorder, int rightBorder, int bottomBorder, int leftBorder);
    DecoratorFunction bold();
    DecoratorFunction strikethrough();
    DecoratorFunction underline();
    DecoratorFunction italic();
}

#endif