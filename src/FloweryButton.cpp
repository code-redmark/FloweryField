#include "Game.hpp"
#include "FloweryComponents.hpp"


FloweryButton::FloweryButton(sf::RectangleShape shape, sf::Text text, sf::Color color)
    :   shape(shape),
        label(text)
        {
            this->shape.setFillColor(color);
        }

void FloweryButton::setPosition(sf::Vector2f position) {
    this->shape.setPosition(position);
    this->label.setPosition(position);
}

sf::Vector2f FloweryButton::getPosition() {
    return this->shape.getPosition();
}

bool FloweryButton::contains(sf::Vector2f pos) {
    return this->shape.getGlobalBounds().contains(pos);
}

sf::Vector2f FloweryButton::getSize() {
    return this->shape.getSize();
}


