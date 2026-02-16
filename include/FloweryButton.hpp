#pragma once

#include <bits/stdc++.h>

class FloweryButton {
    private: 
    sf::Text &label;

    sf::Shape &shape;
    
    public:
    FloweryButton(sf::RectangleShape shape, sf::Text text);
    void draw();
    bool contains(sf::Vector2f pos);
    std::function<void()> MB1action;
    std::function<void()> MB2action;

};
