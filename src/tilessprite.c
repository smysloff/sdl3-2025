
// file: tilessprite.c

#include "tilemap.h"

static const Uint8 colors[TILE_COUNT][4] = {
  { COLOR_BLACK },
  { COLOR_LGRAY },
  { COLOR_DGRAY },
};

SDL_Texture *TilesSprite_Create(SDL_Renderer *renderer) {

  // Allocate memory for Sprite of Tiles

  SDL_Texture *sprite = SDL_CreateTexture(renderer,
    SDL_PIXELFORMAT_RGBA8888,
      SDL_TEXTUREACCESS_TARGET,
        TILE_SIZE * 3, TILE_SIZE * 1); // texture sizes

  if (!sprite)
    return NULL;


  // Create Sprite of Tiles

  SDL_SetRenderTarget(renderer, sprite);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);


  // Draw Tiles on Sprite

  for (size_t i = 0; i < TILE_COUNT; ++i) {

    const Uint8 *color = colors[i];

    SDL_FRect rect = {
      i * TILE_SIZE, 0 * TILE_SIZE, // x, y
      TILE_SIZE,     TILE_SIZE      // w, h
    };


    // color body

    SDL_SetRenderDrawColor(renderer,
      color[0], color[1], color[2], color[3]);

    SDL_RenderFillRect(renderer, &rect);

    if (i == 0) continue;


    // color borders

    SDL_SetRenderDrawColor(renderer, COLOR_BLACK);
    SDL_RenderRect(renderer, &rect);


    // color light area

    SDL_SetRenderDrawColor(renderer, COLOR_WHITE);

    SDL_RenderLine(renderer,
      rect.x + 1,          rect.y + 1, // x, y
      rect.x + rect.w - 3, rect.y + 1  // w, h
    );

    SDL_RenderLine(renderer,
      rect.x + 1, rect.y + 1,          // x, y
      rect.x + 1, rect.y + rect.h - 3  // w, h
    );


    // color shade area

    Uint8 r = color[0] / 3 * 2;
    Uint8 g = color[1] / 3 * 2;
    Uint8 b = color[2] / 3 * 2;
    Uint8 a = color[3];

    SDL_SetRenderDrawColor(renderer, r, g, b, a);

    SDL_RenderLine(renderer,
      rect.x + rect.w - 2, rect.y + 1,         // x, y
      rect.x + rect.w - 2, rect.y + rect.h - 2 // w, h
    );

    SDL_RenderLine(renderer,
      rect.x + rect.w - 2, rect.y + rect.h - 2, // x, y
      rect.x + 1,          rect.y + rect.h - 2  // w, h
    );
  }

  SDL_SetTextureScaleMode(sprite, SDL_SCALEMODE_NEAREST);
  SDL_SetRenderTarget(renderer, NULL);

  return sprite;
}
