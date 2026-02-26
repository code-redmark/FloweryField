#include "Game.hpp"
#include "FloweryComponents.hpp"

FloweryButton::FloweryButton(sf::RectangleShape shape, sf::Text text, sf::Color FillColor, sf::Color OutlineColor)
    :   shape(shape), label(text)
    {
        this->shape.setFillColor(FillColor);
        this->shape.setOutlineColor(OutlineColor);
        this->shape.setOutlineThickness(4.f);
    }

FloweryButton::FloweryButton(sf::RectangleShape shape, sf::Text text, sf::Color FillColor)
    :   shape(shape), label(text)
    {
        this->shape.setFillColor(FillColor);
    }

FloweryButton::FloweryButton(sf::RectangleShape shape, sf::Text text)
    :   shape(shape), label(text) 
    {}

void FloweryButton::setPosition(sf::Vector2f position) {
    this->shape.setPosition(position);
    sf::FloatRect labelBounds = this->label.getLocalBounds();
    this->label.setPosition({static_cast<float>(position.x + this->getSize().x/2 - labelBounds.size.x/2), static_cast<float>(position.y + this->getSize().y/2 - labelBounds.size.y/2)});
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


