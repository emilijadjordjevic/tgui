#include "elements/textLabel.h"
#include <sstream>
#include <algorithm>

TextLabel::TextLabel(string s) : Node(), _content(s) {}

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

void TextLabel::computeMinSize() {
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

vector<string> TextLabel::splitLines() {
    vector<string> lines;
    string currentLine;
    size_t maxWidth = 0;

    for (char c : _content) {
        if (c == '\n') {
            lines.push_back(currentLine);
            maxWidth = max(maxWidth, currentLine.length());
            currentLine.clear();
        } else {
            currentLine += c;
        }
    }

    lines.push_back(currentLine);

    for (string& line : lines) {
        while (line.length() < maxWidth) {
            line += " ";
        }
    }

    return lines;
}

vector<string> TextLabel::splitLinesWithHConstraint(int size) {
    // vector<string> words;
    // istringstream stream(_content);
    // string word;

    // while (stream >> word) {
    //     words.push_back(word);
    // }

    // vector<string> lines;
    // string currentLine;
    // int minWidth = _constraints.getMinWidth();

    // for (const string& w : words) {
    //     if (!currentLine.empty() && (currentLine.length() + 1 + w.length() > minWidth)) {
    //         lines.push_back(currentLine + string(minWidth - currentLine.length(), ' '));
    //         currentLine = "";
    //     }

    //     if (!currentLine.empty()) currentLine += " ";
    //     currentLine += w;
    // }

    // if (!currentLine.empty()) {
    //     lines.push_back(currentLine + string(minWidth - currentLine.length(), ' '));
    // }

    // while (lines.size() < size) {
    //     lines.push_back(string(minWidth, ' '));  
    // }
    // while (lines.size() > height) {
    //     lines.pop_back(); 
    // }

    // return lines;
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

void TextLabel::render(Screen& screen) {

}