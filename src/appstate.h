
// file: appstate.h

#pragma once

#include <SDL3/SDL.h>
#include "deltatime.h"

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    DeltaTime *deltatime;
} AppState;
