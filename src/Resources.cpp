// Fill resources class with all types of assets (pictures, fonts etc.)
#include "Resources.hpp"

#include <iostream>

Resources::Resources()
    :   alarm(SoundBuff)
{
    if (this->BaseFont.openFromFile(std::filesystem::path("assets/mine-sweeper.otf")) == false) {
        std::cerr << "Error loading base font!\n";
    }
    if (this->SoundBuff.loadFromFile(std::filesystem::path("assets/alarm.wav")) == false ) {
        std::cerr << "Error loading alarm sound\n";
    } else { 
        std::cout << "loaded alarm\n";
    }


}