#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H

#include <iostream>
#include "utils/Position.h"
#include "utils/Size.h"
#include "core/DisplayGrid.h"

class UIComponent {
protected:
    Size requiredSize;
    Size prefferedSize;
    Position position;
public:
    UIComponent();
    UIComponent(Size);
    virtual ~UIComponent();

    // virtual void draw(Position) = 0;
    virtual void setPositionOnScreen(Position, DisplayGrid&) = 0;
    virtual void calculateRequiredSize() = 0;
    void setPrefferedSize(Size);
    void setPrefferedWidth(int);
    void setPrefferedHeight(int);
    Size getRequiredSize() const;
    bool isPrefSizeSet() const;
    void setPosition(Position);
    Position getPosition() const;
    
};

#endif