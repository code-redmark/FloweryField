#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

#include "Logic.hpp"
#include "Screen.hpp"

int main()
{

    // create the window
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(640, 480)), "Minesweeper++");
    window.setPosition(sf::Vector2i(0,0));

    FloweryScreen screen(window);

    // Event handling
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) window.close();
            if (event->is<sf::Event::MouseLeft>()) screen;
        }

        
        window.clear(sf::Color::Black);

        // Update screen and game
        screen.draw();

        window.display();

    }

}
