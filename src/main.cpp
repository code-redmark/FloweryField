#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

#include "Game.hpp"
#include "Screens.hpp"

using namespace Global;

int main()
{

    std::cout << "Field built\n"; 
    // Screens
    MenuScreen MenuGUI;

    Field.CurrentScreen = &MenuGUI;
    std::cout << "Set screen\n";
    
    while (Field.Window.isOpen())
    {
        
        Field.CurrentScreen->HandleEvents();

        Field.Window.clear(sf::Color::Black);
        Field.CurrentScreen->Show();
        Field.Window.display();
    }

}
