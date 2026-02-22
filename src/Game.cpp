#include "Game.hpp"


ScreenCollection::ScreenCollection(Game &game) 
    :   game(game), Menu(MenuScreen(game)) {}

Game::Game() 
    :   Window(sf::RenderWindow(sf::VideoMode({800, 600}), "Flowery Field++", sf::Style::Titlebar | sf::Style::Close)),
        GameEngine(nullptr), // Initialized when play is pressed
        Screens(ScreenCollection(*this)),
        CurrentScreen(&this->Screens.Menu)
    {}


void Game::GameLoop() {
    while (this->Window.isOpen()) {
        this->CurrentScreen->HandleEvents(this->Window);
        this->Window.clear(sf::Color::Black);
        this->CurrentScreen->Draw(this->Window);
        this->Window.display();
    }
}

void Game::NewGameAction() {
    ResourcesHandler.alarm.play();
    sf::Vector2i currentSize = this->GameEngine->getSize();
    this->GameEngine = std::make_unique<Engine>(Engine(currentSize)); // TODO : add new screen to select grid size (difficulty)
    //this->Screens.Game = GameScreen();
    this->CurrentScreen = &this->Screens.Menu;
}

void Game::QuitAction() {
    this->Window.close();
}


std::string Game::FlagsToCounter() {
    char buffer[3];
    sprintf(buffer, "%02d", this->GetFlags());
    return buffer;
}

int Game::GetFlags() {
    return this->GetFlags();
}

sf::Vector2i Game::GetWindowPos() {
    return this->Window.getPosition();
}

sf::Vector2f Game::GetWindowSize() {
    sf::Vector2u size = this->Window.getSize();
    return {static_cast<float>(size.x), static_cast<float>(size.y)};
}

void Game::drawLabels(std::vector<sf::Text> labels) {
    for (sf::Text item : labels) {
        this->Window.draw(item);
    }
}

void Game::drawFloweryButtons(const std::vector<FloweryButton> buttons) {
    for (FloweryButton button : buttons) {
        this->Window.draw(button.shape);
        this->Window.draw(button.label);
    }
}
