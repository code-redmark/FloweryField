#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Engine.hpp"

#include <random>
#include <iostream>

Engine::Engine(sf::Vector2i size) 
    : GridSize(size), bombDensity(12) 
    {
        std::cout << "Reinitializing engine with: " << size.x << ", " << size.y << "\n";

        grid.clear();
        for (int i = 0; i < GridSize.x * GridSize.y; i++) {
            grid.push_back(CellData(itop(i, this->GridSize.x)));
        }   

        std::random_device device;
        std::mt19937 generator(device());

        std::uniform_int_distribution posDist(0, (GridSize.x * GridSize.y - 1));

        int bombAmount = static_cast<int>(size.x * size.y / 100.f * bombDensity);

        for (int i = 0; i < bombAmount; i++) {
            int newBomb = posDist(generator);
            if (this->grid[newBomb].isBomb == true) continue;
            this->grid[newBomb].isBomb = true;

            sf::Vector2i toPos = itop(newBomb, this->GridSize.x);
            std::cout << "Around " << newBomb << "\n";
            std::pair<std::array<int, 8>, int> around = this->GetAround(toPos);

            for (int i = 0; i < around.second; i++) {
                this->grid[around.first[i]].around += 1;
            }

            this->bombs.push_back(itop(newBomb, this->GridSize.x));
        }

        std::cout << "\n";
    }

CellData Engine::GetCellData(sf::Vector2i pos) {
    std::cout << "Gathering " << ptoi(pos, this->getGridSize().x) << "\n";

    return this->grid[ptoi(pos, this->getGridSize().x)];
}

std::pair<std::array<int, 8>, int> Engine::GetAround(sf::Vector2i CellPosition) {
    std::array<int, 8> around;
    int size = 0;
    for (int xOffset = -1; xOffset <= 1; xOffset++) {
        for (int yOffset = -1; yOffset <= 1; yOffset++) {
            int aroundX = CellPosition.x + xOffset;
            int aroundY = CellPosition.y + yOffset;
            if (aroundX == CellPosition.x && aroundY == CellPosition.y) {
                continue;
            }

            int aroundIndex = ptoi({aroundX, aroundY}, this->GridSize.x);
            if ((aroundX >= this->GridSize.x || aroundX < 0) || (aroundY >= this->GridSize.y || aroundY < 0)) {
                std::cout << aroundIndex << " is invalid \n";
                continue;
            } else {
                std::cout << aroundIndex << "is around " << ptoi(CellPosition, this->GridSize.x) << "\n";
                around[size] = aroundIndex;
                size++;
            }
        }
    }

    std::cout << "\n\n";
    return std::make_pair(around, size);
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

