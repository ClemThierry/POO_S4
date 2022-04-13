#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "Hangman.hpp"
#include "NoughtsAndCrosses.hpp"
#include "random.hpp"


struct compare {
    int key;
    compare(int const& i)
        : key(i) {}

    bool operator()(int const& i)
    {
        return (i == key);
    }
};

void chooseGame(const char numberOfGameChoose);
char askPlayerChoice();
