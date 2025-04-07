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
    int flex_grow_x;
    int flex_grow_y;
    int flex_shrink_x;
    int flex_shrink_y;
public:
    Constraints();
    ~Constraints();

    void setMinimumSize(Size);
    void setMaximumSize(Size);
    void setPrefSize(Size);

    void setMinWidth(int);
    void setMaxWidth(int);
    void setPrefWidth(int);
    void setMinHeight(int);
    void setMaxHeight(int);
    void setPrefHeight(int);
    
    int getMinWidth() const;
    int getMinHeight() const;
    int getPrefHeight() const;
    int getPrefWidth() const;
    int getMaxWidth() const;
    int getMaxHeight() const;

    Size getMinSize() const;
    Size getPrefSize() const;
    Size getMaxSize() const;

    int flexGrowY() const;
    int flexGrowX() const;
    int flexShrinkX() const;
    int flexSHrinkY() const;


    void flexGrowY(int);
    void flexGrowX(int);
    void flexShrinkX(int);
    void flexSHrinkY(int);
};

#endif