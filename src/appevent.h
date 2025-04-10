
// file: appevent.h

#pragma once

#include <SDL3/SDL.h>

#include "appstate.h"
#include "entity.h"

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event);
