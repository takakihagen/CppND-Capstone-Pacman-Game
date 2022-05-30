#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gameobject/pacman.h"
#include "gameobject/enemy.h"

#include <functional>
#include <vector>

class Controller {
 public:
  void HandleInput(bool &running, Pacman &pacman) const;
  void HandleEnemyDirection(std::vector<Enemy> &enemyList) const;
  void HandleRestartInput(std::function<void()> restart, bool &running) const;
 private:
  void ChangeDirection(Pacman &pacman, Direction input) const;
};

#endif