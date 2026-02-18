#include "Game.hpp"

using namespace Global;

Game::Game() 
    :   Window(sf::RenderWindow(sf::VideoMode({800, 600}), "Flowery Field++", sf::Style::Titlebar | sf::Style::Close)),
        ResourcesHandler(Resources()),
        GameEngine(nullptr), // Initialized when play is pressed
        Screens(ScreenCollection()),
        CurrentScreen(&Field.Screens.Menu)
    {}

// std::string Game::ClockToString() {
//     char buffer[9]; // 2 digits for hours, 2 for mins, 2 for secs + 2 columns + null terminator
//     int seconds = static_cast<int>(Field.FieldClock->getElapsedTime().asSeconds());
//     snprintf(buffer, sizeof(buffer),"%02d:%02d:%02d", seconds/3600, seconds/60 % 60, seconds % 60);
//     return buffer;
// }

std::string Game::FlagsToCounter() {
    char buffer[3];
    sprintf(buffer, "%02d", Global::Field.GetFlags());
    return buffer;
}

int Game::GetFlags() {
    return this->flags;
}

