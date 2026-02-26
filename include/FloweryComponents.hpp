#pragma once

#include <SFML/Graphics.hpp>

class MenuScreen;
class GameScreen;

class Game;

#include <bits/stdc++.h>



class FloweryScreen { // Base screen class, doesn't show anything        
    protected:
    Game &game;

    virtual void OnMB1(sf::RenderWindow &GameWindow); // On left mouse button click
    virtual void OnMB2() {}

    public:
    FloweryScreen(Game &game);
    virtual void HandleEvents(sf::RenderWindow &GameWindow);
    virtual void Draw();
};



class FloweryButton {
    private: 
    sf::Text label;
    sf::RectangleShape shape;
    
    public:
    FloweryButton(sf::RectangleShape shape, sf::Text text); // Makes a white button
    FloweryButton(sf::RectangleShape shape, sf::Text text, sf::Color FillColor); // Makes a button of given fill color
    FloweryButton(sf::RectangleShape shape, sf::Text, sf::Color FillColor, sf::Color OutlineColor); // Makes a button of given fill color and outline color
    
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    
    bool contains(sf::Vector2f pos);

    std::function<void()> MB1action;
    std::function<void()> MB2action;

    sf::Vector2f getSize();

    friend Game;

};

class FloweryGrid {
    private:
    sf::RectangleShape GridShape;
    std::vector<sf::RectangleShape> GridLines;
    
    public:
    FloweryGrid(sf::Vector2f WindowSize, sf::Vector2i WindowPos, sf::Vector2i GameSize);
    void ReloadGrid(sf::Vector2i GameSize);

    bool contains(sf::Vector2f pos);
    sf::Vector2i getCellinPosition(); // Returns the coordinates of the cell in a specific position on the grid, its used by GameEngine to know which cell to reveal/flag


    friend Game;
};



