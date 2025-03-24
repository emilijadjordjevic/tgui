#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include "uiComponent.h"
#include "layout/layout.h"
#include <vector>

using namespace std;

class Container : public UIComponent {
private:
    vector<UIComponent*> elements;
    Size prefferedSize;
    Layout *layout;
public:
    Container();
    ~Container();
    void setPosition(Position, DisplayGrid&);
    void calculateRequiredSize();
    void addElement(UIComponent*);
    void removeElement(UIComponent*);
    void setPrefferedSize(Size);
    void setPrefferedSize(int, int);
};

#endif