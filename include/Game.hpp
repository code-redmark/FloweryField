#pragma once

#include "Interface.hpp"


struct CellPosition;
struct Cell;
enum GameState;

class GameEngine { // Game logic class
    private:
    int width; 
    int height; 
    GameState state; // Current screen

    int bombDensity; // Bombs/Cell percentage (1-100)

    std::vector<Cell> grid;
    void initializeGame();
    
    std::array<CellPosition, 8> GetAround(CellPosition pos); // Get the indices of the positions around given x and y position on grid

    public:
    GameEngine();
    void RevealCell(CellPosition pos);
    GameState getState();
};

enum GameState {
    Menu = 1,
    Game = 2,
};

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

    Cell(const FloweryButton button);
};


int ptoi(CellPosition coords, int width); // X and Y position to index in grid vector