#ifndef HBOX_H
#define HBOX_H

#include "elements/container.h"

class HBox : public IContainer {
public:
    HBox(Size);
    HBox(Elements);
    HBox(Size, Elements);

    void computeRequirement() override;
    // void ComputeMinSize() override;
    void layout(Box&) override;
};

#endif