#include "Game.hpp"

Game::Game() 
    :   Window(sf::RenderWindow(sf::VideoMode({640, 480}), "Flowery Field++")),
        ResourcesHandler(Resources()),
        GameEngine(Engine(9, 9))
    {}