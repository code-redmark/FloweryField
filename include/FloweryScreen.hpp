#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

#include <memory>
#include <vector>
#include <random>

class FloweryScreen { // Base screen class, doesn't show anything    
    protected:
    virtual void OnMB1(); // On left mouse button click
    virtual void OnMB2() {}

    public:
    FloweryScreen();
    virtual void HandleEvents();
    virtual void Show();
};


