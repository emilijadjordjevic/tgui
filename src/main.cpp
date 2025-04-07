#include <iostream>
#include "elements/textLabel.h"
#include "elements/hbox.h"
#include "utils/box.h"

using namespace std;

int main() {

    // TerminalApp app;

    // app.init();

    // app.drawText(5, 10, 'A', 31, 44);
    // app.drawText(10, 11, 'B', 31, 44);
    // app.drawText(7, 10, 'C', 31, 44);
    // app.drawText(12, 10, 'D', 31, 44);

    // cout << "EMILIJA";

    TextLabel l1("emilija je lepa");
    TextLabel l2("novak je lep");
    TextLabel l3("ill be pretty");

    HBox h1(Size(100,20));
    h1.computeRequirement();
    Box layout(Point(0,0), Size(100,20));
    h1.layout(layout);

    cout << h1;
    cout << l1;
    cout << l2;
    cout << l3;

    return 0;
}