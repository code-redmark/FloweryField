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
    void GameLoop(); // Start game function    
    
    std::string FlagsToString(); // Returns the game's engine flags value as a string
    std::string ClockToString(); // Returns the game's engine sf::Clock value as a string

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


    // Engine functions
    sf::Vector2i GetEngineSize();

    void drawLabel(sf::Text &label);
    void drawFloweryButton(FloweryButton &button);
    void drawFloweryGrid(FloweryGrid &grid);

    Game();
};