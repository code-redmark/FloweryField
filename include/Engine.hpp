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

    FloweryButton &button;

    Cell(FloweryButton &button);
};

class Engine { // Game logic class
    private:

    int width; 
    int height; 

    int bombDensity; // Bombs/Cell percentage (1-100)

    std::vector<Cell> grid;
    void initializeGame();
    
    std::array<CellPosition, 8> GetAround(CellPosition pos); // Get the indices of the positions around given x and y position on grid

    public:
    Engine(int width, int height) ;
    void RevealCell(CellPosition pos);
};



int ptoi(CellPosition coords, int width); // X and Y position to index in grid vector