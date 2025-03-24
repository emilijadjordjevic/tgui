#ifndef TEXT_LABEL_H
#define TEXT_LABEL_H

#include "uiComponent.h"
#include <iostream>
#include <vector>
#include "../utils/textMetrics.h"
#include "sizeCalculation.h"

using namespace std;

class TextLabel : public UIComponent {
private:
    string text;
    SizeCalculation* sizeCalculation;
    int largestWord = -1;

    void placeLine(const string& line, Position p, DisplayGrid& grid) {
        for (size_t i = 0; i < line.size(); i++)
        {
            Position linePos(p.getY(), p.getX() + i);
            grid.setCell(linePos, line[i], 0, 7);
        }
    }

    // inline int calculateRequiredWidth() const {
    //     return max(largestWord, requiredSize.getWidth());
    // }

public:
    TextLabel(Size, string);
    ~TextLabel();

    void setSizeCalculation(SizeCalculation*);
    void setPositionOnScreen(Position, DisplayGrid&);
    void calculateRequiredSize();
    int getLargestWordSize() const;
};

#endif