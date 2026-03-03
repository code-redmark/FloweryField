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
    virtual void OnMB2(sf::RenderWindow &GameWindow) {}

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
    sf::Vector2i CurrentGameSize;
    float cellLength;
    float cellHeight;

    sf::RectangleShape RevealedTemplate; // Revealed cell RectangleShape
    std::vector<sf::RectangleShape> RevealedCells;

    std::vector<sf::Sprite> BombSprites;

    sf::RectangleShape GridShape;
    std::vector<sf::RectangleShape> GridLines;

    public:
    FloweryGrid(sf::Vector2f WindowSize, sf::Vector2i WindowPos, sf::Vector2i GameSize);
    
    sf::Vector2f getSize();
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();

    void ReloadGrid(sf::Vector2i GameSize); // Reinitializes the grid's shape
    
    bool contains(sf::Vector2f pos);
    sf::Vector2i ScreenPosToCell(sf::Vector2f pos); // Returns the coordinates of the cell in a specific position on the grid, its used by GameEngine to know which cell to reveal/flag

    void AddRevealed(sf::Vector2i CellPosition); // Creates a revealed cell rectangle at specified position

    friend Game;
};



