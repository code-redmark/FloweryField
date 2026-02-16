#include "Game.hpp"

Game::Game() 
    :   Window(sf::RenderWindow(sf::VideoMode(sf::Vector2u(640, 480)), "Flowery Field++")),
        ResourcesHandler(Resources()),
        GameEngine(Engine(9, 9))
    {}