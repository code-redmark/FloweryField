#include "Game.hpp"

ScreenCollection::ScreenCollection(Game &game) 
    :   game(game), MenuUI(MenuScreen(game)), GameUI(GameScreen(game)), Loss(LossScreen(game, FloweryGrid({0.f,0.f}, {0,0}, {0,0}))) {}
