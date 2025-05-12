#include "ansi/ansi.h"
#include <unistd.h>

namespace ANSI {
    static TerminalState state;

    string moveCursor(int row, int col) {
        return "\033[" + to_string(row + 1) + ";" + to_string(col + 1) + "H";
    }

    string setColor(int fg, int bg) {
        return "\033[38;5;" + to_string(fg) + ";48;5;" + to_string(bg) + "m";
    }

    string resetColor() {
        return "\033[0m";
    }

    string clearScreen() {
        return "\033[2J";
    }

    string hideCursor() {
        return "\033[?25l";
    }

    string showCursor() {
        return "\033[?25h";
    }

    void enableRawMode() {
        tcgetattr(STDIN_FILENO, &state.originalTermios); 
        termios raw = state.originalTermios;

        // raw.c_lflag &= ~(ECHO | ICANON | ISIG);
        // raw.c_iflag &= ~(IXON); 
        // raw.c_oflag &= ~(OPOST); 

        cfmakeraw(&raw);
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    }

    void disableRawMode() {
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &state.originalTermios);
        // tcsetattr(STDIN_FILENO, TCSANOW, &state.originalTermios);
    }
}