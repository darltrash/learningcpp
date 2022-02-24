#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_timer.h"

int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::printf("Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *rn_win = SDL_CreateWindow("daw", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 850, 500, SDL_WINDOW_RESIZABLE);
    if (rn_win == NULL) {
        std::printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_GL_SetSwapInterval(-1);

    bool keep_running = true;
    while (keep_running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) 
                keep_running = false;
        }
    }

    SDL_DestroyWindow(rn_win);
}
