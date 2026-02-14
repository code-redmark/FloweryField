#pragma once

#include "SFML/Graphics.hpp"
#include <bits/stdc++.h>

#include "FloweryScreen.hpp"

class FloweryButton {
    protected:
    sf::Transformable button;
    std::function<void()> action;
    bool mouseCheck();
    public:
    FloweryButton(sf::Transformable button);

    friend FloweryScreen;
};
