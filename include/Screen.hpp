#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

#pragma once

enum GameState {
    Menu = 1,
    Game = 2,
};

class SweeperScreen {

    private:
    sf::RenderWindow &window;
    GameState state;
    void drawMenu();
    void drawGame();

    public:
    SweeperScreen(sf::RenderWindow &win);
    void draw(); // Draw the game's specific interfaces
    GameState getState();


};