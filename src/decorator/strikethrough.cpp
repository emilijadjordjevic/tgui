#include "decorator/strikethrough.h"

Striketrough::Striketrough(Element e) : Decorator(e) {}

int Striketrough::getLayer() const {
    return static_cast<int>(NodeLayer::InlineStyle);
}

void Striketrough::render(Bitmap& map) {
    Point origin = _box.getOrigin();
    int width = _box.getWidth();
    int height = _box.getHeight();

    for (int i = origin.getY(); i < origin.getY() + height; i++) {
        for (int j = origin.getX(); j < origin.getX() + width; j++) {
            map.pixelAt(i, j).addTextStyle(TextStyle::STRIKETHROUGH);
        }
    }
}