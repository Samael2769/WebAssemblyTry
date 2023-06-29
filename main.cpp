/**
 * @ Author: Samael
 * @ Create Time: 2023-06-27 06:29:58
 * @ Modified by: Samael
 * @ Modified time: 2023-06-29 06:28:43
 * @ Description:
 */

#include <SDL2/SDL.h>
#include <iostream>

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("My window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    std::cout << "Hello World!\n" << std::endl;

    //create a square
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 100;
    rect.h = 100;

    //set color
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    //render rect
    SDL_RenderFillRect(renderer, &rect);



    bool isRunning = true;
    while (isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                isRunning = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}