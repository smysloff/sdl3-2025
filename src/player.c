
// file: player.c

#include "player.h"

static float speed = 60.f * 2; // pixels per second

static float scale = 4.f;

static char texture_path[] = "char_spritesheet.png";

static SDL_Texture *texture;

static SDL_FRect srcrect;
static SDL_FRect dstrect;

struct { float x, y; } position = { 0 };

static void quit() {

}

static void handle_events(/*SDL_Event event*/) {

}

static void Player_Update(float delta_time) {

    const bool *keyboard_state = SDL_GetKeyboardState(NULL);


    if (keyboard_state[SDL_SCANCODE_W]) {
        position.y -= speed * delta_time;
    }

    if (keyboard_state[SDL_SCANCODE_S]) {
        position.y += speed * delta_time;
    }

    if (keyboard_state[SDL_SCANCODE_A]) {
        position.x -= speed * delta_time;
    }

    if (keyboard_state[SDL_SCANCODE_D]) {
        position.x += speed * delta_time;
    }

    dstrect.x = position.x;
    dstrect.y = position.y;

}

static void render(SDL_Renderer *renderer) {
    SDL_RenderTexture(renderer, texture, &srcrect, &dstrect);
}

Entity Player_Init(SDL_Renderer *renderer) {

    srcrect.x = 18;
    srcrect.y = 16;
    srcrect.w = 13;
    srcrect.h = 16;

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
        .update = Player_Update,
        .render = render,
    };
}
