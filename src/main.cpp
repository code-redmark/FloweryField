#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

#include "Game.hpp"
#include "FloweryScreen.hpp"

int main()
{
    
    GameEngine logic(9, 9); // Initialize game data

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(640, 480)), "Flowery Field++");
    
    MenuScreen MenuGUI(window, logic);
    GameScreen GameGUI(window, logic);

    FloweryScreen* current = &MenuGUI;
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) window.close();
            switch (logic.getState()) {
                case GAME:
                    GameGUI.HandleEvents();
                    break;
                case MENU:
                    MenuGUI.HandleEvents();
                    break;
            }
        }


        window.clear(sf::Color::Black);

        current->Show();

        window.display();

    }

}
