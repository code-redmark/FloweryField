#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

#pragma once

class Cell {
    private:
    std::vector<Cell> &grid;
    bool revealed;
    bool bomb;
    public:
    Cell(std::vector<Cell> &grid, bool isBomb);
    bool getBomb();
    void Reveal();
};

class Game {
    private:
    int width; // Number of cells on X axis
    int height; // Number of cells on Y axis
    double bombDensity; // Bombs/Cell percentage
    std::vector<Cell> grid;
    void initializeGame();

    public:
    Game();
    void RevealCell(int row, int col);
};