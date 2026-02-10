#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

#include "Logic.hpp"
#include "Screen.hpp"

int main()
{

    GameState state = Menu;

    // create the window
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "Minesweeper++");

    SweeperScreen screen(window);

    // Event handling
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
    }

    // Update screen and game
    screen.draw();

    window.display();
}
