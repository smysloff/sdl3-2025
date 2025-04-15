
// file: engine/quit.c

#include "engine.h"

void SDL_AppQuit(void *appstate, SDL_AppResult result) {

  AppState *state = (AppState *) appstate;

  if (state) {

    if (state->tiles_sprite)
      SDL_DestroyTexture(state->tiles_sprite);

    if (state->renderer)
      SDL_DestroyRenderer(state->renderer);

    if (state->window)
      SDL_DestroyWindow(state->window);

    SDL_free(state);
  }

}
