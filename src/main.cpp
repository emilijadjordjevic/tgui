#include <iostream>
#include "terminal/terminalApp.h"

using namespace std;

int main() {

    TerminalApp app;

    app.init();

    app.drawText(5, 10, 'A', 31, 44);
    app.drawText(10, 11, 'B', 31, 44);
    app.drawText(7, 10, 'C', 31, 44);
    app.drawText(12, 10, 'D', 31, 44);

    cout << "EMILIJA";

    return 0;
}