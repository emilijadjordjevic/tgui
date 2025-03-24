#ifndef TERMINAL_APP_H
#define TERMINAL_APP_H

#include <iostream>
#include "terminalDrawEngine.h"
#include "terminalEnvironment.h"
#include "utils/Position.h"

class TerminalApp {
private:
    TerminalDrawEngine *termDraw;
    TerminalEnvironment *termEnv;
    static TerminalApp *instance;
    TerminalApp();
    ~TerminalApp();
    TerminalApp(const TerminalApp&) = delete;
    TerminalApp& operator=(const TerminalApp&) = delete;
public:
    static TerminalApp* getInstance();

    void init();
    void clearScreen();
    void drawText(int row, int col, char c, int textColor = 37, int bgColor = 40);
    void drawText(Position p, char c, int textColor, int bgColor);
    void resetColors();
};

#endif