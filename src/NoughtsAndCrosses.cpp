#pragma once
#include "NoughtsAndCrosses.hpp"

void noughtsCrossesGame()
{
    auto  ctx      = p6::Context{{900, 900, "Noughts and Crosses"}};
    float sizeBoxe = ctx.aspect_ratio() / 3;
    std::cout << sizeBoxe << std::endl;
    ctx.update = [&]() {                  // Define the function that will be called in a loop once you call ctx.start()
        ctx.background({0.f, 1.f, 0.7f}); // Clear the background with some color (Try to comment out this line to see what happens)
        ctx.fill = {0, 0, 0, 0};
        for (float x = -1; x < 1; x += 2 * sizeBoxe) {
            for (float y = 1; y > -1; y -= 2 * sizeBoxe) {
                ctx.square(p6::TopLeftCorner{x, y}, p6::Radius{sizeBoxe});
            }
        }

    };

    ctx.mouse_pressed = [&](p6::MouseButton event) {
        std::cout << "sizeBoxe";
    };
    ctx.start();
}