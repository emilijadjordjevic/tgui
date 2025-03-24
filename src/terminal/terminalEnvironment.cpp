#include "terminal/terminalEnvironment.h"

TerminalEnvironment::TerminalEnvironment() {
    init();
}

void TerminalEnvironment::enableRawMode() {
    tcgetattr(STDERR_FILENO, &this->originalTermios);
    this->originalTermios.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTermios);
}

void TerminalEnvironment::disableRawMode() {
    // tcgetattr(STDIN_FILENO, &originalTermios);
    originalTermios.c_lflag |= (ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTermios);
}

void TerminalEnvironment::clearScreen() {
    std::cout << "\033[2J\033[H";
}

void TerminalEnvironment::resetColors() {
    std::cout << "\033[0m";
}

void TerminalEnvironment::init() {
    enableRawMode();
}

void TerminalEnvironment::moveCursor(int row, int col) {
    std::cout << "\033[" << row << ";" << col << "H";
}

TerminalEnvironment::~TerminalEnvironment() {
    disableRawMode();
    clearScreen();
    resetColors();
}





