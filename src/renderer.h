#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "gameobject/pacman.h"
#include "gameobject/enemy.h"
#include "gameobject/map.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Pacman pacman, std::vector<Enemy> &emeyList, std::shared_ptr<Map> map);
  void UpdateWindowTitle(int score, int fps, bool pacmanIsAlive);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif