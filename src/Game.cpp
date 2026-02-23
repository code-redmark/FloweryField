#include "Game.hpp"


ScreenCollection::ScreenCollection(Game &game) 
    :   game(game), MenuUI(MenuScreen(game)), GameUI(GameScreen(game)) {}

Game::Game() 
    :   Window(sf::RenderWindow(sf::VideoMode({800, 600}), "Flowery Field++", sf::Style::Titlebar | sf::Style::Close)),
        GameEngine(nullptr), // Initialized when play is pressed
        Screens(ScreenCollection(*this)),
        CurrentScreen(&this->Screens.MenuUI)
    {}


void Game::GameLoop() {
    while (this->Window.isOpen()) {
        this->CurrentScreen->HandleEvents(this->Window);
        this->Window.clear(sf::Color::Black);
        this->CurrentScreen->Draw();
        this->Window.display();
        
    }

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

void Game::drawLabel(sf::Text &label) {
    this->Window.draw(label); // Drawing single item for debugging, need to use a list
}

void Game::drawFloweryButton(FloweryButton &button) {
    this->Window.draw(button.shape);
    this->Window.draw(button.label);
}
