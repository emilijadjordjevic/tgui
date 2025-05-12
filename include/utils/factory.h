#ifndef FACTORY_H
#define FACTORY_H

#include "elements/textLabel.h"
#include "elements/hbox.h"
#include "elements/vbox.h"
#include "elements/progressBar.h"
#include "decorator/border.h"
#include "decorator/bold.h"
#include "decorator/italic.h"
#include "decorator/underline.h"
#include "decorator/strikethrough.h"

using Container = shared_ptr<IContainer>;

namespace factory {

    template<typename T, typename... Args> 
    shared_ptr<T> create(Args&&... args) {
        return make_shared<T>(forward<Args>(args)...);
    }

    Element textLabel(const string&);
    Element progressBar(float, Direction);
    Element progressBar(Size&, float, Direction);

    Element borderInternal(Element, int topBorder, int rightBorder, int bottomBorder, int leftBorder);
    Element borderInternal(Element, char c, int topBorder, int rightBorder, int bottomBorder, int leftBorder);

    Element boldInternal(Element);
    Element strikethroughInternal(Element);
    Element underlineInternal(Element);
    Element italicInternal(Element);

    // Element textLabel(const string&, Size);
    Container hbox(Size&);
    Container hbox(initializer_list<Element>);
    // Container hbox(Element);
    Container hbox(Size&, initializer_list<Element>);
    // Container hbox(Size&, Element);

    Container vbox(Size&);
    Container vbox(initializer_list<Element>);
    // Container vbox(Element);
    Container vbox(Size&, initializer_list<Element>);
    // Container vbox(Size&, Element);
}

#endif