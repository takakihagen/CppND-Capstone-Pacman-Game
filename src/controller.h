#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gameobject/pacman.h"

class Controller {
 public:
  void HandleInput(bool &running, Pacman &pacman) const;

 private:
  void ChangeDirection(Pacman &pacman, Direction input) const;
};

#endif