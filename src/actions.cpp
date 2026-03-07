#include "Game.hpp"

// Contains all actions coming from UI


void Game::NewGameAction() {
    if (this->GameEngine == nullptr || this->GameEngine->isPlaying == false) {
        ResourcesHandler.alarm.stop();
        this->GameEngine = std::make_unique<Engine>(Engine({9, 9})); // TODO : add new screen to select grid size (difficulty)
        this->GameEngine->isPlaying = true;
        this->Screens.GameUI.GridUI.ReloadGrid(GameEngine->getGridSize());
        

        this->CurrentScreen = &this->Screens.GameUI;
    }
}

void Game::QuitAction() {
    std::cout << "Exiting\n";
    this->Window.close();
}

void Game::BackToMenuAction() {
    ResourcesHandler.alarm.stop();
    this->CurrentScreen = &this->Screens.MenuUI;
    this->Screens.GameUI.GridUI.ReloadGrid(GameEngine->getGridSize());
    this->GameEngine->isPlaying = false;
}

void Game::RevealClick(sf::Vector2i CellPosition) {
    if (ptoi(CellPosition, this->GameEngine->GridSize.x) > this->GameEngine->grid.size()) {
        std::cout << "Invalid cell position\n";
        return;
    }

    CellData data = this->GameEngine->GetCellData(CellPosition);
    
    if (data.revealed) return;

    if (data.isBomb == false) {
        std::cout << "not a bomb. " << data.around << " bombs around:\n";
        this->Screens.GameUI.GridUI.AddRevealed(CellPosition, data.around);
        this->GameEngine->grid[ptoi(CellPosition, this->GameEngine->getGridSize().x)].revealed = true;
    } else {
        std::cout << "bomb!\n";
        std::cout << this->GameEngine->bombs.size() << "\n";
        this->Screens.GameUI.GridUI.ShowBombs(this->GameEngine->bombs);

        this->CurrentScreen = &this->Screens.Loss;
        this->GameEngine->isPlaying = false;
    }
}

void Game::FlagClick(sf::Vector2i CellPosition) {}
