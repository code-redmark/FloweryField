#pragma once

#include <SFML/Graphics.hpp>

class MenuScreen;
class GameScreen;

class Game;

#include <bits/stdc++.h>


/**
 * This is the base screen class, every screen has to handle mouse input
 * and handle what has to be currently drawn
 * 
 * Every screen contains it's UI elements as a member of the class itself
 */
class FloweryScreen {     
    protected:
    Game &game;

    virtual void OnMB1(sf::RenderWindow &GameWindow); // On left mouse button click
    virtual void OnMB2(sf::RenderWindow &GameWindow) {}

    public:
    FloweryScreen(Game &game);
    virtual void HandleEvents(sf::RenderWindow &GameWindow);
    virtual void Draw();
};

/**
 * FloweryLabel is the union of a sf::RectangleShape and
 * sf::Text, it's an additional abstraction to what SFML already
 * does, it takes care of keeping the labels position bound to the 
 * shape's position
 */

class FloweryLabel {
    protected:
    sf::RectangleShape shape;
    sf::Text label;
    
    public:
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f position);
    
    sf::Vector2f getSize();
    
    FloweryLabel(sf::RectangleShape shape, sf::Text text);
    FloweryLabel(sf::RectangleShape shape, sf::Text text, sf::Color FillColor);
    FloweryLabel(sf::RectangleShape shape, sf::Text text, sf::Color FillColor, sf::Color OutlineColor);

    friend Game;
};

/**
 * FloweryButton is a FloweryLabel with the ability to check if 
 * a position contains it and that is ready for mouse input
 */

class FloweryButton : public FloweryLabel {
    public:
    FloweryButton(FloweryLabel label);

    std::function<void()> MB1action;
    std::function<void()> MB2action;

    bool contains(sf::Vector2f pos);

    friend Game;
};

/**
 * FloweryGrid is another type of "button", it was made as a separate component
 * to avoid having tens of FloweryButton and it is made up of a background sf::RectangleShape
 * and some other, thin, RectangleShapes to make up the lines that are put on the background rectangle
 * to make the lines of the grid. The grid takes care of checking whether a position on the screen
 * is inside of the grid like FloweryButton and also translates any screen position inside of the grid
 * to the game's grid 2D position to tell Game which cell the user has clicked to flag or reveal
 */

class FloweryGrid {
    private:
    sf::Vector2i CurrentGameSize;
    float cellLength;
    float cellHeight;

    sf::RectangleShape RevealedTemplate; // similar way of storing assets as ResourcesHandler

    std::vector<FloweryLabel> RevealedCells;

    std::vector<sf::Sprite> BombSprites;

    sf::RectangleShape GridShape;
    std::vector<sf::RectangleShape> GridLines;

    public:
    FloweryGrid(sf::Vector2f WindowSize, sf::Vector2i WindowPos, sf::Vector2i GameSize);
    
    sf::Vector2f getSize();
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();

    /**
     * Reloads the grid any time it is moved or when the game restarts,
     * Reloading consists of reloading the lines making up the grid
     * and clearing the revealed cells, flags and bombs inside the 
     * various vectors containing all the UI elements being inserted
     * during gameplay
     */

    void Reload(sf::Vector2i GameSize);
    
    /**
     * This is part of Reload() and it has been separated to be usable when
     * we dont want the grid to be reset but to be moved or copied from somewhere else,
     * the example of this type of usage is in the LossScreen constructor, we want to copy
     * the grid and have it in another position and maybe even scale it so we need to reload 
     * the lines
     */
    void ReloadLines(sf::Vector2i GameSize);

    /**
     * This is called by game after a bomb has been clicked and the
     * player lost, the grid is updated by drawing all the bombs in place
     * before being displayed in the You Loss screen
     * 
     * TODO: "PAINT" THE CLICKED BOMB'S CELL RED
     */
    void ShowBombs(std::vector<sf::Vector2i> bombs);

    /**
     * contains and ScreenPosToCell are used to check whether
     * the grid has been clicked (contains), and to get the
     * specific cell on the grid that has been clicked (the latter is
     * ScreenPosToCell's job)
     */

    

    bool contains(sf::Vector2f pos);

    /**
     * Turns a screen position (that is inside of the grid's rectangle)
     * into the grid's specific cell that the position is in, the secondary
     * overload is used to tell the function to what GridPosition the returned 
     * cell position is relative to, this is used to move the grid on the screen by
     * preserving the position of the item (bomb, revealed rectangle, or a flag) before
     * the GridShape is moved
     *
     */
    sf::Vector2i ScreenPosToCell(sf::Vector2f ScreenPosition); 

    /**
     * Returns the position on the screen of the top left
     * corner of the given cell
     */
    sf::Vector2f CellToScreenPos(sf::Vector2i CellCoordinates);

    /**
     * The following are functions that run after input from
     * Game class which tells the grid to update
     */


    /**
     * Tells the grid to add a new revealed sf::RectangleShape,
     * as mentioned above, this is called by Game which tells the 
     * grid to reveal the given cell and to update the cell's
     * label to the amount of bombs around the cell
     */
    void AddRevealed(sf::Vector2i CellPosition, int around); 

    friend Game;
};



