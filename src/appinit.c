
// file: appinit.c

#include "appinit.h"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {

    AppState *state;

    if (!(state = SDL_malloc(sizeof(AppState)))) {
        SDL_Log("error SDL_malloc: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    *appstate = state;
    state->deltatime = &deltatime;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("error SDL_Init: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!(state->window = SDL_CreateWindow("SDL Game Window", 800, 600, 0))) {
        SDL_Log("error SDL_CreateWindow: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!(state->renderer = SDL_CreateRenderer(state->window, NULL))) {
        SDL_Log("error SDL_CreateRenderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    entities[entity_count++] = Player_Init(state->renderer);

    return SDL_APP_CONTINUE;
}
