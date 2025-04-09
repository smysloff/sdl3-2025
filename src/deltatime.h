
// file: deltatime.h

#pragma once

#include <stdint.h>

typedef struct {
    float value;
    void (*update)(uint64_t timestamp);
} DeltaTime;

extern DeltaTime deltatime;
