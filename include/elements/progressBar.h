#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H
#include "node.h"

enum Direction {
    SOUTH, NORTH, WEST, EAST
};
class ProgressBar : public Node {
private:
    float _progress;
    Direction _direction;

    void renderLateral(Bitmap& map, bool inversed);
    void renderVertical(Bitmap& map, bool inversed);
public:
    ProgressBar(float, Direction);
    ProgressBar(Size, float, Direction);

    void computeRequirement() override;
    void ComputeMinSize() override;
    void layout(Box&) override;
    void render(Bitmap&) override; 
    int getLayer() const override;
};

#endif