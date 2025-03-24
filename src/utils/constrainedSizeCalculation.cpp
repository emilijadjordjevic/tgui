#include "constrainedSizeCalculation.h"
#include "textMetrics.h"

Size ConstrainedSizeCalculation::calculateSize(const string& text, int width) const {
    Size textSize = TextMetrics::computeTextSize(text);
    int largestWord = TextMetrics::computeLargestWord(text);
    if (textSize.getWidth() < width) {
        width = textSize.getWidth();
    }
    int reqWidth = max(largestWord, width);

    return Size(reqWidth, TextMetrics::computeHeight(text, reqWidth));
}

