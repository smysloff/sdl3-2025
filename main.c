
// file: main.c

#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

#include "entity.h"
#include "player.h"

#define render_entities() do {                        \
    for (size_t i = 0; i < entity_count; ++i) {       \
        entities[i].render(renderer);                 \
    }                                                 \
} while (0)

#define update_entities() do {                        \
    for (size_t i = 0; i < entity_count; ++i) {       \
        entities[i].update(delta_time);               \
    }                                                 \
} while (0)

#define quit_entities() do {                          \
    for (size_t i = 0; i < entity_count; ++i) {       \
        entities[i].quit();                           \
    }                                                 \
} while (0)

#define handle_events_entities() do {                 \
    for (size_t i = 0; i < entity_count; ++i) {       \
        entities[i].handle_events(event);             \
    }                                                 \
} while (0)

#define update_delta_time() do {                      \
    last_tick = current_tick;                         \
    current_tick = SDL_GetTicks();                    \
    delta_time = (current_tick - last_tick) / 1000.f; \
} while (0)

SDL_Window *window;
SDL_Renderer *renderer;
Entity entities[ENTITIES_MAX];
size_t entity_count = 0;
Uint64 last_tick = 0;
Uint64 current_tick = 0;
float delta_time = 0;

void update() {
    update_delta_time();
    update_entities();
}

void render(void) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);
    render_entities();
    SDL_RenderPresent(renderer);
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    quit_entities();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    renderer = NULL;
    window = NULL;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    handle_events_entities();
    
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    update();
    render();
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("error SDL_Init: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!(window = SDL_CreateWindow("SDL Game Window", 800, 600, 0))) {
        SDL_Log("error SDL_CreateWindow: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!(renderer = SDL_CreateRenderer(window, NULL))) {
        SDL_Log("error SDL_CreateRenderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    entities[entity_count++] = Player_Init(renderer);

    return SDL_APP_CONTINUE;
}
