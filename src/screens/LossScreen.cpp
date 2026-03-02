#include "Game.hpp"
#include "Screens.hpp"

class Game;

LossScreen::LossScreen(Game &game, FloweryGrid grid)
    : FloweryScreen(game),
        grid(grid),
        Menu(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(ResourcesHandler.BaseFont, "Quit"), sf::Color(255, 0, 0, 255))),
        PlayAgain(FloweryButton(sf::RectangleShape({400.f, 100.f}), sf::Text(ResourcesHandler.BaseFont, "Play Again"), sf::Color(0, 200, 20, 255))),
        YouLose(sf::Text(ResourcesHandler.BaseFont, "You Lost!"))
    {
        sf::Vector2f WindowSize = game.GetWindowSize();
        sf::Vector2f WindowCenter = {WindowSize.x/2, WindowSize.y/2};

        grid.setPosition({WindowCenter.x - grid.getSize().x/2, WindowCenter.y - grid.getSize().y/2});

        const float padding = WindowSize.x / 100;
        const float ButtonsLength = Menu.getSize().x + padding + PlayAgain.getSize().x;
        
        YouLose.setPosition({WindowCenter.x - YouLose.getLocalBounds().size.x/2, WindowCenter.y - WindowCenter.y/2});

        Menu.setPosition({WindowCenter.x - ButtonsLength/2, WindowCenter.y});
        Menu.MB1action = [&game](){ game.BackToMenuAction(); };
        Menu.MB2action = [](){};

        PlayAgain.setPosition({this->Menu.getPosition().x + this->Menu.getSize().x + padding, WindowCenter.y});
        PlayAgain.MB1action = [&game](){ game.NewGameAction(); };
        PlayAgain.MB2action = [&game](){};

    }

void LossScreen::OnMB1(sf::RenderWindow &GameWindow) {
    sf::Vector2f MousePosition = {static_cast<float>(sf::Mouse::getPosition(GameWindow).x), static_cast<float>(sf::Mouse::getPosition(GameWindow).y)};
    if (this->Menu.contains(MousePosition)) {
        Menu.MB1action();
    } else if (this->PlayAgain.contains(MousePosition)) {
        this->PlayAgain.MB1action();
    }
}

void LossScreen::Draw() {
    this->game.drawFloweryButton(this->Menu);
    this->game.drawFloweryButton(this->PlayAgain);
    this->game.drawLabel(this->YouLose);
    this->game.drawFloweryGrid(this->grid);
}



