#include "Game.hpp"

Cell::Cell(std::vector<Cell> &grid, bool isBomb) 
    :   grid(grid), bomb(isBomb), revealed(false) {}