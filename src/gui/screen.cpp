#include "Interface.hpp"


FloweryScreen::FloweryScreen(sf::RenderWindow &win, GameEngine engine)
    : window(win), engine(engine) {}



void FloweryScreen::draw() {
    switch (this->engine.getState()) {
        case Menu:
            this->drawMenu();
            break;
        case Game:
            this->drawGame();
            break;
    }
}

void FloweryScreen::drawMenu() {

}

void FloweryScreen::drawGame() {}

void FloweryScreen::OnMB1() {

    // Check buttons
    for (int i = 0; i < this->buttons.size(); i++) {
        if (buttons[i].priority == this->engine.getState()) {
            if (buttons[i].mouseCheck()) {
            }
        } 
    }
}


