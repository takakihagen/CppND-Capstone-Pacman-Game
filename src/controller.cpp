#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Pacman &pacman, Direction input,
                                 Direction opposite) const {
  if (pacman.direction != opposite) pacman.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Pacman &pacman) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(pacman, Direction::kUp,
                          Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(pacman, Direction::kDown,
                          Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(pacman, Direction::kLeft,
                           Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(pacman,  Direction::kRight,
                          Direction::kLeft);
          break;
      }
    }
  }
}