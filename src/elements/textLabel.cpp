#include "elements/textLabel.h"
#include <sstream>
#include <algorithm>

TextLabel::TextLabel(string s) : Node(), _content(s) { setFlexGrow(1,1); }

void TextLabel::computeRequirement() {
    // if (_constraints.getPrefSize() == Size(0,0)) {
    //     _lines = splitLines();
    //     _constraints.setPrefSize({_lines.at(0).size(),_lines.size()});
    // } else if (_constraints.getPrefHeight() == 0 && _constraints.getPrefWidth() != 0) {
    //     _lines = splitLinesWithHConstraint(_constraints.getPrefWidth());
    //     _constraints.setPrefSize({_lines.at(0).size(),_lines.size()});
    // }

    // } else if (_constraints.getPrefHeight() == 0 && _constraints.getPrefWidth() != 0) {

    // }
    _constraints.setMinHeight(1);
    _constraints.setMinWidth(_content.size());
    Node::computeRequirement();
}

void TextLabel::ComputeMinSize() {
    istringstream stream(_content);
    int maxLength = 0;
    string word;

    while (stream >> word) {
        int current = word.length();
        if (current > maxLength) {
            maxLength = current;
        }
    }

    _constraints.setMinimumSize({maxLength, 1});
}

int TextLabel::getLayer() const {
    return static_cast<int>(NodeLayer::Content);
}

vector<string> TextLabel::splitLinesWithHConstraint(int size) {
    vector<string> words;
    istringstream stream(_content);
    string word;

    while (stream >> word) {
        words.push_back(word);
    }

    vector<string> lines;
    string currentLine;
    int minWidth = _constraints.getMinWidth();

    for (const string& w : words) {
        if (!currentLine.empty() && (currentLine.length() + 1 + w.length() > minWidth)) {
            lines.push_back(currentLine + string(minWidth - currentLine.length(), ' '));
            currentLine = "";
        }

        if (!currentLine.empty()) currentLine += " ";
        currentLine += w;
    }

    if (!currentLine.empty()) {
        lines.push_back(currentLine + string(minWidth - currentLine.length(), ' '));
    }

    while (lines.size() < size) {
        lines.push_back(string(minWidth, ' '));  
    }
    // while (lines.size() > height) {
    //     lines.pop_back(); 
    // }

    return lines;
}

void TextLabel::splitLines() {
    int width = _box.getRequiredSize().getWidth();
    string word = "";

    int counter = 0;
    for (char c : _content) {
        if (counter == width - 1) {
            _lines.push_back(word);
            word = "";
            counter = 0;
        }

        word[counter++] = c;
    }

    if (word != "") {
        int currentSize = word.size();
        while (currentSize != width) {
            word += ' ';
            currentSize++;
        }

        _lines.push_back(word);
    }

}

vector<string> TextLabel::splitLinesWithVConstraint(int size) {
    vector<string> lines;
    istringstream stream(_content);
    string word;
    string currentLine;
    
    while (stream >> word) {
        if (!currentLine.empty() && currentLine.length() + word.length() + 1 > size) {
            lines.push_back(currentLine);
            currentLine.clear();
        }

        if (!currentLine.empty()) {
            currentLine += " ";
        }

        currentLine += word;
    }

    if(!currentLine.empty()) {
        lines.push_back(currentLine);
    }

    return lines;
}

void TextLabel::render(Bitmap& screen) {
    Point startingPoint = _box.getOrigin();
    Size size = _box.getRequiredSize();
    int counter = 0;
    int textSize = _content.size();
    
    for (int y = startingPoint.getY(); y < startingPoint.getY() + size.getHeight() && counter < textSize; ++y) {
        for (int x = startingPoint.getX(); x < startingPoint.getX() + size.getWidth() && counter < textSize; ++x) {
            screen.setChar(_content[counter++], y, x);
        }
    }
}