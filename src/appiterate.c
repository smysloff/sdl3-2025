
// file: appiterate.c

#include "appiterate.h"

SDL_AppResult SDL_AppIterate(void *appstate) {

    AppUpdate(appstate);
    AppRender(appstate);

    return SDL_APP_CONTINUE;
}
