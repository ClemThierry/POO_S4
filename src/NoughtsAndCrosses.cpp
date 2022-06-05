#pragma once
#include "NoughtsAndCrosses.hpp"

void noughtsCrossesGame()
{
    auto  ctx                  = p6::Context{{800, 800, "Noughts and Crosses"}};
    float sizeBoxe             = ctx.aspect_ratio() / 3;
    bool  isFirstPlayerPlaying = true;

    std::cout << sizeBoxe << std::endl;

    // std::vector<boardTile> gameBoardTiles;

    boardTile gameBoardTiles[3][3];
    float     y = 1 - sizeBoxe;
    float     x = -1 + sizeBoxe;

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            gameBoardTiles[i][j] = {x, y, ' '};
            x += 2 * sizeBoxe;
        }
        x = -1 + sizeBoxe;
        y -= 2 * sizeBoxe;
    }

    // std::cout << " case 1 :" << gameBoardTiles[0][0].positionX << ", " << gameBoardTiles[0][0].positionY << std::endl;
    // std::cout << " case 2 :" << gameBoardTiles[0][1].positionX << ", " << gameBoardTiles[0][1].positionY << std::endl;
    // std::cout << " case 4 :" << gameBoardTiles[1][0].positionX << ", " << gameBoardTiles[1][0].positionY << std::endl;

    // for (float y = -1 + sizeBoxe; y < 1; y += 2 * sizeBoxe) {
    //     for (float x = -1 + sizeBoxe; x < 1; x += 2 * sizeBoxe) {
    //         gameBoardTiles.push_back({x, y});
    //     }
    // }
    // std::cout << "0 :" << gameBoardTiles[0].positionX << std::endl;
    // std::cout << "1 :" << gameBoardTiles[1].positionX << std::endl;
    // std::cout << "6 :" << gameBoardTiles[6].positionX << std::endl;

    ctx.update = [&]() {                  // Define the function that will be called in a loop once you call ctx.start()
        ctx.background({0.f, 1.f, 0.7f}); // Clear the background with some color (Try to comment out this line to see what happens)
        ctx.fill = {0, 0, 0, 0};
        // for (size_t i = 0; i < gameBoardTiles.size(); i++) {
        //     ctx.square(p6::Center{gameBoardTiles[i].positionX, gameBoardTiles[i].positionY}, p6::Radius{sizeBoxe});
        // }

        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                if (gameBoardTiles[i][j].insideLetter == 'O') {
                    ctx.fill = {0, 1, 0, 0.2f};
                    ctx.circle(p6::Center{gameBoardTiles[i][j].positionX, gameBoardTiles[i][j].positionY}, p6::Radius{sizeBoxe});
                }
                else if (gameBoardTiles[i][j].insideLetter == 'X') {
                    ctx.fill = {0, 0, 1, 0.2f};
                    ctx.line(glm::vec2(gameBoardTiles[i][j].positionX - sizeBoxe, gameBoardTiles[i][j].positionY + sizeBoxe), glm::vec2(gameBoardTiles[i][j].positionX + sizeBoxe, gameBoardTiles[i][j].positionY - sizeBoxe));
                    ctx.line(glm::vec2(gameBoardTiles[i][j].positionX - sizeBoxe, gameBoardTiles[i][j].positionY - sizeBoxe), glm::vec2(gameBoardTiles[i][j].positionX + sizeBoxe, gameBoardTiles[i][j].positionY + sizeBoxe));
                    // ctx.circle(p6::Center{gameBoardTiles[i][j].positionX, gameBoardTiles[i][j].positionY}, p6::Radius{sizeBoxe});
                }
                else {
                    ctx.fill = {0, 0, 0, 0};
                }
                ctx.square(p6::Center{gameBoardTiles[i][j].positionX, gameBoardTiles[i][j].positionY}, p6::Radius{sizeBoxe});
                // gameBoardTiles[i][j] = {x, y};
            }
        }
        // isEndGame();
        for (size_t i = 0; i < 3; i++) {
            // Test si ligne gagnante
            if (gameBoardTiles[i][0].insideLetter != ' ' || gameBoardTiles[i][1].insideLetter != ' ' || gameBoardTiles[i][2].insideLetter != ' ') {
                if (gameBoardTiles[i][0].insideLetter == gameBoardTiles[i][1].insideLetter && gameBoardTiles[i][1].insideLetter == gameBoardTiles[i][2].insideLetter) {
                    std::cout << "gagné en ligne!";
                    // return true;
                }
            }

            // Test si colonne gagnante
            if (gameBoardTiles[0][i].insideLetter != ' ' || gameBoardTiles[1][i].insideLetter != ' ' || gameBoardTiles[2][i].insideLetter != ' ') {
                if (gameBoardTiles[0][i].insideLetter == gameBoardTiles[1][i].insideLetter && gameBoardTiles[1][i].insideLetter == gameBoardTiles[2][i].insideLetter) {
                    std::cout << "gagné en colonne!";
                    // return true;
                }
            }
        }

        // Test si diagonale gagante
        if (gameBoardTiles[1][1].insideLetter != ' ') {
            if ((gameBoardTiles[0][0].insideLetter == gameBoardTiles[1][1].insideLetter && gameBoardTiles[1][1].insideLetter == gameBoardTiles[2][2].insideLetter) || (gameBoardTiles[0][2].insideLetter == gameBoardTiles[1][1].insideLetter && gameBoardTiles[1][1].insideLetter == gameBoardTiles[2][0].insideLetter)) {
                std::cout << "gagné en diag !";
            }
        }

    };

    ctx.mouse_pressed = [&](p6::MouseButton event) {
        std::cout << "x :" << ctx.mouse()[0] << "<=" << -1 + 2 * sizeBoxe << std::endl;

        int coloneTileClecked = 1;
        int ligneTileClecked  = 1;

        if (ctx.mouse()[0] <= -sizeBoxe) {
            std::cout << "col 0" << std::endl;
            coloneTileClecked = 0;
        }
        else if (ctx.mouse()[0] >= sizeBoxe) {
            std::cout << "col 2" << std::endl;
            coloneTileClecked = 2;
        }

        if (ctx.mouse()[1] >= sizeBoxe) {
            std::cout << "ligne 0" << std::endl;
            ligneTileClecked = 0;
        }
        else if (ctx.mouse()[1] <= -sizeBoxe) {
            std::cout << "ligne 2" << std::endl;
            ligneTileClecked = 2;
        }

        if (isFirstPlayerPlaying) {
            gameBoardTiles[ligneTileClecked][coloneTileClecked].insideLetter = 'X';
        }
        else {
            gameBoardTiles[ligneTileClecked][coloneTileClecked].insideLetter = 'O';
        }

        isFirstPlayerPlaying = !isFirstPlayerPlaying;
    };
    ctx.start();
}

// bool isEndGame()
// {
//     for (size_t i = 0; i < 3; i++) {
//         if (gameBoardTiles[i][0].insideLetter == gameBoardTiles[i][1].insideLetter && gameBoardTiles[i][1].insideLetter == gameBoardTiles[i][2].insideLetter) {
//             return true;
//         }
//     }
//     return false;
// }