#ifndef ANSI_H
#define ANSI_H

#include <iostream>
#include <termios.h>
using namespace std;

namespace ANSI {

    struct TerminalState {
        struct termios originalTermios; 
    };

    string moveCursor(int, int);
    string setColor(int, int);
    string resetColor();
    string clearScreen();
    string hideCursor();
    string showCursor();
    void enableRawMode();
    void disableRawMode();
}

#endif