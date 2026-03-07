#include "Resources.hpp"

#include <iostream>

Resources::Resources()
    :   alarm(SoundBuff)
{
    if (this->BaseFont.openFromFile(std::filesystem::path("assets/mine-sweeper.otf")) == false) {
        std::cerr << "Error loading base font!\n";
    }
    if (this->GameCounterFont.openFromFile(std::filesystem::path("assets/minesweeper-minecount.otf")) == false) {
        std::cerr << "Error loading counter font!\n";
    }
    if (this->SoundBuff.loadFromFile(std::filesystem::path("assets/alarm.wav")) == false ) {
        std::cerr << "Error loading alarm sound\n";
    }

    if (this->FlagIcon.loadFromFile(std::filesystem::path("assets/flower-flag.png")) == false) {
        std::cerr << "Error loading flag icon\n";
    }
    if (this->BombIcon.loadFromFile(std::filesystem::path("assets/bomb.png")) == false) {
        std::cerr << "Error loading bomb icon\n";
    }


}