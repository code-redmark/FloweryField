#include "FloweryScreen.hpp"
#include "Screens.hpp"


// GameScreen::GameScreen(sf::RenderWindow &win, GameEngine engine) 
//     :   FloweryScreen(win, engine),
//         BaseFont(),
//         TimeCounter(sf::Text((BaseFont), "000", 14)),
//         FlaggedCounter(sf::Text((BaseFont), "0")) 
//         {
//             BaseFont.openFromFile(std::filesystem::path("assets/minesweeper-minecount.otf")); <-- Problem, BaseFont is only set later, thats a problem
//         }

MenuScreen::MenuScreen(sf::RenderWindow &win, GameEngine engine)
        :   FloweryScreen(win, engine),
        BaseFont(sf::Font(std::filesystem::path("assets/minesweeper-minecount.otf"))),
        GameTitle(sf::Text((BaseFont), "Flowery Field", 18)),
        Play(FloweryButton(sf::RectangleShape({200.f, 100.f}))),
        Exit(FloweryButton(sf::RectangleShape({200.f, 100.f})))
        {
            
        }


