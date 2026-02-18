#pragma once

#include <SFML/Graphics.hpp>

class MenuScreen;
class GameScreen;

#include <bits/stdc++.h>



class FloweryScreen { // Base screen class, doesn't show anything    
    protected:
    virtual void OnMB1(); // On left mouse button click
    virtual void OnMB2() {}

    public:
    FloweryScreen();
    virtual void HandleEvents();
    virtual void Show();
};



class FloweryButton {
    private: 
    sf::Text label;
    sf::RectangleShape shape;
    
    public:
    FloweryButton(sf::RectangleShape shape, sf::Text text);
    void setPosition(sf::Vector2f position);
    void draw();
    bool contains(sf::Vector2f pos);
    std::function<void()> MB1action;
    std::function<void()> MB2action;

    friend FloweryScreen;
    friend MenuScreen;
    friend GameScreen;

};



