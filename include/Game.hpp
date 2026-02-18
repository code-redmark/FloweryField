#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include "FloweryComponents.hpp"
#include "Resources.hpp"
#include "Engine.hpp"
#include "Screens.hpp"

#include <string>

class FloweryScreen;

struct Game {
    private:
    int flags = 0;

    public:
    sf::RenderWindow Window;
    FloweryScreen *CurrentScreen;
    Resources ResourcesHandler;
    Engine GameEngine;
    sf::Clock FieldClock;

    int GetFlags();
    std::string ClockToString();
    std::string FlagsToCounter();

    Game();
};

namespace Global {
    inline Game Field;
    inline sf::Vector2f WindowCenter() {
        return {(float)Field.Window.getSize().x/2, (float)Field.Window.getSize().y/2};
    }
}