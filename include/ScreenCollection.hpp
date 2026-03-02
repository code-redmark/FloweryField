#pragma once

#include "Screens.hpp"
class Game;

struct ScreenCollection {
    Game &game;

    MenuScreen MenuUI;
    GameScreen GameUI;

    LossScreen Loss;

    ScreenCollection(Game &game);
};