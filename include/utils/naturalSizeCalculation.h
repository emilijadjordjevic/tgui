#ifndef NATURAL_SIZE_CALCULATION_H
#define NATURAL_SIZE_CALCULATION_H

#include "sizeCalculation.h"

class NaturalSizeCalculation : public SizeCalculation {
public:
    Size calculateSize(const string&, int width = -1) const;
};

#endif