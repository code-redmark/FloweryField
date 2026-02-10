#include "Logic.hpp"

Logic::Logic() 
    : width(width), height(height) {
        this->initializeGame();
}

void Logic::initializeGame() {

    this->grid = std::vector<Cell>(this->width * this->height); // initialize grid with cell structs

    std::random_device device;
    std::mt19937 rng(device());

    std::uniform_int_distribution<int> xDist(0, this->width); // x distribution
    std::uniform_int_distribution<int> yDist(0, this->height); // y distribution

    
    // Set bombs
    for (int i = 0; i < (width * height) * (int)(this->bombDensity/100); i++) {
        Position randCoords = {
            .x = xDist(rng),
            .y = yDist(rng),
        };
        this->grid[ptoi(randCoords, this->width)].isBomb = true;
    }

}

void Logic::RevealCell(Position pos) {
    if (this->grid[ptoi(pos, this->width)].isBomb == true) {
        // u loose screen screen and go back, could play some isBomb audio
    } else {
        this->grid[ptoi(pos, this->width)].revealed = true;
        std::array<Position, 8> around = GetAround(pos);
        // if theres no bombs around reveal all bombs around pos
        int bombsAround = 0;  // will have to use this for graphics stuff
        for (Position arPos : around) {
            if (this->grid[ptoi(arPos, width)].isBomb == true) bombsAround += 1;
        }

        if (bombsAround == 0) {
            for (Position ar : around) {
                RevealCell(ar);
            }
        }

    }
}

std::array<Position, 8> Logic::GetAround(Position pos) {
    std::array<Position, 8> around;
    int i = 0;
    for (int yOffset = -1; yOffset <= 1; yOffset++) {
        for (int xOffset = -1; xOffset <= 1; xOffset++) {
            if (xOffset == 0 && yOffset == 0) continue;
            around[i] = {.x = pos.x + xOffset, .y = pos.y + yOffset};
            i++;
        }
    }
    return around;
}

int ptoi(Position coords, int width) {
    return width * (coords.y - 1) + coords.x;
}

