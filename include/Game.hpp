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

class Game {
    private:
    int flags = 0;

    public:
    sf::RenderWindow Window;
    Resources ResourcesHandler;
    std::unique_ptr<Engine> GameEngine;
    //std::unique_ptr<sf::Clock> FieldClock;

    // Screens
    ScreenCollection Screens;

    FloweryScreen *CurrentScreen;

    int GetFlags();
    //std::string ClockToString();
    std::string FlagsToCounter();

    bool isPlaying = false;

    Game();
};

namespace Global {
    inline Game Field;
    inline sf::Vector2f WindowCenter() {
        return {(float)Field.Window.getSize().x/2, (float)Field.Window.getSize().y/2};
    }
}