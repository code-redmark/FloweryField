#include "FloweryComponents.hpp"

#include <cmath>

FloweryGrid::FloweryGrid(sf::Vector2f WindowSize, sf::Vector2i WindowPos, sf::Vector2i GameSize) 
    :   GridShape(sf::RectangleShape({500.f, 500.f})), CurrentGameSize(GameSize)
    {
        sf::Vector2f WindowCenter = {WindowSize.x/2, WindowSize.y/2};

        std::cout << "Gridsize: " << GameSize.x << ", " << GameSize.y << "\n";

        GridShape.setFillColor(sf::Color(45, 45, 45, 215));
        GridShape.setOutlineColor(sf::Color(15, 15, 15, 255));
        GridShape.setOutlineThickness(3.f);

        sf::Vector2f ShapeSize = this->GridShape.getSize();
        std::cout << ShapeSize.x << "\n";

        this->GridShape.setPosition({WindowCenter.x - ShapeSize.x/2, WindowCenter.y - ShapeSize.y/2});

        this->ReloadGrid(this->CurrentGameSize);
    }

sf::Vector2f FloweryGrid::getSize() {
    return this->GridShape.getSize();
}

void FloweryGrid::setPosition(sf::Vector2f position) {
    this->GridShape.setPosition(position);
}

sf::Vector2f FloweryGrid::getPosition() {
    return this->GridShape.getPosition();
}

void FloweryGrid::ReloadGrid(sf::Vector2i GameSize) {
    this->GridLines.clear();

    cellLength = this->GridShape.getSize().x/GameSize.x;
    cellHeight = this->GridShape.getSize().y/GameSize.y;

    sf::RectangleShape Vertical({6.f, this->GridShape.getSize().y});
    sf::RectangleShape Horizontal({this->GridShape.getSize().x, 6.f});

    Vertical.setFillColor(sf::Color(15, 15, 15, 255));
    Horizontal.setFillColor(sf::Color(15, 15, 15, 255));

    for (int x = 0; x < GameSize.x - 1; x++) { // - 1 cause we dont want the last line
        sf::RectangleShape Vline(Vertical);  
        Vline.setPosition({(this->GridShape.getPosition().x + (cellLength * (x + 1))), this->GridShape.getPosition().y});
        this->GridLines.push_back(Vline);
    }

    for (int y = 0; y < GameSize.y - 1; y++) {
        sf::RectangleShape Hline(Horizontal);
        Hline.setPosition({this->GridShape.getPosition().x, (this->GridShape.getPosition().y + (cellHeight * (y + 1)))});
        this->GridLines.push_back(Hline);
    }

}

bool FloweryGrid::contains(sf::Vector2f pos) {
    return this->GridShape.getGlobalBounds().contains(pos);
}

sf::Vector2i FloweryGrid::ScreenPosToCell(sf::Vector2f pos) {
    float Xdistance = abs(pos.x - this->GridShape.getPosition().x);
    float Ydistance = abs(pos.y - this->GridShape.getPosition().y);

    return {static_cast<int>(Xdistance/this->cellLength), static_cast<int>(Ydistance/this->cellHeight + 1)};
}