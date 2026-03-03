#include "SFML/Audio.hpp"

#include "Game.hpp"

#include <cstdlib>

MenuScreen::MenuScreen(Game &game)
    : FloweryScreen(game),
        GameTitle(sf::Text(ResourcesHandler.BaseFont, "Flowery Field++")),
        Play(FloweryButton(FloweryLabel(sf::RectangleShape({200.f, 100.f}), sf::Text(ResourcesHandler.BaseFont, "Play"), sf::Color(0, 255, 0, 255)))),
        Exit(FloweryButton(FloweryLabel(sf::RectangleShape({200.f, 100.f}), sf::Text(ResourcesHandler.BaseFont, "Quit"), sf::Color(255, 0, 132, 255))))
    {
        sf::Vector2f WindowCenter = {game.GetWindowSize().x/2, game.GetWindowSize().y/2};

        GameTitle.setPosition({WindowCenter.x - GameTitle.getLocalBounds().size.x/2, WindowCenter.y - 50});

        Play.setPosition({WindowCenter.x - Play.getSize().x/2, GameTitle.getPosition().y + GameTitle.getLocalBounds().size.y/2 + 25});
        
        Play.MB1action = [&game](){
            game.NewGameAction(); 
        };
        Play.MB2action = [](){};

        Exit.setPosition({WindowCenter.x - Exit.getSize().x/2, WindowCenter.y + Play.getSize().y + 25});
        
        Exit.MB1action = [&game](){ game.QuitAction(); };
        Exit.MB2action = [](){};

        
    }

void MenuScreen::Draw() {
    this->game.drawLabel(this->GameTitle);
    this->game.drawFloweryLabel(&this->Play);
    this->game.drawFloweryLabel(&this->Exit);
}

void MenuScreen::OnMB1(sf::RenderWindow &GameWindow) {
    sf::Vector2i MousePosition = sf::Mouse::getPosition(GameWindow);
    if (this->Play.contains({static_cast<float>(MousePosition.x), static_cast<float>(MousePosition.y)})) {
        Play.MB1action();
    } else if (this->Exit.contains({static_cast<float>(MousePosition.x), static_cast<float>(MousePosition.y)})) {
        Exit.MB1action();
    }
}
