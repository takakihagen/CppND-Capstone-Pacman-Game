#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory>
#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "gameobject/pacman.h"
#include "gameobject/enemy.h"
#include "gameobject/map.h"

class Game {
 public:
  Game(std::size_t enemy_num, std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);

  void generateEnemies(std::size_t enemyNum, std::size_t grid_width, std::size_t grid_height);

 private:
  Pacman pacman;
  std::vector<Enemy> enemyList = {};
  std::shared_ptr<Map> map;
  SDL_Point food;

  std::random_device dev;
  std::shared_ptr<std::mt19937> engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  std::size_t enemy_num;
  std::size_t grid_width;
  std::size_t grid_height;

  int score{0};

  void PlaceFood();
  void Update();
  void checkGameOver();
  void prepareGame();
};

#endif