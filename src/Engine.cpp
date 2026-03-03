#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Engine.hpp"

#include <random>
#include <iostream>

Engine::Engine(sf::Vector2i size) 
    : GridSize(size), bombDensity(12) 
    {
        std::cout << "Reinitializing engine with: " << size.x << ", " << size.y << "\n";
        grid.resize(GridSize.x * GridSize.y, CellData());

        std::random_device device;
        std::mt19937 generator(device());

        std::uniform_int_distribution posDist(0, (GridSize.x * GridSize.y - 1));

        int bombAmount = static_cast<int>(size.x * size.y / 100.f * bombDensity);
        std::cout << bombAmount << "\n";
        for (int i = 0; i < bombAmount; i++) {
            int newBomb = posDist(generator);
            if (this->grid[newBomb].isBomb == true) continue;
            this->grid[newBomb].isBomb = true;

            // increment around integer for every cell around the bomb
            for (int xOffset = -1; xOffset <= 1; xOffset++) {
                for (int yOffset = -1; yOffset <= 1; yOffset++) {
                    int aroundIndex = newBomb + (this->GridSize.x * yOffset) + xOffset;
                    if (aroundIndex != newBomb && (aroundIndex >= 0 && aroundIndex < 80))
                        this->grid[aroundIndex].around += 1;
                }
            }

            this->bombs.push_back(newBomb);

        }

        std::cout << "Engine done\nBombs: ";
        for (int index : this->bombs) {
            std::cout << index << ", ";
        }
        std::cout << "\n";
    }

CellData Engine::GetCellData(sf::Vector2i pos) {
    std::cout << "Gathering " << ptoi(pos, this->getGridSize().x) << "\n";

    return this->grid[ptoi(pos, this->getGridSize().x)];
}

sf::Vector2i Engine::getGridSize() {
    return this->GridSize;
}

sf::Vector2i itop(int index, int width) {
    return {index%width, index/width};
}

int ptoi(sf::Vector2i coords, int width) {
    return width * coords.y + coords.x;
}

