
// file: deltatime.c

#include "deltatime.h"

DeltaTime deltatime = {
    .value = 0,
    .update = update,
};

static uint64_t lasttime = 0;

static void update(uint64_t timestamp) {
    deltatime.value = lasttime == 0
        ? 0
        : (timestamp - lasttime) / 1000.f;
    lasttime = timestamp;
}
