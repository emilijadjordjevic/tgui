#include "screen/terminal.h"
#include <csignal>
#include <sys/ioctl.h>
using namespace ANSI;


Terminal& Terminal::getInstance() {
    static Terminal instance;
    return instance;
}

// Terminal::~Terminal() {
//     cleanup();
// }

Terminal::Terminal() {}

void Terminal::init() {
    enableRawMode();

    enterAlternateScreen();
    hideCursor();
    clearScreen();
    moveCursorTopLeft();
}

void Terminal::cleanup() {
    disableRawMode();
}

Size Terminal::getSize() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        return Size(w.ws_col, w.ws_row);
    }

    return {100,100};
}

string Terminal::drawChar(char c, int row, int col) {
    return moveCursor(row, col) + string(1, c); 
}

void Terminal::setTerminalSize(int cols, int rows) {
    cout << "\033[8;" << rows << ";" << cols << "t";
}

string Terminal::setTextColor(int col) {
    return "\033[38;5;" + to_string(col) + "m";
}

string Terminal::setBackgroundColor(int col) {
    return "\033[48;5;" + to_string(col) + "m";
}

string Terminal::drawChar(char c, int row, int col, int bgCol, int fgCol) {
    return moveCursor(row, col) + setTextColor(fgCol) + setBackgroundColor(bgCol) + string(1, c);
}

void Terminal::enterAlternateScreen() {
    std::cout << "\033[?1049h";
    std::cout.flush();
}

void Terminal::hideCursor() {
    std::cout << "\033[?25l"; 
    std::cout.flush();
}

void Terminal::clearScreen() {
    std::cout << "\033[2J";  
    std::cout.flush();
}

void Terminal::moveCursorTopLeft() {
    std::cout << "\033[H"; 
    std::cout.flush();
}

void Terminal::showCursor() {
    std::cout << "\033[?25h";  
    std::cout.flush();
}

void Terminal::leaveAlternateScreen() {
    std::cout << "\033[?1049l";
    std::cout.flush();
}
