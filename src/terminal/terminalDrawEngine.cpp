#include "terminal/terminalDrawEngine.h"

TerminalDrawEngine::TerminalDrawEngine() {}

void TerminalDrawEngine::drawChar(int row, int col, char c) {
    moveCursor(row, col);
    cout << c;
}

void TerminalDrawEngine::drawRectangle(int row, int col, int width, int height, char c) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            drawChar(row + i, row + j, c);
        }
    }
}

void TerminalDrawEngine::moveCursor(int row, int col) {
    cout << "\033[" << row << ";" << col << "H";
}

void TerminalDrawEngine::moveCursor(Position p) {
    cout << "\033[" << p.getY() << ";" << p.getX() << "H";
}

void TerminalDrawEngine::setBackgroundColor(int color) {
    cout << "\033[" << (color + 10) << "m";
}

void TerminalDrawEngine::setTextColor(int color) {
    std::cout << "\033[" << color << "m";
}

void TerminalDrawEngine::drawChar(Position p, char c) {
    moveCursor(p);
    cout << c;
}

TerminalDrawEngine::~TerminalDrawEngine() {}


