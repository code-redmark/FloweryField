#include <SFML/Graphics.hpp>

#include "Game.hpp"

using namespace Global;

GameScreen::GameScreen() 
    :   FloweryScreen(),
        //TimeCounter(sf::Text(Field.ResourcesHandler.GameCounterFont, Field.ClockToString())),
        FlagCounter(sf::Text(Field.ResourcesHandler.GameCounterFont, Field.FlagsToCounter())),
        RestartButton(FloweryButton(sf::RectangleShape({50.f, 20.f}), sf::Text(Field.ResourcesHandler.GameCounterFont, "Quit game"))),
        QuitButton(FloweryButton(FloweryButton(sf::RectangleShape({50.f, 20.f}), sf::Text(Field.ResourcesHandler.GameCounterFont, "Reset game"))))
{
    //TimeCounter.setPosition(sf::Vector2f(static_cast<float>(Global::WindowCenter().x - TimeCounter.getLocalBounds().size.x - 30), static_cast<float>(Field.Window.getSize().y - 5)));
    FlagCounter.setPosition(sf::Vector2f(static_cast<float>(Global::WindowCenter().x + FlagCounter.getLocalBounds().size.x + 30), static_cast<float>(Field.Window.getSize().y + 5)));

    RestartButton.setPosition(sf::Vector2f(static_cast<float>(5), static_cast<float>(Field.Window.getSize().y + 5)));
    RestartButton.shape.setFillColor(sf::Color::Green);
    RestartButton.MB1action = [](){
        sf::Vector2i currentSize = Field.GameEngine->getSize();
        Field.GameEngine = std::make_unique<Engine>(sf::Vector2i(currentSize.x, currentSize.y));
    };

    QuitButton.setPosition(sf::Vector2f(static_cast<float>(5), static_cast<float>(Field.Window.getSize().y + 15)));
    QuitButton.shape.setFillColor(sf::Color::Red);
    QuitButton.MB1action = []() {
        Global::Field.CurrentScreen = &Field.Screens.Menu; // Move Current Screen pointer to Menu
    };
}

void GameScreen::Show() {
    //Global::Field.Window.draw(this->TimeCounter);
    Global::Field.Window.draw(this->FlagCounter);
    RestartButton.draw();
    QuitButton.draw();
}

void GameScreen::HandleEvents() {
    while (std::optional<sf::Event> event = Global::Field.Window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            std::cout << "Closing\n";
            Global::Field.Window.close();
        } else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            this->OnMB1();
        } else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
            this->OnMB2();
        }
    }
}

void GameScreen::OnMB1() {

    if (this->RestartButton.contains({static_cast<float>(sf::Mouse::getPosition(Global::Field.Window).x), static_cast<float>(sf::Mouse::getPosition(Global::Field.Window).y)})) {
        this->RestartButton.MB1action();
    } else if (this->QuitButton.contains({static_cast<float>(sf::Mouse::getPosition(Global::Field.Window).x), static_cast<float>(sf::Mouse::getPosition(Global::Field.Window).y)})) {
        this->QuitButton.MB1action();
    }
    
    // Reveal cell logic, go through every cell
}   

void GameScreen::OnMB2() {
    // Put flag logic
    // Idea: Engine.AddFlag() function
}