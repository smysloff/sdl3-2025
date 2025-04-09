all: build-windows run

build-windows:
	@gcc main.c player.c                                                 \
		-IC:\Dev\SDL3/include -LC:\Dev\SDL3\lib -lSDL3                   \
		-IC:\Dev\SDL3_image\include -LC:\Dev\SDL3_image\lib -lSDL3_image \
		-lmingw32 -lkernel32 -ladvapi32 -lgdi32 -limm32 -lole32          \
	    -loleaut32 -lsetupapi -lshell32 -luser32 -lversion -lwinmm       \
		-O3                                                              \
		-o game

run:
	@game

clean:
	@rm -rf game

.PHONY: all build build-windows build-macos build-linux run game
