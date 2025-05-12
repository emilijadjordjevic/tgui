#pragma once

#ifndef TERMINAL_H
#define TEMRINAL_H

#include <iostream>
#include "ansi/ansi.h"
#include "utils/size.h"
using namespace ANSI;

class Terminal {
private:
    TerminalState state;
    Terminal();
    Terminal(const Terminal&) = delete;
    Terminal& operator=(const Terminal&) = delete;
public:
    static Terminal& getInstance();
    // ~Terminal();

    void init();
    void cleanup();

    static Size getSize();
    static void setTerminalSize(int cols, int rows);

    static void enterAlternateScreen();
    static void hideCursor();
    static void clearScreen();
    static void moveCursorTopLeft();
    static void showCursor();
    static void leaveAlternateScreen();

    static string drawChar(char c, int row, int col);
    static string setTextColor(int fgCol);
    static string setBackgroundColor(int bgCol);
    static string drawChar(char c, int row, int col, int bgCol, int fgCol);
};

#endif 