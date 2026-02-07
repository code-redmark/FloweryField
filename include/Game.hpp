#include <SFML/Graphics.hpp>
#include <vector>

#pragma once

struct Cell {
    bool revealed;
    bool bomb;
};


class Game {
    private:
    int width; // Number of cells on X axis
    int height; // Number of cells on Y axis
    std::vector<Cell> grid;
    void initializeGame();

    public:
    Game();
    ~Game();
};