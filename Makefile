APP := game
TARGET_SYSTEM := Linux
UNAME := $(shell uname -s)

ifeq ($(OS), Windows_NT)
	TARGET_SYSTEM := Windows
else ifeq ($(UNAME), Darwin)
	TARGET_SYSTEM := MacOS
endif

all: clean build run

clean:
	@rm -rf $(GAME)

build:
ifeq ($(TARGET_SYSTEM), Windows)
	@gcc src/*.c \
		-IC:\Dev\SDL3\include -LC:\Dev\SDL3\lib -lSDL3 \
		-IC:\Dev\SDL3_image\include -LC:\Dev\SDL3_image\lib -lSDL3_image \
		-lmingw32 -lkernel32 -ladvapi32 -lgdi32 -limm32 -lole32 \
		-loleaut32 -lsetupapi -lshell32 -luser32 -lversion -lwinmm \
		-O3 \
		-o $(APP)
else ifeq ($(TARGET_SYSTEM),MacOS)
	@gcc src/*.c \
		$(shell pkg-config --cflags sdl3 sdl3-image) \
		$(shell pkg-config --libs sdl3 sdl3-image \
		-O3 \
		-o $(APP)
else
	@gcc src/*.c \
		-lSDL3 -lSDL3_image \
		-O3 \
		-o $(APP)
endif

run:
	@./$(APP)

.PHONY: all clean build run
