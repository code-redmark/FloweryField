#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Game.hpp"

#include <iostream>

FloweryScreen::FloweryScreen(Game &game) : game(game) {}


void FloweryScreen::Draw(sf::RenderWindow &GameWindow) {
    std::cout << "Draw\n";
}

void FloweryScreen::HandleEvents(sf::RenderWindow &GameWindow) { // Base events
    while (std::optional<sf::Event> event = GameWindow.pollEvent())
    if (event->is<sf::Event::Closed>()) {
        GameWindow.close();
    }
}

void FloweryScreen::OnMB1() { 
    sf::Vector2i winPos = this->game.GetWindowPos();
    sf::Vector2f winSize = this->game.GetWindowSize();
    if ((winPos.x >= 0 && winPos.x < winSize.x) && (winPos.y >= 0 && winPos.y < winSize.y)) {
        std::cout << "Mouse clicked and is in window!";
    }
}
