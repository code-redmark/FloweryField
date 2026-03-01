#include "Game.hpp"


ScreenCollection::ScreenCollection(Game &game) 
    :   game(game), MenuUI(MenuScreen(game)), GameUI(GameScreen(game)) {}

Game::Game() 
    :   Window(sf::RenderWindow(sf::VideoMode({1366, 768}), "Flowery Field++", sf::Style::Titlebar | sf::Style::Close)),
        GameEngine(nullptr), // Initialized when play is pressed
        Screens(ScreenCollection(*this)),
        CurrentScreen(&this->Screens.MenuUI)
    {
        this->Window.setSize(sf::Vector2u(1366, 768));
    }


void Game::GameLoop() {
    while (this->Window.isOpen()) {
        this->CurrentScreen->HandleEvents(this->Window);
        this->Window.clear(sf::Color(120, 110, 115, 255));
        this->CurrentScreen->Draw();
        this->Window.display();
    }

}

std::string Game::FlagsToString() {
    char buffer[3];
    sprintf(buffer, "%02d", this->GameEngine->flags);
    return buffer;
}

std::string Game::ClockToString() {
    char buffer[9];
    sprintf(buffer, "%03d", static_cast<int>(this->GameEngine->GameClock.getElapsedTime().asSeconds()));
    return buffer;
}

sf::Vector2i Game::GetWindowPos() {
    return this->Window.getPosition();
}

sf::Vector2f Game::GetWindowSize() {
    sf::Vector2u size = this->Window.getSize();
    return {static_cast<float>(size.x), static_cast<float>(size.y)};
}

sf::Vector2i Game::GetEngineSize() {
    return this->GameEngine->getGridSize();
}

void Game::RevealClick(sf::Vector2i CellPosition) {
    if (ptoi(CellPosition, this->GameEngine->GridSize.x) > this->GameEngine->grid.size()) {
        std::cout << "Invalid cell position\n";
        return;
    }

    CellData data = this->GameEngine->GetCellData(CellPosition);
    if (data.isBomb == false) {
        std::cout << "not a bomb. " << data.around << " bombs around\n";
    } else {
        ResourcesHandler.alarm.play(); 
        std::cout << "clicked a bomb!\n " << data.around << " bombs around\n";
        // Show bombs
        // Getbombs (need to save bombs in an array)
    }
}

void Game::FlagClick(sf::Vector2i CellPosition) {}


void Game::drawLabel(sf::Text &label) {
    this->Window.draw(label); // Drawing single item for debugging, need to use a list
}

void Game::drawFloweryButton(FloweryButton &button) {
    this->Window.draw(button.shape);
    this->Window.draw(button.label);
}

void Game::drawFloweryGrid(FloweryGrid &grid) {
    this->Window.draw(grid.GridShape);
    for (sf::RectangleShape line : grid.GridLines) {
        this->Window.draw(line);
    }
}
