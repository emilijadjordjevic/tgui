#ifndef BOX_LAYOUT_HELPER_H
#define BOX_LAYOUT_HELPER_H

#include <vector>
#include <iostream>
using namespace std;

class BoxHelper {
public:
    int minSize;
    int flex_grow;
    int flex_shrink;
    int size;
    BoxHelper(int, int, int);

    friend ostream& operator<<(ostream& os, const BoxHelper&);
};

namespace box_layout {
    void compute(vector<BoxHelper>&, int target);
    void distributeExtraSpace(vector<BoxHelper>& elements, int space, double flexSum, int);
    void shrinkElementsByFlex(vector<BoxHelper>& elements, int space, double flexSize, int targetSize, int);
    void shrinkToFit(vector<BoxHelper>& elements, int overflow, int elementSum);
}

#endif