#include "Screen.hpp"

SweeperScreen::SweeperScreen(sf::RenderWindow &win) 
    : window(win), state(Menu) {}

GameState SweeperScreen::getState() {
    return this->state;
}

void SweeperScreen::draw() {
    switch (this->state) {
        case Menu:
            this->drawMenu();
            break;
        case Game:
            this->drawGame();
            break;
    }
}

void SweeperScreen::drawMenu() {

    sf::RenderStates states;

    sf::RectangleShape rect({200.f, 100.f});
    rect.setPosition(sf::Vector2f(this->window.getSize().x / 2, this->window.getSize().y / 2));

    this->window.draw(rect, states.transform.translate(sf::Vector2f()));

}
void SweeperScreen::drawGame() {}