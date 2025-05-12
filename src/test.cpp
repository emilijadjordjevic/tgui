// #include "elements/textLabel.h"
// #include "elements/hbox.h"
// #include "utils/box.h"
// #include "utils/factory.h"
// #include "screen/application.h"
// #include "elements/progressBar.h"
// #include "decorator/decorator.h"
// #include <iostream>

// using namespace std;
// using namespace factory;
// using namespace tgui;

// int main() {

//     Screen screen({20,20});
//     Size s(2,2);
//     auto bar = progressBar(s, 0.9, Direction::SOUTH);
//     string text = "emilija je lepa i novak je govno";
//     auto text1 = textLabel(text);
//     auto label = bar | border('P', 1, 1, 1, 1);
//     auto label1 = text1 | border('P', 1, 1, 1, 1);
//     auto hbox1 = hbox({ label1 });
//     screen.setRoot(hbox1);
//     screen.render();
//     screen.print();
//     return 0;
// }