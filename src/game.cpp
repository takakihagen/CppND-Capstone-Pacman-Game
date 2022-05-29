#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t enemy_num, std::size_t grid_width, std::size_t grid_height)
    : map(std::make_shared<Map>()),
      // pacman(map, grid_width, grid_height), // Q(1)
      engine(std::make_shared<std::mt19937>(dev())),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  // Q(1) Why isn't it possible to assign it above?
  // Even if the map should be declaired first, itwas empty
  pacman = Pacman(map, grid_width, grid_height, engine);
  pacman.place();

  generateEnemies(enemy_num, grid_width, grid_height);
}

void Game::generateEnemies(std::size_t enemyNum, std::size_t grid_width, std::size_t grid_height) {
  for (int i = 0; i < enemyNum; i++) {
    auto enemy = Enemy(map, grid_width, grid_height, engine);
    enemy.place();
    enemyList.emplace_back(enemy);
  }
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, pacman);
    controller.HandleEnemyDirection(enemyList);
    if (pacman.alive)
      Update();
    renderer.Render(pacman, enemyList, map);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(pacman.getPoint(), frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::checkGameOver() {
  int pacmanGridX = static_cast<int>(pacman.x_pos);
  int pacmanGridY = static_cast<int>(pacman.y_pos);
  for (auto& enemy : enemyList) {
    int enemyGridX = static_cast<int>(enemy.x_pos);
    int enemyGridY = static_cast<int>(enemy.y_pos);
    if (pacmanGridX == enemyGridX && pacmanGridY == enemyGridY) {
      pacman.alive = false;
      break;
    }
  }
}

void Game::Update() {
  // if (!pacman.alive) return;
  pacman.Update();
  for (auto& enemy : enemyList) {
    enemy.Update();
  }
  checkGameOver();
}
