#include "Game.hpp"

// Contains all actions coming from UI


void Game::NewGameAction() {

    if (this->GameEngine == nullptr || this->GameEngine->isPlaying == false) {
        this->CurrentScreen = &this->Screens.GameUI;
        
        this->GameEngine = std::make_unique<Engine>(Engine({9, 9})); // TODO : add new screen to select grid size (difficulty)
        this->GameEngine->isPlaying = true;
    }

}

void Game::QuitAction() {
    std::cout << "Exiting\n";
    this->Window.close();
}

void Game::BackToMenuAction() {
    this->CurrentScreen = &this->Screens.MenuUI;
    this->GameEngine->isPlaying = false;
}