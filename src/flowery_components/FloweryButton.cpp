#include "Game.hpp"
#include "FloweryComponents.hpp"

FloweryButton::FloweryButton(FloweryLabel label) 
    : FloweryLabel(label) {}

bool FloweryButton::contains(sf::Vector2f pos) {
    return this->shape.getGlobalBounds().contains(pos);
}


