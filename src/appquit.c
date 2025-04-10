
// file: appquit.c

#include "appquit.h"

void SDL_AppQuit(void *appstate, SDL_AppResult result) {

    AppState *state = appstate;

    for (size_t i = 0; i < entity_count; ++i) {
        entities[i].quit();
    }

    SDL_DestroyRenderer(state->renderer);
    SDL_DestroyWindow(state->window);
    SDL_QuitSubSystem(SDL_INIT_VIDEO);

    state->renderer = NULL;
    state->window = NULL;
}
