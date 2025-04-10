
// file: entity.h

#pragma once

#include <SDL3/SDL.h>

#define ENTITIES_MAX 128

typedef struct {
    void (*quit)(void);
    void (*handle_events)(SDL_Event *event);
    void (*update)(float delta_time);
    void (*render)(SDL_Renderer *renderer);
} Entity;

extern Entity entities[ENTITIES_MAX];
extern size_t entity_count;
