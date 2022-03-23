#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "Hangman.hpp"
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

void chooseGame();
