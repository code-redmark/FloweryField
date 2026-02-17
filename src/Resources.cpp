// Fill resources class with all types of assets (pictures, fonts etc.)
#include "Resources.hpp"
#include <iostream>

Resources::Resources() 
{
    if (this->BaseFont.openFromFile(std::filesystem::path("assets/mine-sweeper.otf")) == false) {
        std::cerr << "Error loading base font!";
    }
    // if (this->SoundBuff.loadFromFile(std::filesystem::path("assets/alarm.mp3")) == false) {
    //     std::cerr << "Error loading alarm sound!";
    // }
    
    // this->FlagIcon.loadFromFile();
    // this->GameCounterFont.openFromFile();
    // this->GameIcon.loadFromFile();
    // this->TitleFont.openFromFile();
}