#pragma once
#include "random.hpp"

int pick_random_number(int min, int max)
{
    static std::default_random_engine  generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
};

void compare_user_number_to_random_number(int theNumberToGuess, int theUserNumber)
{
    if (theNumberToGuess == theUserNumber) {
        std::cout << "Congrats, you won !" << std::endl;
    }
    else {
        if (theUserNumber > theNumberToGuess) {
            std::cout << "Smaller" << std::endl;
        }
        else {
            std::cout << "Greater" << std::endl;
        }
    }
};

int askNumberToTheUser()
{
    int number;
    std::cin >> number;
    while (number < 0 || number > 100) {
        std::cout << "I said between 0 and 100 ... Think !" << std::endl;
        std::cin >> number;
    }
    return number;
}

void randomGame()
{
    std::cout << "THE GAME" << std::endl;
    int numberToGuess = pick_random_number(0, 100);

    std::cout << "I picked a number between 0 and 100" << std::endl
              << "Guess the number : " << std::endl;

    int userNumber = askNumberToTheUser();
    compare_user_number_to_random_number(numberToGuess, userNumber);

    while (numberToGuess != userNumber) {
        userNumber = askNumberToTheUser();
        compare_user_number_to_random_number(numberToGuess, userNumber);
    }
}