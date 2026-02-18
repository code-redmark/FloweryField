#include <SFML/Graphics.hpp>

#include "Game.hpp"

GameScreen::GameScreen() 
    :   FloweryScreen(),
        TimeCounter(sf::Text(Global::Field.ResourcesHandler.GameCounterFont, Global::Field.ClockToString())),
        FlagCounter(sf::Text(Global::Field.ResourcesHandler.GameCounterFont, Global::Field.FlagsToCounter()))
{

}