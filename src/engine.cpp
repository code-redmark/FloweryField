#include "SFML/Graphics.hpp"

#include "Engine.hpp"
#include <random>
#include <iostream>



Engine::Engine(int width, int height) 
    : width(width), height(height) {
        this->initializeGame();
}

void Engine::initializeGame() 
{
    sf::RectangleShape CellShape({100.f, 100.f});
    
    //this->grid.resize(this->width * this->height, Cell(FloweryButton(CellShape, Global::Field.ResourcesHandler.BaseFont)));

    std::random_device device;
    std::mt19937 rng(device());

    std::uniform_int_distribution<std::mt19937::result_type> xDist(0, this->width - 1); // x distribution
    std::uniform_int_distribution<std::mt19937::result_type> yDist(0, this->height - 1); // y distribution

    // Set bombs
    for (int i = 0; i < (width * height) * (this->bombDensity/100.f); i++) {
        CellPosition randCoords {
            .x = (int)xDist(rng),
            .y = (int)yDist(rng)
        };
        this->grid[ptoi(randCoords, this->width)].isBomb = true;
        std::cout << randCoords.x << ", " << randCoords.y << "set to bomb\n";
    }
    std::cout << "Initialized grid\n";
}

void Engine::RevealCell(CellPosition pos) {
    if (this->grid[ptoi(pos, this->width)].isBomb == true) {
        // u loose screen screen and go back, could play some isBomb audio
    } else {
        this->grid[ptoi(pos, this->width)].revealed = true;
        std::array<CellPosition, 8> around = GetAround(pos);
        // if theres no bombs around reveal all bombs around pos
        int bombsAround = 0;  // will have to use this for graphics stuff
        for (CellPosition arPos : around) {
            if (this->grid[ptoi(arPos, width)].isBomb == true) bombsAround += 1;
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


Cell::Cell(FloweryButton &button) 
    :   button(button)
{}

int ptoi(CellPosition coords, int width) {
    return width * (coords.y - 1) + coords.x;
}

