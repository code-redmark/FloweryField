#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

#include <memory>
#include <bits/stdc++.h>

#pragma once

enum GameState {
    Menu = 1,
    Game = 2,
};

class FloweryScreen {
    private:
    sf::RenderWindow &window;
    std::vector<FloweryButton> buttons; // Keeps active buttons

    GameState state;
    void drawMenu();
    void drawGame();

    public:
    FloweryScreen(sf::RenderWindow &win);
    void draw(); // Draw the game's specific interfaces
    GameState getState();
    void OnMouseClick();
    
};

class FloweryButton {
    private:
    GameState priority; // What screen does this button belong to?
    std::unique_ptr<sf::Transformable> button; // Pointers make you use contain derived classes by just making base class pointers
    std::function<void()> action;
    bool mouseCheck();
    public:
    FloweryButton(sf::Transformable &item, GameState priority);
    
    friend FloweryScreen;
};