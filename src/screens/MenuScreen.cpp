#include "SFML/Audio.hpp"

#include "Game.hpp"
#include "Screens.hpp"

#include <cstdlib>



MenuScreen::MenuScreen()
    : FloweryScreen(),
      GameTitle(sf::Text(Global::Field.ResourcesHandler.BaseFont, "Flowery Field++")),
      Play(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(Global::Field.ResourcesHandler.BaseFont, "Play"))),
      Exit(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(Global::Field.ResourcesHandler.BaseFont, "Quit")))
    {
        Play.setPosition({Global::WindowCenter().x - Play.shape.getSize().x/2, Global::WindowCenter().y});
        Play.MB1action = [](){
            Global::Field.ResourcesHandler.alarm.play();
        };
        Play.MB2action = [](){};


        Exit.setPosition({Global::WindowCenter().x - Exit.shape.getSize().x/2, Global::WindowCenter().y + Play.shape.getSize().y + 25});
        Exit.MB1action = [](){
            Global::Field.Window.close();
        };
        Exit.MB2action = [](){};

        GameTitle.setPosition({Global::WindowCenter().x - GameTitle.getLocalBounds().size.x/2, Global::WindowCenter().y - 50});
    }

void MenuScreen::Show() {
    
    Global::Field.Window.draw(this->GameTitle);
    // Draw FloweryButtons
    this->Play.draw();
    this->Exit.draw();
}

void MenuScreen::HandleEvents() {
    while (std::optional<sf::Event> event = Global::Field.Window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            std::cout << "Closing\n";
            Global::Field.Window.close();
        } else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            this->OnMB1();
        }
    }
}

void MenuScreen::OnMB1() {
    if (this->Play.contains({static_cast<float>(sf::Mouse::getPosition(Global::Field.Window).x), static_cast<float>(sf::Mouse::getPosition(Global::Field.Window).y)})) {
        Play.MB1action();
    } else if (this->Exit.contains({static_cast<float>(sf::Mouse::getPosition(Global::Field.Window).x), static_cast<float>(sf::Mouse::getPosition(Global::Field.Window).y)})) {
        Exit.MB1action();
    }
}
