#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <array>


#pragma once

struct Position {
    int x;
    int y;
};

struct Cell {
    bool revealed = false;
    bool isBomb = false;
    int around = 0;
};

class Logic {
    private:
    int width;
    int height;

    int bombDensity; // Bombs/Cell percentage (1-100)

    std::vector<Cell> grid;

    void initializeGame();
    std::array<Position, 8> GetAround(Position pos); // Get the indices of the positions around given x and y position on grid

    public:
    Logic();
    void RevealCell(Position pos);
};

int ptoi(Position coords, int width); // X and Y position to index in grid vector