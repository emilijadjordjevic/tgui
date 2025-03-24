#ifndef SIZE_H
#define SIZE_H

#include <iostream>
using namespace std;

class Size {
private:
    int width;
    int height;
public:
    Size();
    Size(int, int);
    ~Size();

    int getWidth() const;
    int getHeight() const;
    void setWidth(int);
    void setHeight(int);
    bool operator==(const Size&);
    Size operator+(const Size&);
    bool operator>(const Size&);
    bool operator>(int);
};

#endif