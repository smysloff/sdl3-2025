
# file: Makefile

NAME := game
SOURCES := src/*.c src/engine/*c
GCC_FLAGS := -O3 -Wall -Werror
SDL_FLAGS := $(shell pkg-config --cflags --libs sdl3)

all: clean build run

clean:
	@rm -rf $(NAME)

build:
	@gcc $(SOURCES) $(GCC_FLAGS) $(SDL_FLAGS) -o $(NAME)

run:
	@./$(NAME)

.PHONY: all clean build run
