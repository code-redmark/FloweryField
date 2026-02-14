#include "FloweryScreen.hpp"

FloweryScreen::FloweryScreen(sf::RenderWindow &win, GameEngine engine)
    : window(win), engine(engine) {}


void FloweryScreen::Show() {}

void FloweryScreen::HandleEvents() {

}

void FloweryScreen::OnMB1() { 
    sf::Vector2i winPos = this->window.getPosition();
    if ((winPos.x >= 0 && winPos.x < this->window.getSize().x) && (winPos.y >= 0 && winPos.y < this->window.getSize().y)) {
        std::cout << "Mouse clicked and is in window!";
    }
}
