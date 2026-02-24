#pragma once

class Game;

class MenuScreen : public FloweryScreen {
    private:
    sf::Font BaseFont;
    sf::Text GameTitle;
    FloweryButton Play;
    FloweryButton Exit;

    void OnMB1(sf::RenderWindow &GameWindow) override;
    void OnMB2() override {}

    public:
    MenuScreen(Game &game);
    void Draw() override;
};

class GameScreen : public FloweryScreen {
    private:
    FloweryButton CellUI;
    FloweryButton Quit;
    sf::Text ClockUI;

    void OnMB1(sf::RenderWindow &GameWindow) override;
    void OnMB2() override {} // To override with flag tag


    public:
    void HandleEvents(sf::RenderWindow &GameWindow) override; // Overriding for clock
    GameScreen(Game &game);
    void Draw() override;
};


