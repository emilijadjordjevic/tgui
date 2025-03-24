#ifndef SIZE_CALCULATION_H
#define SIZE_CALCULATION_H

#include <iostream>
#include "Size.h"
using namespace std;

class SizeCalculation {
public:
    virtual Size calculateSize(const string& text, int width = -1) const = 0;
};

#endif