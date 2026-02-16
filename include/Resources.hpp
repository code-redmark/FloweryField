#pragma once

#include <filesystem>
#include <iostream>

#include "SFML/Graphics.hpp"

struct Resources {
    sf::RectangleShape SelectionOutline;
    sf::Font TitleFont;
    sf::Font BaseFont;
    sf::Font GameCounterFont;
    sf::Image GameIcon;
    sf::Image FlagIcon;
    Resources();
};
