#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Game.hpp"
#include "FloweryComponents.hpp"

#include <iostream>

FloweryScreen::FloweryScreen() {}


void FloweryScreen::Show() {}

void FloweryScreen::HandleEvents() {}

void FloweryScreen::OnMB1() { 
    sf::Vector2i winPos = Global::Field.Window.getPosition();
    if ((winPos.x >= 0 && winPos.x < Global::Field.Window.getSize().x) && (winPos.y >= 0 && winPos.y < Global::Field.Window.getSize().y)) {
        std::cout << "Mouse clicked and is in window!";
    }
}
