#pragma once

#include <filesystem>
#include "SFML/Graphics.hpp"

struct Resources {
    sf::Font BaseFont;
    Resources();
};

struct LabelStyle {
    sf::Color TextColor;
    int FontSize;
};

struct ButtonStyle {
    sf::Color FillColor;
    sf::Color OutlineColor;

    LabelStyle TextStyle;
};

namespace Style {

    inline const ButtonStyle Default = {
        .FillColor = sf::Color(125, 145, 145, 155),
        .OutlineColor = sf::Color(50, 50, 50),
        .TextStyle = {
            .TextColor = sf::Color::White,
            .FontSize = 10,
        }
    };

    namespace Cell {
        inline const ButtonStyle Hidden {
            .FillColor = Default.FillColor,
            .OutlineColor = Default.OutlineColor,
            .TextStyle = {
                .TextColor = sf::Color::Transparent,
                .FontSize = 10,
            }
        };
        inline const ButtonStyle Revealed = Default;
    }

    namespace Labels {
        inline const LabelStyle GameCounters {
            .TextColor = sf::Color::Red,
            .FontSize = 14,
        };
        inline const LabelStyle GameTitle {
            .TextColor = sf::Color::Blue,
            .FontSize = 17,
        };
    }
};