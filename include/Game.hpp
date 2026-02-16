#pragma once

#include "SFML/Graphics.hpp"
#include "FloweryScreen.hpp"
#include "Resources.hpp"
#include "Engine.hpp"

class Game {
    public:
    sf::RenderWindow Window;
    FloweryScreen *CurrentScreen;
    Resources ResourcesHandler;
    Engine GameEngine;
    Game();
};

namespace Global {
    inline Game Field;
}