#include "decorator/decorator.h"
using namespace factory;

namespace tgui {
    DecoratorFunction compose(DecoratorFunction a, DecoratorFunction b) {
        return [a = move(a), b = move(b)](Element element) {
            return b(a(element));
        };
    }

    DecoratorFunction operator|(DecoratorFunction a, DecoratorFunction b) {
        return compose(move(a), move(b));
    }

    Element operator|(Element element, DecoratorFunction decoratorFunction) {
        return decoratorFunction(element);
    }

    DecoratorFunction border(char c, int topBorder, int rightBorder, int bottomBorder, int leftBorder) {
        return [=](Element e) {
            return factory::borderInternal(e, c, topBorder, rightBorder, bottomBorder, leftBorder);
        };
    }

    DecoratorFunction border(int topBorder, int rightBorder, int bottomBorder, int leftBorder) {
        return [=](Element e) {
            return factory::borderInternal(e, topBorder, rightBorder, bottomBorder, leftBorder);
        };
    }

    DecoratorFunction bold() {
        return [=](Element e) {
            return factory::boldInternal(e);
        };
    }

    DecoratorFunction strikethrough() {
        return [=](Element e) {
            return factory::strikethroughInternal(e);
        };
    }

    DecoratorFunction underline() {
        return [=](Element e) {
            return factory::underlineInternal(e);
        };
    }

    DecoratorFunction italic() {
        return [=](Element e) {
            return factory::italicInternal(e);
        };
    }
}