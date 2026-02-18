#include "Game.hpp"


using namespace Global;

int main()
{

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
