#include "Game.hpp"
#include "Screens.hpp"

class Game;

GameScreen::GameScreen(Game &game)
    : FloweryScreen(game),
        Quit(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(ResourcesHandler.BaseFont, "Back to Menu"), sf::Color(255, 0, 0, 255)))
    {
        sf::Vector2f WindowCenter = {game.GetWindowSize().x/2, game.GetWindowSize().y/2};
        Quit.setPosition({WindowCenter.x - Quit.getSize().x/2, WindowCenter.y - 50});
        
        Quit.MB1action = [&game](){ game.BackToMenuAction(); };
        Quit.MB2action = [](){};
    }

void GameScreen::Draw() {
    this->game.drawFloweryButton(this->Quit);
}

void GameScreen::OnMB1(sf::RenderWindow &GameWindow) {
    sf::Vector2i MousePosition = sf::Mouse::getPosition(GameWindow);
    if (this->Quit.contains({static_cast<float>(MousePosition.x), static_cast<float>(MousePosition.y)})) {
        Quit.MB1action();
    }
}
