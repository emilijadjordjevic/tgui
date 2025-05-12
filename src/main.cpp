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

    // string s = "emilija ej lepa";
    // string s1 = "novak ej lepa";
    // string s2 = "djbvidbviubdsiubuibfiub";
    // // cout << "hej he h";
    // // auto l1 = textLabel(s);
    // // auto l2 = textLabel(s1);
    // // auto l3 = textLabel(s2);
    // Size size(100,20);
    // Point p(0,0);
    // Box b(p, size);
    // // auto hcont = hbox(size);
    // // hcont->add(l1);
    // // hcont->add(l2);
    // // hcont->add(l3);    

    // auto hcont = hbox({textLabel(s), textLabel(s1), textLabel(s2)});
    // // hcont->computeRequirement();
    // // hcont->layout(b);

    // cout << endl << "----------------------------------------" << endl;
    // cout << (*hcont);

    // // hcont->computeRequirement();
    // // l1->setFlexGrowX(1);
    // Size screenSize(80, 80);
    // Screen screen(screenSize);
    // screen.setRoot(hcont);
    // screen.render();
    // cout << screen.print();
    // // hcont->layout(b);

    // // cout << *l1;
    // // cout << *l2;
    // // cout << *l3;
    // Application app;
    // app.run();

    Size s(1,1);
    Size s1(10, 11);
    string sent = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum";
    string sent2 = "emilijaaaaaaaaaaaaaaaaaaaaaaaa";
    auto bar = progressBar(s, 0.9, Direction::SOUTH);
    auto bar1 = progressBar(s1, 0.5, Direction::NORTH);
    auto tl1 = textLabel(sent);
    auto tl2 = textLabel(sent2);
    auto chg = tl1 | border('Q',1,1,1,1);
    auto box = hbox({bar, chg, tl2, bar1});
    Screen screen({34,100});
    screen.setRoot(box);
    // screen.render();
    // screen.print();

    Application app(screen);
    app.run();
    return 0;
}