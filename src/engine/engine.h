
// file: engine/engine.h

#pragma once

#include "SDL3/SDL.h"

#include "../config.h"

typedef struct AppState {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *tiles_sprite;
} AppState;
