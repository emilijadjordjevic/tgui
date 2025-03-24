#ifndef DISPLAY_CELL_H
#define DISPLAY_CELL_H

#include <iostream>
using namespace std;

class DisplayCell {
private:
    char c;
    int backgroundColor;
    int foregroundColor;
    bool dirty;
public:
    DisplayCell(char, int, int);
    ~DisplayCell();

    bool operator==(const DisplayCell&) const;
    DisplayCell& setChar(char c);
    DisplayCell& setBackgroundColor(int);
    DisplayCell& setForegroundColor(int);
};

#endif