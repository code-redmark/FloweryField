#pragma once

#include "Screens.hpp"
class Game;

struct ScreenCollection {
    Game &game;

    MenuScreen MenuUI;
    GameScreen GameUI; 

    ScreenCollection(Game &game);
};