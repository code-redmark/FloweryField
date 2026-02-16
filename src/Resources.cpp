// Fill resources class with all types of assets (pictures, fonts etc.)


#include "Resources.hpp"

Resources::Resources() 
{
    if (this->BaseFont.openFromFile(std::filesystem::path("assets/minesweeper-minecount.otf")) == false) {
        std::cerr << "Error loading base font!";
    }
    
    // this->FlagIcon.loadFromFile();
    // this->GameCounterFont.openFromFile();
    // this->GameIcon.loadFromFile();
    // this->TitleFont.openFromFile();
}