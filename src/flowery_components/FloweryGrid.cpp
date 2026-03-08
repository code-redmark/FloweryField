#include "Game.hpp"

#include <cmath>
#include <string>

FloweryGrid::FloweryGrid(sf::Vector2f WindowSize, sf::Vector2i WindowPos, sf::Vector2i GameSize) 
    :   GridShape(sf::RectangleShape({500.f, 500.f})), CurrentGameSize(GameSize), RevealedTemplate(sf::RectangleShape({0.f,0.f}))
    {
        sf::Vector2f WindowCenter = {WindowSize.x/2, WindowSize.y/2};
        
        std::cout << "Gridsize: " << GameSize.x << ", " << GameSize.y << "\n";

        GridShape.setFillColor(sf::Color(45, 45, 45, 215));
        GridShape.setOutlineColor(sf::Color(15, 15, 15, 255));
        GridShape.setOutlineThickness(3.f);

        sf::Vector2f ShapeSize = this->GridShape.getSize();
        std::cout << ShapeSize.x << "\n";

        this->GridShape.setPosition({WindowCenter.x - ShapeSize.x/2, WindowCenter.y - ShapeSize.y/2});

        this->RevealedTemplate.setFillColor(sf::Color(200, 200, 200, 215));

        this->Reload(this->CurrentGameSize);
    }

sf::Vector2f FloweryGrid::getSize() {
    return this->GridShape.getSize();
}

void FloweryGrid::setPosition(sf::Vector2f position) {
    sf::Vector2f oldPosition = this->getPosition();

    this->GridShape.setPosition(position);
    this->ReloadLines(this->CurrentGameSize);
    
    // Put revealed back in place
    for (FloweryLabel &cell : this->RevealedCells) {
        sf::Vector2f current = cell.getPosition();
        sf::Vector2f newPos = {current.x + (position.x - oldPosition.x), current.y + (position.y - oldPosition.y)};
        std::cout << "cell old pos: " << current.x << ", " << current.y << "\nnew pos: " << newPos.x << ", " << newPos.y << "\n";
        cell.setPosition(newPos);
    }
}

sf::Vector2f FloweryGrid::getPosition() {
    return this->GridShape.getPosition();
}

void FloweryGrid::Reload(sf::Vector2i GameSize) {
    this->GridLines.clear();
    this->BombSprites.clear();
    this->RevealedCells.clear();

    cellLength = this->GridShape.getSize().x/GameSize.x;
    cellHeight = this->GridShape.getSize().y/GameSize.y;

    this->RevealedTemplate.setSize({cellLength, cellHeight});

    this->CurrentGameSize = GameSize;

    this->ReloadLines(GameSize);
}

void FloweryGrid::ReloadLines(sf::Vector2i GameSize) {
    this->GridLines.clear();

    sf::RectangleShape Vertical({6.f, this->GridShape.getSize().y});
    sf::RectangleShape Horizontal({this->GridShape.getSize().x, 6.f});

    Vertical.setFillColor(sf::Color(15, 15, 15, 255));
    Horizontal.setFillColor(sf::Color(15, 15, 15, 255));

    for (int x = 0; x < GameSize.x - 1; x++) { // we dont want the line on the bottom of the last cell so we do Gamesize.x - 1
        sf::RectangleShape Vline(Vertical);  
        Vline.setPosition({(this->GridShape.getPosition().x + (cellLength * (x + 1))), this->GridShape.getPosition().y});
        this->GridLines.push_back(Vline);
    }

    for (int y = 0; y < GameSize.y - 1; y++) { // same thing for the condition as Vlines to not get the line on the right
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

    return {static_cast<int>(Xdistance/this->cellLength), static_cast<int>(Ydistance/this->cellHeight)};
}

sf::Vector2f FloweryGrid::CellToScreenPos(sf::Vector2i cellCoords) {
    sf::Vector2f GridPos = this->GridShape.getPosition();

    float TopLeftX = GridPos.x + (cellCoords.x * this->cellLength);
    float TopLeftY = GridPos.y + (cellCoords.y * this->cellHeight);
    
    return {TopLeftX, TopLeftY};
}

void FloweryGrid::AddRevealed(sf::Vector2i CellPosition, int around) {
    // Top left X coordinate of the cell on the screen
    float ScreenX = this->GridShape.getPosition().x + CellPosition.x * this->cellLength; 
    float ScreenY = this->GridShape.getPosition().y + CellPosition.y * this->cellHeight;
    sf::Text aroundText(ResourcesHandler.BaseFont, "");
    if (around != 0) {
        aroundText.setString(std::to_string(around));
        switch (around) {
            case 1:
            aroundText.setFillColor(sf::Color::Red);
            break;
            case 2:
            aroundText.setFillColor(sf::Color::Green);
            break;
            case 3:
            aroundText.setFillColor(sf::Color::Blue);
            break;
            case 4:
            aroundText.setFillColor(sf::Color::Cyan);
            break;
            case 5:
            aroundText.setFillColor(sf::Color::Black);
            break;
            case 6:
            aroundText.setFillColor(sf::Color::Yellow);
            break;
            case 7:
            aroundText.setFillColor(sf::Color::Magenta);
            break;
            case 8:
            aroundText.setFillColor(sf::Color(128, 64, 255));
            break;
        }
    }
    
    FloweryLabel RevealedCell = FloweryLabel(this->RevealedTemplate, aroundText);
    RevealedCell.setPosition({ScreenX, ScreenY});
    this->RevealedCells.push_back(RevealedCell);
}

void FloweryGrid::ShowBombs(std::vector<sf::Vector2i> bombs) {
    for (sf::Vector2i position : bombs) {
        sf::Sprite newBomb(ResourcesHandler.BombIcon);
        newBomb.setPosition(this->CellToScreenPos(position));
        this->BombSprites.push_back(newBomb);
    }
}