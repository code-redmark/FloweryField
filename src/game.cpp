#include "Game.hpp"

Game::Game() 
    : width(width), height(height) {
        this->initializeGame();
}

void Game::initializeGame() {

    std::random_device device; // random device from OS
    std::mt19937 rng(device()); // pseudo random number with Mersenne Twister
    std::uniform_real_distribution<int> distribution(1, 100);

    for (int col = 0; col < this->width; col++) {
        for (int row = 0; row < this->height; row++) {
            bool isBomb = (distribution(rng) >= this->bombDensity) ? true : false;
            Cell gridCell(grid, isBomb);
            this->grid.push_back(gridCell);
        }
    }
}


void Cell::Reveal() {

}