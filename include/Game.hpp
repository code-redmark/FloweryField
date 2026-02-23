#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include "FloweryComponents.hpp"
#include "Resources.hpp"
#include "Engine.hpp"
#include "Screens.hpp"
#include "ScreenCollection.hpp"

#include <string>

class FloweryScreen;



class Game {
    private:

    sf::RenderWindow Window;
    std::unique_ptr<Engine> GameEngine;
    //std::unique_ptr<sf::Clock> FieldClock;

    // Screens
    ScreenCollection Screens;
    FloweryScreen *CurrentScreen;

    public:
    int GetFlags();
    std::string FlagsToCounter();
    //std::string ClockToString();

    

    void GameLoop(); // Start game function

    // Actions
    void NewGameAction(); // Reinitializes engine and GameScreen components
    void QuitAction();
    void BackToMenuAction();
    // void RevealAction();
    // void FlagAction();

    // Window functions
    inline sf::Vector2i WindowPosition(sf::Vector2i position) { // Returns the given position relative to the game's window
        return position - this->Window.getPosition();
    } 
    sf::Vector2i GetWindowPos();
    sf::Vector2f GetWindowSize();

    void drawLabel(sf::Text &label);
    void drawFloweryButton(FloweryButton &button);

    Game();
};