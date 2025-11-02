#include <iostream>
#include "elements/textLabel.h"
#include "elements/hbox.h"
#include "utils/box.h"
#include "utils/factory.h"
#include "screen/application.h"
#include "elements/progressBar.h"
#include "decorator/decorator.h"

using namespace std;
using namespace factory;
using namespace tgui;

int main() {
    cout << "heloooou" << endl;
    Size s(1,1);
    Size s1(10, 11);
    string sent = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum";
    string sent2 = "emilijaaaaaaaaaaaaaaaaaaaaaaaa";
    string sent3 = "SJDIUBIUBFIUBEUUIEB";
    auto bar = progressBar(s, 0.9, Direction::SOUTH);
    auto bar1 = progressBar(s1, 0.5, Direction::NORTH);
    auto tl1 = textLabel(sent);
    auto tl2 = textLabel(sent2);
    // auto chg = tl2 | border('Q',1,1,1,1);
    auto box = hbox({bar, tl2}); //, tl2, bar1
    auto tl3 = textLabel(sent3);
    auto bar2 = progressBar(s, 0.9, Direction::SOUTH);
    auto box2 = hbox({tl3, bar2});
    auto vboxx = hbox({box2, box}); 
    Screen screen({90,40});
    screen.setRoot(vboxx);
    screen.render();
    screen.print();
    cout << "SIZE FOR BOX2: " << endl;
    cout << "W: " << box2->getBoxWidth() << " H: " << box2->getBoxHeight() << " X: "  << box2->getOrigin().getX() << endl;

    cout << "SIZE FOR TL3: " << endl;
    cout << "W: " << tl3->getBoxWidth() << " H: " << tl3->getBoxHeight()  << " X: "  << tl3->getOrigin().getX() << endl;

    cout << "SIZE FOR bar2: " << endl;
    cout << "W: " << bar2->getBoxWidth() << " H: " << bar2->getBoxHeight()  << " X: "  << bar2->getOrigin().getX() << endl;

    cout << "SIZE FOR BOX: " << endl;
    cout << "W: " << box->getBoxWidth() << " H: " << box->getBoxHeight()  << " X: "  << box->getOrigin().getX() << endl;

    cout << "SIZE FOR bar: " << endl;
    cout << "W: " << bar->getBoxWidth() << " H: " << bar->getBoxHeight()  << " X: "  << bar->getOrigin().getX() << endl;

    // cout << "SIZE FOR chg: " << endl;
    // cout << "W: " << tl1->getBoxWidth() << " H: " << tl1->getBoxHeight() << endl;



    return 0;
}