#pragma once

class Game;

class MenuScreen : public FloweryScreen {
    private:
    sf::Font BaseFont;
    sf::Text GameTitle;
    FloweryButton Play;
    FloweryButton Exit;

    void OnMB1() override;
    void OnMB2() override {}

    public:
    MenuScreen(Game &game);
    void HandleEvents(sf::RenderWindow &GameWindow) override;
    void Draw(sf::RenderWindow &GameWindow) override;
};

// class GameScreen : public FloweryScreen {
//     private:
//     //sf::Text TimeCounter;
//     sf::Text FlagCounter;
//     FloweryButton RestartButton;
//     FloweryButton QuitButton;
//     //std::vector<FloweryButton> grid;

//     void OnMB1() override;
//     void OnMB2() override;

//     public:
//     GameScreen();
//     void HandleEvents() override;
//     void Show() override;
// };


