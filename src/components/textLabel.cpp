#include "components/TextLabel.h"

TextLabel::TextLabel(Size size, string text) : UIComponent(size), text(text) {}

TextLabel::~TextLabel() {}

void TextLabel::calculateRequiredSize() {
    // this->requiredSize = TextMetrics::computeTextSize(this->text);
    // this->largestWord = TextMetrics::computeLargestWord(this->text);
    // int reqWidth = calculateRequiredWidth();
    // requiredSize = Size(reqWidth, TextMetrics::computeHeight(text, reqWidth));
    requiredSize = ( isPrefSizeSet() ) ? TextMetrics::computeTextSize(this->text, prefferedSize.getWidth()) : TextMetrics::computeTextSize(this->text);
}

void TextLabel::setPositionOnScreen(Position p, DisplayGrid& grid) {
    auto lines = TextMetrics::splitLines(text, requiredSize.getWidth());

    for (size_t i = 0; i < lines.size(); i++)
    {
        Position linePos(p.getX(), p.getY() + i);
        placeLine(lines[i], linePos, grid);
    }
}


int TextLabel::getLargestWordSize() const {
    return this->largestWord;
}

void TextLabel::setSizeCalculation(SizeCalculation* sc) {
    this->sizeCalculation = sc;
}


