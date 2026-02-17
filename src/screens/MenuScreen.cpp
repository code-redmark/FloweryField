#include "Game.hpp"

#include "Screens.hpp"

MenuScreen::MenuScreen()
    : FloweryScreen(),
      GameTitle(sf::Text(Global::Field.ResourcesHandler.BaseFont, "Flowery Field++")),
      Play(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(Global::Field.ResourcesHandler.BaseFont, "Play"))),
      Exit(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(Global::Field.ResourcesHandler.BaseFont, "Quit")))
    {
        Play.setPosition({Global::WindowCenter().x - Play.shape.getSize().x/2, Global::WindowCenter().y});
        Play.MB1action = [](){
            std::cout << "Play!";
        };
        Play.MB1action = [](){};


        Exit.setPosition({Global::WindowCenter().x - Exit.shape.getSize().x/2, Global::WindowCenter().y + Play.shape.getSize().y + 25});
                Exit.MB1action = [](){
            std::cout << "Quit :(";
        };
        Exit.MB1action = [](){};

        GameTitle.setPosition({Global::WindowCenter().x - GameTitle.getScale().x/2, Global::WindowCenter().y - 50});
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
            Global::Field.Window.close();
        } else if (const auto *mousePress = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (mousePress->button == sf::Mouse::Button::Left) {
                this->OnMB1();
            } else if (mousePress->button == sf::Mouse::Button::Right) {
                this->OnMB2();
            }
        }
 
    }   
}

void MenuScreen::OnMB1() {
    if (this->Play.contains({(float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y})) {
        Play.MB1action();
    } else if (this->Exit.contains({(float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y})) {
        Exit.MB1action();
    }
}
