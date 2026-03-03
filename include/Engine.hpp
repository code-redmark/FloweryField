#pragma once

class FloweryButton;

#include <SFML/Graphics.hpp>

#include <vector>

struct CellData {
    bool revealed = false;
    bool isBomb = false;
    int around = 0;
};

class Engine { // Game logic class
    private:
    std::vector<int> bombs;

    bool isPlaying = false;
    
    int flags = 0;
    sf::Clock GameClock;
    

    sf::Vector2i GridSize;

    int bombDensity; // Bombs/Cell percentage (1-100)

    std::vector<CellData> grid;

    public:
    Engine(sf::Vector2i size);
    CellData GetCellData(sf::Vector2i pos);

    sf::Vector2i getGridSize();
    
    friend class Game;

};



sf::Vector2i itop(int index, int width); // index to X and Y position in grid vector
int ptoi(sf::Vector2i coords, int width); // X and Y position to index in grid vector