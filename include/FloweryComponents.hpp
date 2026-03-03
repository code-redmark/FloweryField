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

class FloweryLabel {
    protected:
    sf::RectangleShape shape;
    sf::Text label;
    
    public:
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);
    
    sf::Vector2f getSize();
    
    FloweryLabel(sf::RectangleShape shape, sf::Text text);
    FloweryLabel(sf::RectangleShape shape, sf::Text text, sf::Color FillColor);
    FloweryLabel(sf::RectangleShape shape, sf::Text text, sf::Color FillColor, sf::Color OutlineColor);

    friend Game;
};


class FloweryButton : public FloweryLabel {
    public:
    FloweryButton(FloweryLabel label);

    std::function<void()> MB1action;
    std::function<void()> MB2action;

    bool contains(sf::Vector2f pos);

    friend Game;
};

class FloweryGrid {
    private:
    sf::Vector2i CurrentGameSize;
    float cellLength;
    float cellHeight;

    sf::RectangleShape RevealedTemplate; // Revealed cell RectangleShape
    std::vector<FloweryLabel> RevealedCells;

    std::vector<sf::Sprite> BombSprites;

    sf::RectangleShape GridShape;
    std::vector<sf::RectangleShape> GridLines;

    public:
    FloweryGrid(sf::Vector2f WindowSize, sf::Vector2i WindowPos, sf::Vector2i GameSize);
    
    sf::Vector2f getSize();
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();

    void ReloadGrid(sf::Vector2i GameSize); // Reinitializes the grid's interface
    
    bool contains(sf::Vector2f pos);
    sf::Vector2i ScreenPosToCell(sf::Vector2f pos); // Returns the coordinates of the cell in a specific position on the grid, its used by GameEngine to know which cell to reveal/flag

    void AddRevealed(sf::Vector2i CellPosition, int around); // Creates a revealed cell rectangle at specified position

    friend Game;
};



