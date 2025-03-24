#ifndef TERMINAL_DRAW_ENGINE_H
#define TERMINAL_DRAW_ENGINE_H

#include <iostream>
#include "utils/Position.h"
using namespace std;

class TerminalDrawEngine {
public:
TerminalDrawEngine();
    ~TerminalDrawEngine();

    void moveCursor(int, int);
    void moveCursor(Position);
    void setTextColor(int);
    void setBackgroundColor(int);
    void drawChar(int, int, char);
    void drawChar(Position, char);
    void drawRectangle(int, int, int, int, char);
};

#endif 