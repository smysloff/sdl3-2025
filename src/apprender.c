
// file: apprender.c

#include "apprender.h"

void AppRender(void *appstate) {

    AppState *state = (AppState *) appstate;

    SDL_SetRenderDrawColor(state->renderer, 0, 255, 0, 255);
    SDL_RenderClear(state->renderer);

    for (size_t i = 0; i < entity_count; ++i) {
        entities[i].render(state->renderer);
    }

    SDL_RenderPresent(state->renderer);
}
