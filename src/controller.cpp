#include "controller.h"
#include <iostream>
#include <memory>
#include "SDL.h"
#include "gameobject/map.h"

void Controller::ChangeDirection(Pacman &pacman, Direction input) const {
  if (!pacman.checkWalls(input))
    pacman.direction = input;
}

void Controller::HandleEnemyDirection(std::vector<Enemy> &enemyList) const {
  for (auto& enemy : enemyList) {
    enemy.decideDirection();
  }
}

void Controller::HandleInput(bool &running, Pacman &pacman) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(pacman, Direction::kUp);
          break;

        case SDLK_DOWN:
          ChangeDirection(pacman, Direction::kDown);
          break;

        case SDLK_LEFT:
          ChangeDirection(pacman, Direction::kLeft);
          break;

        case SDLK_RIGHT:
          ChangeDirection(pacman,  Direction::kRight);
          break;
      }
    }
  }
}

void Controller::HandleRestartInput(std::function<void()> restart, bool &running) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_SPACE:
          restart();
          break;
      }
    }
  }
}