#pragma once

#include "FloweryScreen.hpp"
#include "FloweryButton.hpp"
#include "Style.hpp"

#include <filesystem>

class MenuScreen : public FloweryScreen {
    private:
    sf::Font BaseFont;
    sf::Text GameTitle;
    FloweryButton Play;
    FloweryButton Exit;

    void OnMB1() override;

    public:
    MenuScreen(sf::RenderWindow &win, GameEngine engine);
    void Show() override;
};

class GameScreen : public FloweryScreen {
    private:
    sf::Font BaseFont;
    sf::Text TimeCounter;
    sf::Text FlaggedCounter;
    std::vector<FloweryButton> Cells;

    void OnMB1() override;

    public:
    GameScreen(sf::RenderWindow &win, GameEngine engine);
    void Show() override;
};

