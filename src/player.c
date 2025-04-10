
// file: player.c

#include "player.h"

static float speed = 60.f * 2; // pixels per second

static float scale = 4.f;

static char texture_path[] = "char_spritesheet.png";

static SDL_FRect srcrect = {
    .x = 18, .y = 16,
    .w = 13, .h = 16,
};

static SDL_FRect dstrect = { 0 };

static SDL_Texture *texture;

struct { float x, y; } position = { 0 };

static void quit() {

}

static void handle_events(/*SDL_Event event*/) {

}

static void update(float deltatime) {

    const bool *keyboard_state = SDL_GetKeyboardState(NULL);

    float framespeed = speed * deltatime;

    if (keyboard_state[SDL_SCANCODE_W]) {
        position.y -= framespeed;
    }

    if (keyboard_state[SDL_SCANCODE_S]) {
        position.y += framespeed;
    }

    if (keyboard_state[SDL_SCANCODE_A]) {
        position.x -= framespeed;
    }

    if (keyboard_state[SDL_SCANCODE_D]) {
        position.x += framespeed;
    }

    dstrect.x = position.x;
    dstrect.y = position.y;
}

static void render(SDL_Renderer *renderer) {
    SDL_RenderTexture(renderer, texture, &srcrect, &dstrect);
}

Entity Player_Init(SDL_Renderer *renderer) {

    position.x = (800 - srcrect.x * scale) / 2;
    position.y = (600 - srcrect.y * scale) / 2;

    dstrect.x = position.x;
    dstrect.y = position.y;
    dstrect.w = srcrect.w * scale;
    dstrect.h = srcrect.h * scale;

    texture = IMG_LoadTexture(renderer, texture_path);
    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);

    return (Entity) {
        .quit = quit,
        .handle_events = handle_events,
        .update = update,
        .render = render,
    };
}
