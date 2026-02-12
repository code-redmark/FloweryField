#include "Interface.hpp"

FloweryButton::FloweryButton(sf::Transformable item, GameState priority) 
    : priority(priority), button(item) {}

bool FloweryButton::mouseCheck() {
    // Get mouse position
    sf::Vector2i mouse = sf::Mouse::getPosition();
    sf::Vector2f button = this->button.getPosition();
    return (mouse.x > button.x && mouse.x < button.x + this->button.getScale().x) && (mouse.y > button.y && mouse.y < button.y + this->button.getScale().y);
}