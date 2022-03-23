#pragma once
#include "menu.hpp"

void chooseGame()
{
    std::cout << "Welcome !!!" << std::endl;
    std::cout << "The available games are : \n -The hangman = 0 \n -The random game = 1" << std::endl;
    std::cout << "With which game do you want to play ?" << std::endl;

    unsigned int numberOfGameChoose;
    std::cin >> numberOfGameChoose;

    switch (numberOfGameChoose) {
    case 0:
        hangmanGame();
        break;
    case 1:
        randomGame();
        break;
    default:
        break;
    }
}