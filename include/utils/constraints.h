#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include <stdio.h>
#include "utils/size.h"
using namespace std;

class Constraints {
private:
    Size minSize;
    Size prefSize;
    Size maxSize;
    Size requiredSize;
    double flex_grow_x;
    double flex_grow_y;
    double flex_shrink_x;
    double flex_shrink_y;
public:
    Constraints();
    ~Constraints();

    void setMinimumSize(Size);
    void setMaximumSize(Size);
    void setPrefSize(Size);
    void setRequiredSize(Size);

    void setMinWidth(int);
    void setMaxWidth(int);
    void setPrefWidth(int);
    void setMinHeight(int);
    void setMaxHeight(int);
    void setPrefHeight(int);
    void setRequiredWidth(int);
    void setRequiredHeight(int);
    
    int getMinWidth() const;
    int getMinHeight() const;
    int getPrefHeight() const;
    int getPrefWidth() const;
    int getMaxWidth() const;
    int getMaxHeight() const;
    int getRequiredHeight() const;
    int getRequiredWidth() const;

    Size getMinSize() const;
    Size getPrefSize() const;
    Size getMaxSize() const;
    Size getRequiredSize() const;

    double flexGrowY() const;
    double flexGrowX() const;
    double flexShrinkX() const;
    double flexShrinkY() const;

    void flexGrowY(double);
    void flexGrowX(double);
    void flexShrinkX(double);
    void flexShrinkY(double);
};

#endif