#include "Game.hpp"
#include "Screens.hpp"

class Game;

GameScreen::GameScreen(Game &game)
    : FloweryScreen(game),
        GridUI(FloweryGrid({0.f,0.f}, {0,0}, {0,0})),
        Quit(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(ResourcesHandler.BaseFont, "Menu"), sf::Color(255, 0, 0, 255))),
        ClockUI(sf::Text(ResourcesHandler.BaseFont, "clock"))
    {
        sf::Vector2f WindowCenter = {game.GetWindowSize().x/2, game.GetWindowSize().y/2};
        
        Quit.setPosition({static_cast<float>(WindowCenter.x * 1.5 - 10), static_cast<float>(10)});
        
        Quit.MB1action = [&game](){ game.BackToMenuAction(); };
        Quit.MB2action = [](){};

        ClockUI.setPosition({10.f, 10.f});
    }

void GameScreen::OnMB1(sf::RenderWindow &GameWindow) {
    sf::Vector2i MousePosition = sf::Mouse::getPosition(GameWindow);
    std::cout << MousePosition.x << " " << MousePosition.y << "\n";
    if (this->Quit.contains({static_cast<float>(MousePosition.x), static_cast<float>(MousePosition.y)})) {
        Quit.MB1action();
    }
}

void GameScreen::HandleEvents(sf::RenderWindow &GameWindow) {
    FloweryScreen::HandleEvents(GameWindow);
    this->ClockUI.setString(this->game.ClockToString());
} 

void GameScreen::Draw() {
    this->game.drawFloweryButton(this->Quit);
    this->game.drawLabel(this->ClockUI);
    this->game.drawFloweryGrid(this->GridUI);
    //this->game.drawFloweryButton(this->CellUI);
}




