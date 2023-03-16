#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <iostream>


int main(int argc, char* argv[])
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Red Square", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Set the render color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Clear the screen with black color
    SDL_RenderClear(renderer);

    // Set the render color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Create a rectangle to represent the red square
    SDL_Rect rect = { 320, 240, 50, 50 };

    // Render the red square
    SDL_RenderFillRect(renderer, &rect);

    // Update the screen
    SDL_RenderPresent(renderer);

    // Handle events
    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            rect.y -= 10;
                            break;

                        case SDLK_DOWN:
                            rect.y += 10;
                            break;

                        case SDLK_LEFT:
                            rect.x -= 10;
                            break;

                        case SDLK_RIGHT:
                            rect.x += 10;
                            break;
                    }
                    break;
            }
        }

        // Clear the screen with black color
        SDL_RenderClear(renderer);

        // Render the red square
        SDL_RenderFillRect(renderer, &rect);

        // Update the screen
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
