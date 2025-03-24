#include "components/uiComponent.h"

Size UIComponent::getRequiredSize() const {
    return this->requiredSize;
}

UIComponent::~UIComponent() {}

UIComponent::UIComponent()  {}

UIComponent::UIComponent(Size size) : prefferedSize(size) {}

void UIComponent::setPrefferedSize(Size newSize) {
    this->prefferedSize = newSize;
}

void UIComponent::setPrefferedWidth(int w) {
    this->prefferedSize = Size(w, prefferedSize.getHeight());
}

void UIComponent::setPrefferedHeight(int h) {
    this->prefferedSize = Size(prefferedSize.getWidth(), h);
}

bool UIComponent::isPrefSizeSet() const {
}

void UIComponent::setPosition(Position p) {
    this->position = p;
}

Position UIComponent::getPosition() const {
    return this->position;
}