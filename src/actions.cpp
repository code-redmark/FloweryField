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
    this->GameEngine->isPlaying = false;
}