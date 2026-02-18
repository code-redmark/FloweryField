#include "Game.hpp"

using namespace Global;

Game::Game() 
    :   Window(sf::RenderWindow(sf::VideoMode({800, 600}), "Flowery Field++", sf::Style::Titlebar | sf::Style::Close)),
        ResourcesHandler(Resources()),
        GameEngine(Engine(9, 9))
    {} // Current screen is initialized in main

std::string Game::ClockToString() {
    char buffer[6];
    int seconds = static_cast<int>(Field.FieldClock.getElapsedTime().asSeconds());
    sprintf(buffer, "%02d:%02d", seconds/60, seconds%60);
    return buffer;
}

std::string Game::FlagsToCounter() {
    char buffer[3];
    sprintf(buffer, "%02d", Global::Field.GetFlags());
    return buffer;
}

int Game::GetFlags() {
    return this->flags;
}

