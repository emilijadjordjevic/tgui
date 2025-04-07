#ifndef SIZE_H
#define SIZE_H

#include <iostream>
using namespace std;

class Size {
private:
    int _width;
    int _height;
public:
    Size();
    Size(int, int);
    Size(const Size&);
    ~Size();

    void setWidth(int);
    void setHeight(int);

    int getWidth() const;
    int getHeight() const;

    int area() const;

    friend ostream& operator<<(ostream&, const Size&);
    bool operator==(const Size&);
    // bool operator!=(const Size&);
    bool operator==(const int) const;
    bool operator!=(const int) const;
};

#endif