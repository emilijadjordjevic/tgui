#ifndef CONSTRAINED_SIZE_CALCULATION_H
#define CONSTRAINED_SIZE_CALCULATION_H

#include "sizeCalculation.h"

class ConstrainedSizeCalculation : public SizeCalculation {
public:
    Size calculateSize(const string&, int) const;
};

#endif