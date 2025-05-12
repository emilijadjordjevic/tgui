#include "decorator/decorator.h"
using namespace factory;

namespace tgui {
    Decorator compose(Decorator a, Decorator b) {
        return [a = move(a), b = move(b)](Element element) {
            return b(a(element));
        };
    }

    Decorator operator|(Decorator a, Decorator b) {
        return compose(move(a), move(b));
    }

    Element operator|(Element element, Decorator decorator) {
        return decorator(element);
    }

    Decorator border(char c, int topBorder, int rightBorder, int bottomBorder, int leftBorder) {
        return [=](Element e) {
            return factory::borderInternal(e, c, topBorder, rightBorder, bottomBorder, leftBorder);
        };
    }

    Decorator border(int topBorder, int rightBorder, int bottomBorder, int leftBorder) {
        return [=](Element e) {
            return factory::borderInternal(e, topBorder, rightBorder, bottomBorder, leftBorder);
        };
    }

    Decorator bold() {
        return [=](Element e) {
            return factory::boldInternal(e);
        };
    }

    Decorator strikethrough() {
        return [=](Element e) {
            return factory::strikethroughInternal(e);
        };
    }

    Decorator underline() {
        return [=](Element e) {
            return factory::underlineInternal(e);
        };
    }

    Decorator italic() {
        return [=](Element e) {
            return factory::italicInternal(e);
        };
    }
}