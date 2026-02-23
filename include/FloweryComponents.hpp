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
    void HandleEvents(sf::RenderWindow &GameWindow);
    virtual void Draw();
};



class FloweryButton {
    private: 
    sf::Text label;
    sf::RectangleShape shape;
    
    public:
    FloweryButton(sf::RectangleShape shape, sf::Text text, sf::Color color);
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    bool contains(sf::Vector2f pos);

    std::function<void()> MB1action;
    std::function<void()> MB2action;

    sf::Vector2f getSize();

    friend Game;

};



