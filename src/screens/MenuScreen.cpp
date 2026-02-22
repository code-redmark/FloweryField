#include "SFML/Audio.hpp"

#include "Game.hpp"

#include <cstdlib>

MenuScreen::MenuScreen(Game &game)
    : FloweryScreen(game),
        GameTitle(sf::Text(ResourcesHandler.BaseFont, "Flowery Field++")),
        Play(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(ResourcesHandler.BaseFont, "Play"), sf::Color(142, 120, 112, 205))),
        Exit(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(ResourcesHandler.BaseFont, "Quit"), sf::Color(142, 120, 112, 205)))
    {
        sf::Vector2f WindowCenter = {game.GetWindowPos().x + game.GetWindowSize().x/2, game.GetWindowPos().y + game.GetWindowSize().y/2};

        Play.setPosition({0.f, 0.f});
        Play.MB1action = [&game](){ game.NewGameAction(); };
        Play.MB2action = [](){};


        Exit.setPosition({WindowCenter.x - Exit.getSize().x/2, WindowCenter.y + Play.getSize().y + 25});
        Exit.MB1action = [&game](){ game.QuitAction(); };
        Exit.MB2action = [](){};

        GameTitle.setPosition({WindowCenter.x - GameTitle.getLocalBounds().size.x/2, WindowCenter.y - 50});
    }

void MenuScreen::Draw(sf::RenderWindow &GameWindow) {
    game.drawLabels({this->GameTitle});
    game.drawFloweryButtons({this->Play, this->Exit});
}

void MenuScreen::HandleEvents(sf::RenderWindow &GameWindow) {   
    while (const std::optional<sf::Event> event = GameWindow.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            GameWindow.close();
        } else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            this->OnMB1();
        }
    }
}

void MenuScreen::OnMB1() {
    sf::Vector2i WindowRelative = this->game.WindowPosition(sf::Mouse::getPosition());
    if (this->Play.contains({static_cast<float>(WindowRelative.x), static_cast<float>(WindowRelative.y)})) {
        Play.MB1action();
    } else if (this->Exit.contains({static_cast<float>(WindowRelative.x), static_cast<float>(WindowRelative.y)})) {
        Exit.MB1action();
    }
}
