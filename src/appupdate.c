
// file: appupdate.c

#include "appupdate.h"

void AppUpdate(void *appstate) {

    AppState *state = (AppState *) appstate;

    state->deltatime->update(SDL_GetTicks());

    for (size_t i = 0; i < entity_count; ++i) {
        entities[i].update(state->deltatime->value);
    }
}
