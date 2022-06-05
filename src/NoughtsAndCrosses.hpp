#include <p6/p6.h>
#include <cstdlib>
#include <iostream>
#include <vector>

struct boardTile {
    float positionX;
    float positionY;
    char  insideLetter;
};

void noughtsCrossesGame();
// bool isEndGame();