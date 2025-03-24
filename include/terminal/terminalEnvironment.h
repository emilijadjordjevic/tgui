#ifndef TERMINAL_ENVIRONMENT_H
#define TERMINAL_ENVIRONMENT_H

#include <iostream>
#include <termios.h>
#include <unistd.h>
using namespace std;

class TerminalEnvironment {
private:
    struct termios originalTermios;
public:
    TerminalEnvironment();
    ~TerminalEnvironment();
    
    void init();
    void clearScreen();
    void resetColors();
    void enableRawMode();
    void disableRawMode();
    void moveCursor(int, int);
};

#endif
