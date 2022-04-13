#include <cstdlib>
#include <iostream>
#include "menu.hpp"

int main()
{
    std::cout << "Welcome !!!" << std::endl;
    // char choiceOfPlayer = askPlayerChoice();
    // while (choiceOfPlayer != 'q') {
    //     chooseGame(choiceOfPlayer);
    //     std::cout << "Play again ?" << std::endl;
    //     choiceOfPlayer = askPlayerChoice();
    // }
    noughtsCrossesGame();
}