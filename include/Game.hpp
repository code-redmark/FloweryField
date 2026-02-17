#pragma once

#include "SFML/Graphics.hpp"

#include "Resources.hpp"
#include "Engine.hpp"

class FloweryScreen;

struct Game {
    sf::RenderWindow Window;
    FloweryScreen *CurrentScreen;
    Resources ResourcesHandler;
    Engine GameEngine;
    
    Game();
};

namespace Global {
    inline Game Field;
    inline sf::Vector2f WindowCenter() {
        return {(float)Field.Window.getSize().x/2, (float)Field.Window.getSize().y/2};
    }
}