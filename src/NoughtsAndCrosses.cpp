#pragma once
#include "NoughtsAndCrosses.hpp"
const float sizeBoxe = 1.f / 3.f;

void noughtsCrossesGame()
{
    // Variable definition
    auto ctx                  = p6::Context{{800, 800, "Noughts and Crosses"}};
    bool isFirstPlayerPlaying = true;

    std::array<std::array<boardTile, 3>, 3> gameBoardTiles;

    // Init of the board
    float y = 1 - sizeBoxe;
    float x = -1 + sizeBoxe;
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            gameBoardTiles[i][j] = {x, y, ' '};
            x += 2 * sizeBoxe;
        }
        x = -1 + sizeBoxe;
        y -= 2 * sizeBoxe;
    }

    ctx.update = [&]() {
        ctx.background({0.f, 1.f, 0.7f});
        ctx.fill = {0, 0, 0, 0};

        // Draw the board (as the name said)
        drawBoard(ctx, gameBoardTiles);

        // Check if there is a winner
        if (isEndGame(gameBoardTiles)) {
            ctx.stop();
            std::string winner = (isFirstPlayerPlaying) ? " 'O' " : " 'X' ";
            std::cout << "Congratulation" << winner
                      << "player won !";
        }
    };

    ctx.mouse_pressed = [&](p6::MouseButton event) {
        std::cout << "x :" << ctx.mouse()[0] << "<=" << -1 + 2 * sizeBoxe << std::endl;

        int columnTileClicked = 1;
        int lineTileClicked   = 1;

        // Find which colomn is clicked
        if (ctx.mouse()[0] <= -sizeBoxe) {
            columnTileClicked = 0;
        }
        else if (ctx.mouse()[0] >= sizeBoxe) {
            columnTileClicked = 2;
        }

        // Find which line is clicked
        if (ctx.mouse()[1] >= sizeBoxe) {
            lineTileClicked = 0;
        }
        else if (ctx.mouse()[1] <= -sizeBoxe) {
            lineTileClicked = 2;
        }

        drawSymbols(isFirstPlayerPlaying, lineTileClicked, columnTileClicked, gameBoardTiles);
    };
    ctx.start();
}

void drawBoard(p6::Context& ctx, std::array<std::array<boardTile, 3>, 3>& board)
{
    // Draw lines
    ctx.line(glm::vec2(board[1][1].positionX - sizeBoxe, board[1][1].positionY + 1), glm::vec2(board[1][1].positionX - sizeBoxe, board[1][1].positionY - 1));
    ctx.line(glm::vec2(board[1][1].positionX + sizeBoxe, board[1][1].positionY + 1), glm::vec2(board[1][1].positionX + sizeBoxe, board[1][1].positionY - 1));
    // Draw columns
    ctx.line(glm::vec2(board[1][1].positionX - 1, board[1][1].positionY + sizeBoxe), glm::vec2(board[1][1].positionX + 1, board[1][1].positionY + sizeBoxe));
    ctx.line(glm::vec2(board[1][1].positionX - 1, board[1][1].positionY - sizeBoxe), glm::vec2(board[1][1].positionX + 1, board[1][1].positionY - sizeBoxe));

    // Draw Inner case (symbols)
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (board[i][j].insideLetter == 'O') {
                ctx.circle(p6::Center{board[i][j].positionX, board[i][j].positionY}, p6::Radius{sizeBoxe - 0.1f});
            }
            else if (board[i][j].insideLetter == 'X') {
                ctx.line(glm::vec2(board[i][j].positionX - sizeBoxe + 0.1f, board[i][j].positionY + sizeBoxe - 0.1f), glm::vec2(board[i][j].positionX + sizeBoxe - 0.1f, board[i][j].positionY - sizeBoxe + 0.1f));
                ctx.line(glm::vec2(board[i][j].positionX - sizeBoxe + 0.1f, board[i][j].positionY - sizeBoxe + 0.1f), glm::vec2(board[i][j].positionX + sizeBoxe - 0.1f, board[i][j].positionY + sizeBoxe - 0.1f));
            }
        }
    }
}

void drawSymbols(bool& isFirstPlayerPlaying, int line, int column, std::array<std::array<boardTile, 3>, 3>& board)
{
    // Check if the case is available
    if (board[line][column].insideLetter == ' ') {
        // Complet with the correct symbol
        if (isFirstPlayerPlaying) {
            board[line][column].insideLetter = 'X';
        }
        else {
            board[line][column].insideLetter = 'O';
        }
        isFirstPlayerPlaying = !isFirstPlayerPlaying;
    }
}

bool isEndGame(std::array<std::array<boardTile, 3>, 3>& gameBoardTiles)
{
    for (size_t i = 0; i < 3; i++) {
        // Is winning line
        if (gameBoardTiles[i][0].insideLetter != ' ' || gameBoardTiles[i][1].insideLetter != ' ' || gameBoardTiles[i][2].insideLetter != ' ') {
            if (gameBoardTiles[i][0].insideLetter == gameBoardTiles[i][1].insideLetter && gameBoardTiles[i][1].insideLetter == gameBoardTiles[i][2].insideLetter) {
                return true;
            }
        }

        // Is winning column
        if (gameBoardTiles[0][i].insideLetter != ' ' || gameBoardTiles[1][i].insideLetter != ' ' || gameBoardTiles[2][i].insideLetter != ' ') {
            if (gameBoardTiles[0][i].insideLetter == gameBoardTiles[1][i].insideLetter && gameBoardTiles[1][i].insideLetter == gameBoardTiles[2][i].insideLetter) {
                return true;
            }
        }
    }
    // Is winning diagonal
    if (gameBoardTiles[1][1].insideLetter != ' ') {
        if ((gameBoardTiles[0][0].insideLetter == gameBoardTiles[1][1].insideLetter && gameBoardTiles[1][1].insideLetter == gameBoardTiles[2][2].insideLetter) || (gameBoardTiles[0][2].insideLetter == gameBoardTiles[1][1].insideLetter && gameBoardTiles[1][1].insideLetter == gameBoardTiles[2][0].insideLetter)) {
            return true;
        }
    }
    return false;
}