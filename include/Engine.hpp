#pragma once

class FloweryButton;

#include <vector>

struct CellPosition {
    int x;
    int y;
};

struct Cell {
    // GameEngine variables
    bool revealed = false;
    bool isBomb = false;
    int around = 0;
};

class Engine { // Game logic class
    private:
    sf::Vector2i size;

    int bombDensity; // Bombs/Cell percentage (1-100)

    std::vector<Cell> grid;
    void initializeGame();
    
    std::array<CellPosition, 8> GetAround(CellPosition pos); // Get positions around given x and y position on grid

    public:
    Engine(sf::Vector2i size);
    void RevealCell(CellPosition pos);

    sf::Vector2i getSize();

};



int ptoi(CellPosition coords, int width); // X and Y position to index in grid vector