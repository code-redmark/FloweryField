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

        std::uniform_int_distribution posDist(0, GridSize.x * GridSize.y - 1);

        int bombAmount = static_cast<int>(size.x * size.y / 100.f * bombDensity);
        std::cout << bombAmount << "\n";
        for (int i = 0; i < bombAmount; i++) {
            int newBomb = posDist(generator);
            this->grid[newBomb].isBomb = true;
            this->bombs.push_back(newBomb);

            std::array<sf::Vector2i, 8> around = GetAround(itop(newBomb, size.x));
            for (sf::Vector2i cellPos : around) {

                int index = ptoi(cellPos, size.x);
                if (index < 0 || index >= this->grid.size()) continue;
            
                this->grid[ptoi(cellPos, size.x)].around += 1;
            }
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

std::array<sf::Vector2i, 8> Engine::GetAround(sf::Vector2i pos) {
    std::array<sf::Vector2i, 8> around;
    int i = 0;
    for (int yOffset = -1; yOffset <= 1; yOffset++) {
        for (int xOffset = -1; xOffset <= 1; xOffset++) {
            if (xOffset == 0 && yOffset == 0) continue;
            around[i] = {pos.x + xOffset, pos.y + yOffset};
            i++;
        }
    }
    return around;
}

sf::Vector2i Engine::getGridSize() {
    return this->GridSize;
}

sf::Vector2i itop(int index, int width) {
    return {index%width, index/width};
}

int ptoi(sf::Vector2i coords, int width) {
    return width * (coords.y - 1) + coords.x;
}

