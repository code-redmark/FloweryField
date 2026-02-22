#pragma once

#include "Screens.hpp"
class Game;

struct ScreenCollection {
    Game &game;

    MenuScreen Menu;
    // GameScreen Game; 

    ScreenCollection(Game &game);
};