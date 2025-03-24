#ifndef TEXT_METRICS_H
#define TEXT_METRICS_H

#include <string>
#include "Size.h"
#include <vector>

class TextMetrics {
public: 
    static Size computeTextSize(const string&);
    static Size computeTextSize(const string&, int);
    static int computeLargestWord(const string&); 
    static int computeHeight(const string&, int);
    static bool newLine(char);
    static vector<string> splitLines(const string&);
    static vector<string> splitLines(const string&, int);
    vector<string> TextMetrics::splitLinesCaller(const string &text, int width = -1) const;
};

#endif