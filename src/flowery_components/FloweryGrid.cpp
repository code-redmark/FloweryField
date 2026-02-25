#include "FloweryComponents.hpp"

FloweryGrid::FloweryGrid(sf::Vector2f WindowSize, sf::Vector2i WindowPos, sf::Vector2i GameSize) 
    :   GridShape(sf::RectangleShape({WindowSize.x/3, WindowSize.y/3})) 
    {
        GridShape.setFillColor(sf::Color(45, 45, 45, 215));
        GridShape.setOutlineColor(sf::Color(15, 15, 15, 255));
        GridShape.setOutlineThickness(3.f);

        this->GridShape.setOrigin({this->GridShape.getSize().x/2, this->GridShape.getSize().y/2});
        this->GridShape.setPosition({WindowPos.x + WindowSize.x/2, WindowPos.y + WindowSize.y/2});

        int cellLength = this->GridShape.getSize().x/GameSize.x;
        int cellHeight = this->GridShape.getSize().y/GameSize.y;

        sf::RectangleShape Vertical({3.f, this->GridShape.getSize().y});
        sf::RectangleShape Horizontal({this->GridShape.getSize().x, 3.f});

        Vertical.setFillColor(sf::Color(15, 15, 15, 255));
        Horizontal.setFillColor(sf::Color(15, 15, 15, 255));

        for (int x = 0; x < GameSize.x; x++) {
            sf::RectangleShape Vline(Vertical);
            Vline.setPosition({(this->GridShape.getPosition().x + cellLength) * (x + 1), this->GridShape.getPosition().y});
            this->GridLines.push_back(Vline);
        }

        for (int y = 0; y < GameSize.y; y++) {
            sf::RectangleShape Hline(Horizontal);
            Hline.setPosition({(this->GridShape.getPosition().y + cellHeight) * (y + 1), this->GridShape.getPosition().x});
            this->GridLines.push_back(Hline);
        }


        

    }

bool FloweryGrid::contains(sf::Vector2f pos) {
    return this->GridShape.getGlobalBounds().contains(pos);
}

sf::Vector2i getCellinPosition();