
// file: engine/iterate.c

#include "engine.h"
#include "../tilemap.h"

SDL_AppResult SDL_AppIterate(void *appstate) {

  AppState *state = (AppState *) appstate;

  SDL_SetRenderDrawColor(state->renderer, 0, 0, 0, 255);
  SDL_RenderClear(state->renderer);

  for (size_t row = 0; row < TILE_MAP_ROWS; ++row) {
    for (size_t col = 0; col < TILE_MAP_COLS; ++col) {

      size_t index = row * TILE_MAP_COLS + col;
      char symbol = TILE_MAP[index];

      float n = 0;
      if (symbol == '.') n = 1;
      else if (symbol == '#') n = 2;

      SDL_FRect srcrect = {
        n * TILE_SIZE, 0,
        TILE_SIZE, TILE_SIZE
      };

      SDL_FRect dstrect = {
        col * TILE_SIZE, row * TILE_SIZE,
        TILE_SIZE,       TILE_SIZE,
      };

      SDL_RenderTexture(state->renderer,
        state->tiles_sprite, &srcrect, &dstrect);
    }
  }

  SDL_RenderPresent(state->renderer);

  SDL_Delay(1); // FPS cap

  return SDL_APP_CONTINUE;
}
