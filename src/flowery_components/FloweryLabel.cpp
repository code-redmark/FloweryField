#include "Game.hpp"

FloweryLabel::FloweryLabel(sf::RectangleShape shape, sf::Text text, sf::Color FillColor, sf::Color OutlineColor)
    :   shape(shape), label(text)
    {
        this->shape.setFillColor(FillColor);
        this->shape.setOutlineColor(OutlineColor);
        this->shape.setOutlineThickness(4.f);
    }

FloweryLabel::FloweryLabel(sf::RectangleShape shape, sf::Text text, sf::Color FillColor)
    :   shape(shape), label(text)
    {
        this->shape.setFillColor(FillColor);
    }

FloweryLabel::FloweryLabel(sf::RectangleShape shape, sf::Text text)
    :   shape(shape), label(text) 
    {}




void FloweryLabel::setPosition(sf::Vector2f position) {
    this->shape.setPosition(position);
    sf::FloatRect labelBounds = this->label.getLocalBounds();
    this->label.setPosition({static_cast<float>(position.x + this->getSize().x/2 - labelBounds.size.x/2), static_cast<float>(position.y + this->getSize().y/2 - labelBounds.size.y/2)});
}

sf::Vector2f FloweryLabel::getPosition() {
    return this->shape.getPosition();
}



sf::Vector2f FloweryLabel::getSize() {
    return this->shape.getSize();
}