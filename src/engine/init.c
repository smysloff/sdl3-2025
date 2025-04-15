
// file: engine/init.c

#define SDL_MAIN_USE_CALLBACKS 1
#include "SDL3/SDL_main.h"

#include "engine.h"
#include "../tilemap.h"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {

  // Init SDL

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("error <SDL_Init>: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }


  // Allocate AppState

  AppState *state = SDL_calloc(1, sizeof(AppState));
  if (!state) {
    SDL_Log("error <SDL_calloc>: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }
  *appstate = state;


  // Create Window and Renderer

  if (!SDL_CreateWindowAndRenderer("SDL Test Window",
    WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT, 0, // window sizes and flags
      &state->window, &state->renderer)
  ) {
    SDL_Log("error <SDL_CreateWindowAndRenderer>: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }


  // Allocate Tiles Sprite

  if (!(state->tiles_sprite = TilesSprite_Create(state->renderer))) {
    SDL_Log("error <TileSprite_Create>: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }


  // Exit

  return SDL_APP_CONTINUE;
}
