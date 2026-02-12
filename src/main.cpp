#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

#include "Game.hpp"
#include "Interface.hpp"

int main()
{

    // create the window
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(640, 480)), "Flowery Field++");
    window.setPosition(sf::Vector2i(0,0));
    
    FloweryScreen screen(window);

    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            // Event handling
            if (event->is<sf::Event::Closed>()) window.close();
            switch (screen.getState()) {
                case Game:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) screen.OnMB1();
                    break;
                case Menu:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter));
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down));
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up));
                    break;
            }
        }

        
        window.clear(sf::Color::Black);

        // Update screen and game
        screen.draw();

        window.display();

    }

}
