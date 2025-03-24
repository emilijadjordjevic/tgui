#include <iostream>
#include <sstream>
#include <Size.h>
#include "textMetrics.h"
using namespace std;

Size TextMetrics::computeTextSize(const string& text) {
    int maxWidth = 0;
    int currentWidth = 0;
    int height = 1;

    for (char c : text) {
        if (newLine(c)) {
            maxWidth = max(maxWidth, currentWidth);
            currentWidth = 0;
            height ++;
        } else {
            currentWidth ++;
        }
    }

    maxWidth = max(maxWidth, currentWidth);

    return {maxWidth, height};
}

Size TextMetrics::computeTextSize(const string& text, int width) {
    Size textSize = computeTextSize(text);
    int largestWord = computeLargestWord(text);
    if (textSize.getWidth() < width) {
        width = textSize.getWidth();
    }
    int reqWidth = max(largestWord, width);

    return Size(reqWidth, computeHeight(text, reqWidth));
}

int TextMetrics::computeHeight(const string& text, int width) {
    istringstream stream(text);
    vector<string> words;
    string word;

    int currentLineWidth = 0;
    int lineCount = 1;

    while (stream >> word) {
        if (currentLineWidth + word.length() + 1 > width) {
            lineCount++;
            currentLineWidth = 0;
        }

        if (currentLineWidth > 0) currentLineWidth ++;

        currentLineWidth += word.size();
    }

    if (currentLineWidth > 0) lineCount++;

    return lineCount;

}

int TextMetrics::computeLargestWord(const string& text) {
    istringstream stream(text);
    int maxLength = 0;
    string word;

    while (stream >> word) {
        if (word.length() > maxLength) {
            maxLength = word.length();
        }
    }

    return maxLength;
}

bool TextMetrics::newLine(char c) {
    return c == '\n';
}

vector<string> TextMetrics::splitLinesCaller(const string &text, int width = -1) const {
    (width == -1) ? splitLines
}

vector<string> TextMetrics::splitLines(const string &text) {
    vector<string> lines;
    string currentLine;

    for (char c : text) {
        if (newLine(c)) {
            lines.push_back(currentLine);
            currentLine.clear();
        } else {
            currentLine += c;
        }
    }

    lines.push_back(currentLine);
    return lines;
}

vector<string> TextMetrics::splitLines(const string &text, int width) {
    vector<string> lines;
    istringstream stream(text);
    string word;
    string currentLine;

    int minWidth = max(width, computeLargestWord(text));

    while (stream >> word) {
        if (!currentLine.empty() && currentLine.length() + word.length() + 1 > minWidth) {
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