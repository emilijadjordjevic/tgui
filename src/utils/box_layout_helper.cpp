// #include "box_layout_helper.h"
#include "utils/box_layout_helper.h"
#include <algorithm>
#include <iostream>
using namespace std;

BoxHelper::BoxHelper(int minSize, int flexGrow, int flexShrink) : flex_grow(flexGrow), flex_shrink(flexShrink), minSize(minSize) {}

ostream& operator<<(ostream& os, const BoxHelper& other) {
    os << "minsize: " << other.minSize << "\n";
    return os;
}


namespace box_layout {
    void compute(vector<BoxHelper>& elements, int available_space) {
        int size = 0;
        int flex_grow_sum = 0;
        int flex_shrink_sum = 0;
        int flex_shirnk_size = 0;
        int flex_grow_size = 0;
        int flexDirection = 1;

        for (auto& child : elements) {
            flex_grow_sum += child.flex_grow;
            flex_shrink_sum += child.flex_shrink;
            size += child.minSize;

            if (child.flex_grow) {
                flex_grow_size += child.minSize * child.flex_grow;
            }

            if (child.flex_shrink) {
                flex_shirnk_size += child.minSize * child.flex_shrink;
            }
        }

        cout << "avaiable spae " << available_space << " size " << size;

        int space_left = available_space - size;

        cout << "space left " << space_left;

        if (!space_left) {
            return;
        }

        cout << "flex shrink size" << flex_shirnk_size << endl;
        
        if (space_left > 0) {
            cout << "here sir";
            cout << "felx grow sum: " << flex_grow_sum;
            if (flex_grow_sum) distributeExtraSpace(elements, space_left, flex_grow_sum, flex_grow_size);
        } else  {
            cout << "hellouu" << endl;
            if (flex_shrink_sum) {
                shrinkElementsByFlex(elements, space_left, flex_shrink_sum, available_space, flex_shirnk_size);
            } else {
                cout << "shrink hard" << endl;
                shrinkToFit(elements, space_left, size);
            }
        }
    }

    void distributeExtraSpace(vector<BoxHelper>& elements, int space, double flexSum, int flexSize) {

        for (auto& element : elements) {
            double dx = (element.flex_grow * static_cast<double>(element.minSize)) / static_cast<double>(flexSize) * space;

            element.minSize = element.minSize + dx;
        }
    }
    
    void shrinkElementsByFlex(vector<BoxHelper>& elements, int space, double flexSum, int targetSize, int flexSize) {


        int elementsWithNoShrinkage = 0;
        
        for (auto& element : elements) {
            
            double dx = ((element.flex_shrink * static_cast<double>(element.minSize)) / static_cast<double>(flexSize) * space);

            cout << " fx " << dx << endl;

            element.minSize = max(0, static_cast<int>(element.minSize + dx));

            targetSize -= element.minSize;
            if (!element.flex_shrink) {
                elementsWithNoShrinkage += element.minSize;
            }
        }

        cout << "target size:: " << targetSize << endl;
        // if (targetSize < 0) {
        //     cout << "in this block ELEMENTSNOSHRINKAGE " << elementsWithNoShrinkage <<  endl;
        //     for (auto& element : elements) {
        //         if (!element.flex_shrink) {
        //             cout << "minsize " << element.minSize << " elementsNoShrinkage " << elementsWithNoShrinkage << " targetsize " << targetSize << endl;
        //             int dx = static_cast<int>(static_cast<float>(element.minSize) / elementsWithNoShrinkage * targetSize);
        //             cout << "DX: " <<dx << endl;
        //             element.minSize = max(0, static_cast<int>(element.minSize + dx));
        //         }
        //     }
        // }

        if (targetSize < 0) shrinkToFit(elements, targetSize, elementsWithNoShrinkage);
    }

    void shrinkToFit(vector<BoxHelper>& elements, int overflow, int elementSum) {
        for (auto& element : elements) {
            double dx = (static_cast<double>(element.minSize) / elementSum) * overflow;
            cout << "current dx " << dx;
            element.minSize = max(0, static_cast<int>(element.minSize + dx));
        }
    }
}