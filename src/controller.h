#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gameobject/pacman.h"
#include "gameobject/enemy.h"

#include <vector>

class Controller {
 public:
  void HandleInput(bool &running, Pacman &pacman) const;
  void HandleEnemyDirection(std::vector<Enemy> &enemyList) const;
 private:
  void ChangeDirection(Pacman &pacman, Direction input) const;
};

#endif