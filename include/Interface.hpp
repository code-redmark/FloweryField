#pragma once

#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

#include <iostream>
#include <string>
#include <memory>
#include <bits/stdc++.h>
#include <vector>
#include <random>
#include <array>

const sf::Color CELL_COLOR = sf::Color(220, 205, 215, 165);
const sf::Color CELL_OUTLINE = sf::Color(180, 170, 175, 204);

class FloweryScreen;
class FloweryButton;
struct SweeperGrid;

class FloweryScreen { // Main screen class
    private:
    GameEngine &engine;
    sf::RenderWindow &window;
    std::vector<FloweryButton> buttons;
    std::vector<sf::Text> labels;

    void drawMenu();
    void drawGame();

    public:
    FloweryScreen(sf::RenderWindow &win, GameEngine engine);

    void draw(); // Draw screen corresponding to current state

    // Events
    void OnMB1(); // On left mouse button click
    
};

class FloweryButton {
    private:
    GameState priority; // What screen (GameState) does this button belong to?

    sf::Transformable button;
    std::function<void()> action;

    bool mouseCheck();
    public:
    FloweryButton(sf::Transformable button, GameState priority);
    friend FloweryScreen;
};

struct SweeperGrid {
    std::vector<FloweryButton> cells;

    SweeperGrid(sf::Transformable Container); // Makes grid out of container
};