#include "Game.hpp"

using namespace Global;

int main()
{

    while (Field.Window.isOpen())
    {
        Field.CurrentScreen->HandleEvents();

        Field.Window.clear(sf::Color::Black);
        Field.CurrentScreen->Show();
        Field.Window.display();
    }

    return 0;
}
