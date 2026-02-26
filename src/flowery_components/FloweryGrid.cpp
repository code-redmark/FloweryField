#include "FloweryComponents.hpp"

FloweryGrid::FloweryGrid(sf::Vector2f WindowSize, sf::Vector2i WindowPos, sf::Vector2i GameSize) 
    :   GridShape(sf::RectangleShape({500.f, 500.f})) 
    {
        std::cout << "Gridsize: " << GameSize.x << ", " << GameSize.y << "\n";

        GridShape.setFillColor(sf::Color(45, 45, 45, 215));
        GridShape.setOutlineColor(sf::Color(15, 15, 15, 255));
        GridShape.setOutlineThickness(3.f);

        this->GridShape.setPosition({WindowPos.x + 100.f, WindowPos.y + 100.f});

        this->ReloadGrid(GameSize);
    }


void FloweryGrid::ReloadGrid(sf::Vector2i GameSize) {
    this->GridLines.clear();

    int cellLength = this->GridShape.getSize().x/GameSize.x;
    int cellHeight = this->GridShape.getSize().y/GameSize.y;

    sf::RectangleShape Vertical({3.f, this->GridShape.getSize().y});
    sf::RectangleShape Horizontal({this->GridShape.getSize().x, 3.f});

    Vertical.setFillColor(sf::Color(255, 0, 0, 255));
    Horizontal.setFillColor(sf::Color(0, 255, 15, 255));

    for (int x = 0; x < GameSize.x - 1; x++) { // - 1 cause we dont want the last line
        sf::RectangleShape Vline(Vertical);  
        Vline.setPosition({(this->GridShape.getPosition().x + (cellLength * (x + 1))), this->GridShape.getPosition().y});
        this->GridLines.push_back(Vline);
    }

    for (int y = 0; y < GameSize.y - 1; y++) {
        sf::RectangleShape Hline(Horizontal);
        std::cout << this->GridShape.getPosition().y + (cellHeight * (y + 1)) << "\n";
        Hline.setPosition({this->GridShape.getPosition().x, (this->GridShape.getPosition().y + (cellHeight * (y + 1)))});
        this->GridLines.push_back(Hline);
    }

}




bool FloweryGrid::contains(sf::Vector2f pos) {
    return this->GridShape.getGlobalBounds().contains(pos);
}

sf::Vector2i getCellinPosition();