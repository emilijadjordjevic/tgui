#ifndef TEXT_LABEL_H
#define TEXT_LABEL_H

#include "elements/node.h"
#include <iostream>
using namespace std;

class TextLabel : public Node {
private:
    string _content;
    vector<string> _lines;
public:
    TextLabel(string);

    void computeRequirement() override;
    void ComputeMinSize() override;
    void render(Bitmap&) override;
    int getLayer() const override;
    void splitLines();
    vector<string> splitLinesWithHConstraint(int size);
    vector<string> splitLinesWithVConstraint(int size);
};

#endif