#pragma once
#include "NoughtsAndCrosses.hpp"

void noughtsCrossesGame()
{
    auto  ctx      = p6::Context{{900, 900, "Noughts and Crosses"}};
    float sizeBoxe = ctx.aspect_ratio() / 3;
    std::cout << sizeBoxe;
    ctx.update = [&]() {                    // Define the function that will be called in a loop once you call ctx.start()
        ctx.background({0.2f, 0.1f, 0.3f}); // Clear the background with some color (Try to comment out this line to see what happens)
        ctx.fill = {0, 1, 0, 0.5};
        for (float x = -1; x < 1; x += 2 * sizeBoxe) {
            for (float y = 1; y > -1; y -= 2 * sizeBoxe) {
                ctx.square(p6::TopLeftCorner{x, y}, p6::Radius{sizeBoxe});
            }
        }

    };
    ctx.start();
}