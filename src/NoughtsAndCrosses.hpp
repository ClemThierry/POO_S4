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
void drawBoard(p6::Context& ctx, std::array<std::array<boardTile, 3>, 3>& board);
void drawSymbols(bool& isFirstPlayerPlaying, int line, int column, std::array<std::array<boardTile, 3>, 3>& board);
bool isWinner(std::array<std::array<boardTile, 3>, 3>& gameBoardTiles);
bool isEndGame(std::array<std::array<boardTile, 3>, 3>& gameBoardTiles);