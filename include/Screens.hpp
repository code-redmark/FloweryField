#pragma once

#include "FloweryComponents.hpp"

class MenuScreen : public FloweryScreen {
    private:
    sf::Font BaseFont;
    sf::Text GameTitle;
    FloweryButton Play;
    FloweryButton Exit;

    void OnMB1() override;
    void OnMB2() override {}

    public:
    MenuScreen();
    void HandleEvents() override;
    void Show() override;
};

class GameScreen : public FloweryScreen {
    private:
    sf::Text TimeCounter;
    sf::Text FlagCounter;

    void OnMB1() override;
    void OnMB2() override;

    public:
    GameScreen();
    void HandleEvents() override;
    void Show() override;
};


