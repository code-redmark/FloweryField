#include "Game.hpp"
#include "Screens.hpp"

class Game;

LossScreen::LossScreen(Game &game, FloweryGrid grid)
    : FloweryScreen(game),
        grid(grid),
        Menu(FloweryButton(FloweryLabel(sf::RectangleShape({200.f, 100.f}), sf::Text(ResourcesHandler.BaseFont, "Quit"), sf::Color(255, 0, 0, 255)))),
        PlayAgain(FloweryButton(FloweryLabel(sf::RectangleShape({400.f, 100.f}), sf::Text(ResourcesHandler.BaseFont, "Play Again"), sf::Color(0, 200, 20, 255)))),
        YouLose(sf::Text(ResourcesHandler.BaseFont, "You Lost!"))
    {
        sf::Vector2f WindowSize = game.GetWindowSize();
        sf::Vector2f WindowCenter = {WindowSize.x/2, WindowSize.y/2};

        this->gridPosition = {WindowSize.x * 0.01f, WindowCenter.y - grid.getSize().x/2};

        const float padding = WindowSize.x / 100;
        const float ButtonsLength = Menu.getSize().x + padding + PlayAgain.getSize().x;
        
        Menu.setPosition({(gridPosition.x + grid.getSize().x) * 1.3f, WindowCenter.y});
        Menu.MB1action = [&game](){ game.BackToMenuAction(); };
        Menu.MB2action = [](){};

        PlayAgain.setPosition({this->Menu.getPosition().x + this->Menu.getSize().x + padding, WindowCenter.y});
        PlayAgain.MB1action = [&game](){ game.NewGameAction(); };
        PlayAgain.MB2action = [&game](){};

        YouLose.setPosition({Menu.getPosition().x + ButtonsLength/2 - YouLose.getGlobalBounds().size.x/2, WindowCenter.y - WindowCenter.y/2});
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
    this->game.drawFloweryLabel(&this->Menu);
    this->game.drawFloweryLabel(&this->PlayAgain);
    this->game.drawLabel(this->YouLose);
    this->game.drawFloweryGrid(this->grid);
}

void LossScreen::Reload(FloweryGrid newGrid) {
    this->grid = newGrid;
    this->grid.setPosition(this->gridPosition);
}



