#include "Game.hpp"
#include "FloweryComponents.hpp"


FloweryButton::FloweryButton(sf::RectangleShape shape, sf::Text text)
    :   shape(shape),
        label(text)
        {}

void FloweryButton::draw() {
    Global::Field.Window.draw(this->shape);
    Global::Field.Window.draw(this->label);   
}

void FloweryButton::setPosition(sf::Vector2f position) {
    this->shape.setPosition(position);
    this->label.setPosition(position);
}

bool FloweryButton::contains(sf::Vector2f pos) {
    return this->shape.getGlobalBounds().contains(pos);
}


