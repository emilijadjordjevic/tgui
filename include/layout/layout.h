#ifndef LAYOUT_H
#define LAYOUT_H

#include <iostream>
#include "uiComponent.h";
using namespace std;

class Layout {
public:
    void arrangeElements(vector<UIComponent*>);
};

#endif