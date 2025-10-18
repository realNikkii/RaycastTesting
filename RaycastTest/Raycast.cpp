#include <SDL3/SDL.h>

constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;

int main(int /*argc*/, char* /*argv*/[]) {
    bool done = false;

    // Initialize SDL3
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    
    // Create window and renderer
    SDL_Window* window = SDL_CreateWindow("Raycast", WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer( window, nullptr);

    // Check that the window and renderer were successfully created
    if (window == nullptr || renderer == nullptr) {
        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window or renderer: %s\n", SDL_GetError());
        return 1;
    }

    // Background color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    SDL_FRect test_rect;
    test_rect.w = 50;
    test_rect.h = 50;
    test_rect.x = 50;
    test_rect.y = 50;

    // Render rect in red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &test_rect);
    SDL_RenderPresent(renderer);
    
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
