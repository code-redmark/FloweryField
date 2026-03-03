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

    ScreenCollection Screens;
    FloweryScreen *CurrentScreen;

    public:
    void GameLoop();   
    
    std::string FlagsToString(); 
    std::string ClockToString(); 

    // Actions (./actions.cpp)
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
    void RevealClick(sf::Vector2i CellPosition); // Click means it comes from UI
    void FlagClick(sf::Vector2i CellPosition);

    void drawLabel(sf::Text &label);
    void drawFloweryLabel(FloweryLabel *label);
    void drawFloweryGrid(FloweryGrid &grid);

    Game();
};