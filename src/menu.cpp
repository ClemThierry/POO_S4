#pragma once
#include "menu.hpp"

void chooseGame()
{
    std::vector<char> possibleOption = {'0', '1', 'q'};

    std::cout << "Welcome !!!" << std::endl;
    std::cout << "The available games are : \n -The hangman = 0 \n -The random game = 1" << std::endl;
    std::cout << "With which game do you want to play ?" << std::endl;

    char numberOfGameChoose;
    std::cin >> numberOfGameChoose;

    while (std::none_of(possibleOption.begin(), possibleOption.end(), compare(numberOfGameChoose))) {
        std::cout << "CHOOSE A CORRECT OPTION !" << std::endl;
        std::cout << "The available games are : \n -The hangman = 0 \n -The random game = 1" << std::endl;
        std::cout << "With which game do you want to play ?" << std::endl;
        std::cin >> numberOfGameChoose;
    }

    switch (numberOfGameChoose) {
    case '0':
        hangmanGame();
        break;
    case '1':
        randomGame();
        break;
    default:
        break;
    }
}
