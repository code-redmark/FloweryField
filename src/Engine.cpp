#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Engine.hpp"

#include <random>
#include <iostream>

Engine::Engine(sf::Vector2i size) 
    : GridSize(size), bombDensity(30) 
    {
        std::cout << "Reinitializing engine with: " << size.x << ", " << size.y << "\n";
        grid.resize(GridSize.x * GridSize.y, Cell());

        std::random_device device;
        std::mt19937 generator(device());

        std::uniform_int_distribution posDist(0, GridSize.x * GridSize.y - 1);

        for (int i = 0; i < static_cast<float>(GridSize.x * GridSize.y / 100 * bombDensity); i++) {
            this->grid[posDist(generator)].isBomb = true;
        }
    }

void Engine::RevealCell(CellPosition pos) {
    if (this->grid[ptoi(pos, this->GridSize.x)].isBomb == true) {
        // u loose screen screen and go back, could play some audio
    } else {
        this->grid[ptoi(pos, this->GridSize.x)].revealed = true;
        std::array<CellPosition, 8> around = GetAround(pos);
        // if theres no bombs around reveal all cells around pos
        int bombsAround = 0;  // will have to use this to show number on cells
        for (CellPosition arPos : around) {
            if (this->grid[ptoi(arPos, this->GridSize.x)].isBomb == true) bombsAround += 1;
        }

        if (bombsAround == 0) {
            for (CellPosition ar : around) {
                RevealCell(ar);
            }
        }
    }
}

std::array<CellPosition, 8> Engine::GetAround(CellPosition pos) {
    std::array<CellPosition, 8> around;
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


sf::Vector2i Engine::getGridSize() {
    return this->GridSize;
}

int ptoi(CellPosition coords, int width) {
    return width * (coords.y - 1) + coords.x;
}

