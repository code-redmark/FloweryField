#pragma once

class Game;

class MenuScreen : public FloweryScreen {
    private:
    sf::Font BaseFont;
    sf::Text GameTitle;
    FloweryButton Play;
    FloweryButton Exit;

    void OnMB1(sf::RenderWindow &GameWindow) override;

    public:
    MenuScreen(Game &game);
    void Draw() override;
};

class GameScreen : public FloweryScreen {
    private:
    FloweryGrid GridUI;
    //FloweryButton CellUI;
    FloweryButton Quit;
    sf::Text ClockUI;

    void OnMB1(sf::RenderWindow &GameWindow) override;
    void OnMB2(sf::RenderWindow &GameWindow) override; // To override with flag tag


    public:
    void HandleEvents(sf::RenderWindow &GameWindow) override; // Overriding for clock
    GameScreen(Game &game);
    void Draw() override;

    friend Game;

};

class LossScreen : public FloweryScreen {
    private:
    FloweryGrid grid;
    sf::Text YouLose;
    FloweryButton Menu;
    FloweryButton PlayAgain;

    void OnMB1(sf::RenderWindow &GameWindow) override;

    public:
    LossScreen(Game &game, FloweryGrid grid);
    void Draw() override;

    friend Game;
};


