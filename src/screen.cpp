#include "Screen.hpp"


FloweryScreen::FloweryScreen(sf::RenderWindow &win)
    : window(win), state(Menu) {}

GameState FloweryScreen::getState() {
    return this->state;
}

void FloweryScreen::draw() {
    switch (this->state) {
        case Menu:
            this->drawMenu();
            break;
        case Game:
            this->drawGame();
            break;
    }
}

void FloweryScreen::drawMenu() {
    sf::RectangleShape rect(sf::Vector2f(100, 200));
    rect.setFillColor(sf::Color::Red);
    rect.setOrigin(rect.getSize() / 2.f);
    rect.setPosition(sf::Vector2f(this->window.getSize().x / 2.f, this->window.getSize().y / 2.f));

    this->window.draw(rect);
}

void FloweryScreen::drawGame() {}


void FloweryScreen::OnMouseClick() {
    for (int i = 0; i < this->buttons.size(); i++) {
        if (buttons[i].priority == this->state) {
            if (buttons[i].mouseCheck()) {
                
            }
        } 
    }
}



FloweryButton::FloweryButton(sf::Transformable &item, GameState priority) 
    : button(&item), priority(priority) {}

bool FloweryButton::mouseCheck() {
    // Get mouse position
    sf::Vector2i mouse = sf::Mouse::getPosition();
    sf::Vector2f button = this->button->getPosition();

    if ((mouse.x > button.x && mouse.x < button.x + this->button->getScale().x) && (mouse.y > button.y && mouse.y < button.y + this->button->getScale().y)) {
        return true;
    } else return false;
}