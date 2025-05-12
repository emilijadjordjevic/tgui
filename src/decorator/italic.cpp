#include "decorator/italic.h"

Italic::Italic(Element e) : Decorator(e) {}

void Italic::computeRequirement() {
    setRequiredSize(_element->getRequiredSize());
}

void Italic::ComputeMinSize() {
    cout << "minsize" << endl;
}

int Italic::getLayer() const {
    return static_cast<int>(NodeLayer::InlineStyle);
}

void Italic::render(Bitmap& map) {
    Point origin = _box.getOrigin();
    int width = _box.getWidth();
    int height = _box.getHeight();

    for (int i = origin.getY(); i < origin.getY() + height; i++) {
        for (int j = origin.getX(); j < origin.getX() + width; j++) {
            map.pixelAt(i, j).addTextStyle(TextStyle::ITALIC);
        }
    }
}