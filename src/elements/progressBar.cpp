#include "elements/progressBar.h"

// ----||| -normal
// |||---- -inversed

void ProgressBar::renderLateral(Bitmap& map, bool inversed) {
    int width = _box.getRequiredSize().getWidth();
    int height = _box.getRequiredSize().getHeight();
    Point origin = _box.getOrigin();

    char c = '*';

    int fieldsToFill = _progress * width;
    for (int i = origin.getY(); i < origin.getY() + height; i++) {
        int positionIncrement = inversed ? width - 1 : fieldsToFill - 1;
        for (int j = origin.getX(), fields = fieldsToFill; fields > 0; fields--) {
            map.setChar(c, i, j + positionIncrement);
            positionIncrement--;
        }
    }
}

void ProgressBar::renderVertical(Bitmap& map, bool inversed) {
    int width = _box.getRequiredSize().getWidth();
    int height = _box.getRequiredSize().getHeight();
    Point origin = _box.getOrigin();

    char c = '*';
    int fieldsToFill = _progress * height;
    for (int j = origin.getX(); j < origin.getX() + width; j++) {
        int positionIncrement = inversed ? height - 1 : fieldsToFill - 1;
        for (int i = origin.getY(), fields = fieldsToFill; fields > 0; fields--, positionIncrement--) {
            // cout << "i: " << i + positionIncrement << " j: " << j << endl;
            map.setChar(c, i + positionIncrement, j);
        }
    }
}

ProgressBar::ProgressBar(float progress, Direction direction) : Node(), _progress(progress), _direction(direction) {
    ComputeMinSize();
}

ProgressBar::ProgressBar(Size size, float progress, Direction direction) : Node(size), _progress(progress), _direction(direction) {
    ComputeMinSize();
}

void ProgressBar::computeRequirement() {
    // Node::computeRequirement();
    switch(_direction) {
        case Direction::SOUTH:
        case Direction::NORTH:
            setFlexGrow(0, 1); //unutar kontejnera zauzmi mogucu visinu
            setFlexShrink(0, 1);
            _constraints.setRequiredHeight(max(_constraints.getMinSize().getHeight(), _constraints.getPrefHeight()));
            _constraints.setRequiredWidth(( _constraints.getPrefSize().getWidth() > 0) ? _constraints.getPrefSize().getWidth() : 1);
            break;
        case Direction::EAST:
        case Direction::WEST:
            setFlexGrow(1, 0); // unutar kontejnera zauzmi mogucu duzinu
            setFlexShrink(1, 0);
            _constraints.setRequiredWidth(max(_constraints.getMinSize().getWidth(), _constraints.getPrefWidth()));
            _constraints.setRequiredHeight((_constraints.getPrefSize().getHeight() > 0) ? _constraints.getPrefSize().getHeight() : 1);
    }
    cout << "MY WISTH: " << _constraints.getRequiredWidth() << " MY HEIGHT: " << _constraints.getRequiredHeight() << endl;
}

void ProgressBar::ComputeMinSize() {
    _constraints.setRequiredSize({1,1});
}

int ProgressBar::getLayer() const {
    return static_cast<int>(NodeLayer::Content);
}

void ProgressBar::layout(Box& box) {
    // box.setSize({box.getRequiredSize().getWidth(), 1});
    Node::layout(box);
    // cout << "width: " << box.getRequiredSize().getWidth() << " height: " << box.getRequiredSize().getHeight() << " x: " << box.getOrigin().getX() << " y: " << box.getOrigin().getY() << endl;
    
}

void ProgressBar::render(Bitmap& map) {
    switch(_direction) {
        case Direction::SOUTH:
            renderVertical(map, false);
            break;
        case Direction::NORTH:
            renderVertical(map, true);
            break;
        case Direction::EAST:
            renderLateral(map, false);
            break;
        case Direction::WEST:
            renderLateral(map, true);
            break;
    }
}
