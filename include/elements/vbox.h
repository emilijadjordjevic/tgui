#ifndef VBOX_H
#define VBOX_H

#include "elements/container.h"

class VBox : public IContainer {
public:
    VBox(Size);
    VBox(Elements);
    VBox(Size, Elements);

    void computeRequirement() override;
    void layout(Box&) override;
};

#endif