
// file: appevent.c

#include "appevent.h"

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {

    AppState *state = appstate;

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    for (size_t i = 0; i < entity_count; ++i) {
        entities[i].handle_events(event);
    }

    return SDL_APP_CONTINUE;
}
