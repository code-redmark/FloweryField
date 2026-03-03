#include "Game.hpp"
#include "Screens.hpp"

class Game;

GameScreen::GameScreen(Game &game)
    : FloweryScreen(game),
        GridUI(FloweryGrid(game.GetWindowSize(), {0,0}, {0,0})),
        Quit(FloweryButton(FloweryLabel(sf::RectangleShape({200.f, 100.f}), sf::Text(ResourcesHandler.BaseFont, "Menu"), sf::Color(255, 0, 0, 255)))),
        ClockUI(sf::Text(ResourcesHandler.BaseFont, "clock"))
    {
        sf::Vector2f WindowCenter = {game.GetWindowSize().x/2, game.GetWindowSize().y/2};
        
        GridUI.setPosition({WindowCenter.x - GridUI.getSize().x/2, WindowCenter.y - GridUI.getSize().y/2});

        Quit.setPosition({static_cast<float>(WindowCenter.x * 1.5 - 10), static_cast<float>(10)});
        
        Quit.MB1action = [&game](){ game.BackToMenuAction(); };
        Quit.MB2action = [](){};

        ClockUI.setPosition({10.f, 10.f});
    }

void GameScreen::OnMB1(sf::RenderWindow &GameWindow) {
    sf::Vector2f MousePosition = {static_cast<float>(sf::Mouse::getPosition(GameWindow).x), static_cast<float>(sf::Mouse::getPosition(GameWindow).y)};

    if (this->GridUI.contains(MousePosition)) {
        this->game.RevealClick(this->GridUI.ScreenPosToCell({MousePosition.x, MousePosition.y}));
    }

    if (this->Quit.contains(MousePosition)) {
        Quit.MB1action();
    }
}

void GameScreen::OnMB2(sf::RenderWindow &GameWindow) {
    sf::Vector2f MousePosition = {static_cast<float>(sf::Mouse::getPosition(GameWindow).x), static_cast<float>(sf::Mouse::getPosition(GameWindow).y)};

    if (this->GridUI.contains(MousePosition)) {

    }

}

void GameScreen::HandleEvents(sf::RenderWindow &GameWindow) {
    FloweryScreen::HandleEvents(GameWindow);
    this->ClockUI.setString(this->game.ClockToString());
} 

void GameScreen::Draw() {
    this->game.drawFloweryLabel(&this->Quit);
    this->game.drawLabel(this->ClockUI);
    this->game.drawFloweryGrid(this->GridUI);
}




