#pragma once
#include "menu.hpp"

char askPlayerChoice()
{
    std::vector<char> possibleOption = {'0', '1', '2', 'q'};

    std::cout << "The available games are : \n -The hangman = 0 \n -The random game = 1 \n -The Noughts and Crosses game = 2" << std::endl;
    std::cout << "Quit with 'q'" << std::endl;
    std::cout << "With which game do you want to play ?" << std::endl;

    char numberOfGameChoose;
    std::cin >> numberOfGameChoose;

    while (std::none_of(possibleOption.begin(), possibleOption.end(), compare(numberOfGameChoose))) {
        std::cout << "CHOOSE A CORRECT OPTION !" << std::endl;
        std::cout << "Quit with 'q'" << std::endl;
        std::cout << "The available games are : \n -The hangman = 0 \n -The random game = 1  \n -The Noughts and Crosses game = 2" << std::endl;
        std::cout << "With which game do you want to play ?" << std::endl;
        std::cin >> numberOfGameChoose;
    }
    return numberOfGameChoose;
}

void chooseGame(const char numberOfGameChoose)
{
    switch (numberOfGameChoose) {
    case '0':
        hangmanGame();
        break;
    case '1':
        randomGame();
        break;
    case '2':
        noughtsCrossesGame();
        break;
    default:
        break;
    }
}
