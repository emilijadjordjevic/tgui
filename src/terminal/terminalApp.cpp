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

void TerminalApp::resetColors() {
    termEnv->resetColors();
}

TerminalApp::~TerminalApp() {
    delete termDraw;
    delete termEnv;
}



