#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {

    SDL_Window* window;
    SDL_Renderer* renderer;

    bool done = false;

    // Initialize SDL3
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    
    // Create window and renderer
    window = SDL_CreateWindow("Raycast", 640, 480, 0);
    renderer = SDL_CreateRenderer(window, nullptr);

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    while (!done) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }
        
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}
