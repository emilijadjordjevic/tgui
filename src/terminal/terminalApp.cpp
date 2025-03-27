#include "terminal/terminalApp.h"

TerminalApp* TerminalApp::instance = nullptr;

TerminalApp::TerminalApp() {
    this->termDraw = new TerminalDrawEngine();
    this->termEnv = new TerminalEnvironment();
    init();
}

TerminalApp* TerminalApp::getInstance() {
    if (instance == nullptr) {
        instance = new TerminalApp();
    }

    return instance;
}

void TerminalApp::init() {
    clearScreen();
    termEnv->init();
}

void TerminalApp::clearScreen() {
    termEnv->clearScreen();
}

void TerminalApp::drawText(int row, int col, char c, int textCol, int bgCol) {
    termDraw->setTextColor(textCol);
    termDraw->setBackgroundColor(bgCol);
    termDraw->drawChar(row, col, c);
}

void TerminalApp::drawText(int row, int col, DisplayCell& cell) {
    // termDraw->setTextColor(cell.getForegroundColor());
    // termDraw->setBackgroundColor(cell.getBackgroundColor());
    // termDraw->drawChar(row, col, cell.getChar());
    drawText(row, col, cell.getChar(), cell.getForegroundColor(), cell.getBackgroundColor());
}

void TerminalApp::drawText(Position p, char c, int textColor, int bgColor) {
    // termDraw->setTextColor(textColor);
    // termDraw->setBackgroundColor(bgColor);
    drawText(p.getY(), p.getX(), c, textColor, bgColor);
}

void TerminalApp::resetColors() {
    termEnv->resetColors();
}

TerminalApp::~TerminalApp() {
    delete termDraw;
    delete termEnv;
}

void TerminalApp::drawText(Position p, DisplayCell& cell) {
    drawText(p, cell.getChar(), cell.getForegroundColor(), cell.getBackgroundColor());
}



