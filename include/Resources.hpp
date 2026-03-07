#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

struct Resources {
    sf::RectangleShape SelectionOutline;
    sf::Font TitleFont;
    sf::Font BaseFont;
    sf::Font GameCounterFont;
    sf::SoundBuffer SoundBuff;

    sf::Sound alarm;

    sf::Texture FlagIcon;
    sf::Texture BombIcon;

    Resources();
};

extern Resources ResourcesHandler;