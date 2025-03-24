#include "naturalSizeCalculation.h"
#include "textMetrics.h"

Size NaturalSizeCalculation::calculateSize(const string& text, int width = -1) const {
    // Size textSize = TextMetrics::computeTextSize(text);
    // int largestWord = TextMetrics::computeLargestWord(text);
    // int reqWidth = max(textSize.getWidth(), largestWord);
    // return Size(reqWidth, TextMetrics::computeHeight(text, reqWidth));
    return TextMetrics::computeTextSize(text);
}

