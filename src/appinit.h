
// file: appinit.h

#pragma once

#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "appstate.h"
#include "deltatime.h"
#include "entity.h"
#include "player.h"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]);
