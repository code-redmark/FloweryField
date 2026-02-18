#include "SFML/Audio.hpp"

#include "Game.hpp"
#include "Screens.hpp"

#include <cstdlib>

using namespace Global;

MenuScreen::MenuScreen()
    : FloweryScreen(),
      GameTitle(sf::Text(Field.ResourcesHandler.BaseFont, "Flowery Field++")),
      Play(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(Field.ResourcesHandler.BaseFont, "Play"))),
      Exit(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(Field.ResourcesHandler.BaseFont, "Quit")))
    {
        Play.setPosition({WindowCenter().x - Play.shape.getSize().x/2, WindowCenter().y});
        Play.shape.setFillColor(sf::Color(142, 120, 112, 205));
        Play.MB1action = [](){
            if (Field.isPlaying) return;
            Field.ResourcesHandler.alarm.play();
            Field.GameEngine = std::make_unique<Engine>(Engine({9, 9})); // TODO: Make a way to select grid size/difficulty
            Field.CurrentScreen = &Field.Screens.Game;
            Field.isPlaying = true; // avoid memory errors by resetting Engine multiple times
        };
        Play.MB2action = [](){};


        Exit.setPosition({WindowCenter().x - Exit.shape.getSize().x/2, WindowCenter().y + Play.shape.getSize().y + 25});
        Exit.shape.setFillColor(sf::Color(142, 120, 112, 205));
        Exit.MB1action = [](){
            Field.Window.close();
        };
        Exit.MB2action = [](){};

        GameTitle.setPosition({WindowCenter().x - GameTitle.getLocalBounds().size.x/2, WindowCenter().y - 50});
    }

void MenuScreen::Show() {
    
    Field.Window.draw(this->GameTitle);
    // Draw FloweryButtons
    this->Play.draw();
    this->Exit.draw();
}

void MenuScreen::HandleEvents() {
    while (std::optional<sf::Event> event = Field.Window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            std::cout << "Closing\n";
            Field.Window.close();
        } else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            this->OnMB1();
        }
    }
}

void MenuScreen::OnMB1() {
    if (this->Play.contains({static_cast<float>(sf::Mouse::getPosition(Field.Window).x), static_cast<float>(sf::Mouse::getPosition(Field.Window).y)})) {
        Play.MB1action();
    } else if (this->Exit.contains({static_cast<float>(sf::Mouse::getPosition(Field.Window).x), static_cast<float>(sf::Mouse::getPosition(Field.Window).y)})) {
        Exit.MB1action();
    }
}
