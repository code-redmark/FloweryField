#include "Game.hpp"

#include "FloweryScreen.hpp"
#include "Screens.hpp"

MenuScreen::MenuScreen()
    : FloweryScreen(),
      GameTitle(sf::Text(Global::Field.ResourcesHandler.TitleFont, "Flowery Field++")),
      Play(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(Global::Field.ResourcesHandler.BaseFont, "Play"))),
      Exit(FloweryButton(sf::RectangleShape({200.f, 100.f}), sf::Text(Global::Field.ResourcesHandler.BaseFont, "Quit")))
    {
        Play.MB1action = [](){ std::cout << "Play!\n"; };
    }

void MenuScreen::Show() {
    Global::Field.Window.draw(GameTitle);
    // Draw FloweryButtons
    this->Play.draw();
    this->Exit.draw();
}

void MenuScreen::HandleEvents() {
    while (std::optional<sf::Event> event = Global::Field.Window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) Global::Field.Window.close();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) this->OnMB1();
    }   
}

void MenuScreen::OnMB1() {
    if (this->Play.contains({(float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y})) {
        Play.MB1action();
    } else if (this->Exit.contains({(float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y})) {
        Exit.MB1action();
    }
}
