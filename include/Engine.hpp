#pragma once

class FloweryButton;

#include <SFML/Graphics.hpp>

#include <vector>

/**
 * CellData is used to group every cell's specific data,
 * and more specifically its used by the main Game class to
 * update the game UI
 */
struct CellData {
    sf::Vector2i Position;

    bool revealed = false;
    bool isBomb = false;
    int around = 0;

    CellData(sf::Vector2i CellPosition) : Position(CellPosition) {};
};



/**
 * The engine class contains all the logic gamestate
 * and functions
 */
class Engine {
    private:
    std::vector<sf::Vector2i> bombs;

    bool isPlaying = false;
    
    int flags = 0;
    sf::Clock GameClock;
    

    sf::Vector2i GridSize;

    int bombDensity; // Bombs/Cell percentage (1-100)

    std::vector<CellData> grid;

    public:
    Engine(sf::Vector2i size);
    CellData GetCellData(sf::Vector2i pos);

    std::pair<std::array<int, 8>, int>GetAround(sf::Vector2i CellPosition); // Returns an array containing the indices of the cells adjacent to the given cell

    sf::Vector2i getGridSize();
    
    friend class Game;

};


/**
 * turns index of any unidimensional array's item into
 * a 2D position
 */
sf::Vector2i itop(int index, int width); 

/**
 * turns position of any 2D array's item into
 * a 1D index
 */

int ptoi(sf::Vector2i coords, int width); // X and Y position to index in grid vector