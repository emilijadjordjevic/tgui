#include "decorator/bold.h"

Bold::Bold(Element e) : Decorator(e) {}

void Bold::computeRequirement() {
    Decorator::computeRequirement();
}

void Bold::ComputeMinSize() {

}

int Bold::getLayer() const {
    return static_cast<int>(NodeLayer::InlineStyle);
}

void Bold::render(Bitmap& map) {
    Point origin = _box.getOrigin();
    int width = _box.getWidth();
    int height = _box.getHeight();

    for (int i = origin.getY(); i < origin.getY() + height; i++) {
        for (int j = origin.getX(); j < origin.getX() + width; j++) {
            map.pixelAt(i, j).addTextStyle(TextStyle::BOLD);
        }
    }
}