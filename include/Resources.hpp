#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

struct Resources {
    sf::RectangleShape SelectionOutline;
    sf::Font TitleFont;
    sf::Font BaseFont;
    sf::Font GameCounterFont;
    sf::Image GameIcon;
    sf::Image FlagIcon;
    // sf::SoundBuffer SoundBuff;
    Resources();
};
