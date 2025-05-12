// #include "box_layout_helper.h"
#include "utils/box_layout_helper.h"
#include <algorithm>
#include <iostream>
using namespace std;

BoxHelper::BoxHelper(int minSize, int flexGrow, int flexShrink) : flex_grow(flexGrow), flex_shrink(flexShrink), minSize(minSize) {}

ostream& operator<<(ostream& os, const BoxHelper& other) {
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

        int space_left = available_space - size;

        if (!space_left) {
            return;
        }
        
        if (space_left > 0) {
            if (flex_grow_sum) distributeExtraSpace(elements, space_left, flex_grow_sum, flex_grow_size);
        } else  {
            if (flex_shrink_sum) {
                shrinkElementsByFlex(elements, space_left, flex_shrink_sum, available_space, flex_shirnk_size);
            } else {
                shrinkToFit(elements, space_left, size);
            }
        }
    }

    void distributeExtraSpace(vector<BoxHelper>& elements, int space, double flexSum, int flexSize) {
        int totalAdded = 0;
        double accumulatedError = 0;

        for (auto& element : elements) {
            double exact = (element.flex_grow * static_cast<double>(element.minSize)) / static_cast<double>(flexSize) * space;
            accumulatedError += exact;

            int rounded = static_cast<int>(accumulatedError);
            accumulatedError -= rounded;

            element.minSize = element.minSize + rounded;
            totalAdded += rounded;
        }

        int leftoverDueError = space - totalAdded;
        for (int i = 0; i < elements.size() && leftoverDueError > 0; i++) {
            elements[i].minSize += 1;
            leftoverDueError--;
        }
    }
    
    void shrinkElementsByFlex(vector<BoxHelper>& elements, int space, double flexSum, int targetSize, int flexSize) {
        int totalShrunk = 0;
        double accumulatedError = 0.0;
        int elementsWithNoShrinkage = 0;
        
        for (auto& element : elements) {
            double dx = ((element.flex_shrink * static_cast<double>(element.minSize)) / static_cast<double>(flexSize) * space);

            element.minSize = max(0, static_cast<int>(element.minSize + dx));

            targetSize -= element.minSize;
            if (!element.flex_shrink) {
                elementsWithNoShrinkage += element.minSize;
            }
        }

        if (targetSize < 0) shrinkToFit(elements, targetSize, elementsWithNoShrinkage);
    }

    void shrinkToFit(vector<BoxHelper>& elements, int overflow, int elementSum) {
        int totalShrunk = 0;
        double accumulatedError = 0.0;

        for (auto& element : elements) {
            // cout << "minsize before: " << element.minSize << endl;
            double exact = (static_cast<double>(element.minSize) / elementSum) * overflow;
            accumulatedError += exact;
            int rounded = static_cast<int>(accumulatedError);
            accumulatedError -= rounded;

            element.minSize = max(1, element.minSize + rounded);
            totalShrunk += rounded;
            // cout << "minsize currnt: " << element.minSize << endl;
        }

        int leftover = overflow - totalShrunk;
        
        if (elements.empty()) return;

        int i = 0;
        while (leftover < 0) {
            if (elements[i].minSize > 1) {
                elements[i].minSize -= 1;
                ++leftover;
            }
            i = (i + 1) % elements.size(); // wrap around
        }

        int sum = 0;
        for (int i = 0; i < elements.size(); i++)
        {
            cout << "i: " << i << " final size: " << elements[i].minSize << endl;
            sum += elements[i].minSize;
        }

        cout << "SUM: " << sum << endl;;
        
    }
}