#pragma once

#include "Game.hpp"
#include "Screens.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

#include <memory>
#include <bits/stdc++.h>
#include <vector>
#include <random>

class FloweryScreen { // Base screen class, doesn't show anything
    private:
    GameEngine &engine;
    sf::RenderWindow &window;

    protected:
    virtual void OnMB1(); // On left mouse button click

    public:
    FloweryScreen(sf::RenderWindow &win, GameEngine engine);
    virtual void HandleEvents();
    virtual void Show();

};


