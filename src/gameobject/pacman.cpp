#include "pacman.h"
#include "gameObject.h"
#include <cmath>

Pacman::Pacman() : MovableObject(nullptr, 0, 0, std::mt19937()){}
Pacman::Pacman(
    std::shared_ptr<Map> map,
    std::size_t grid_width, std::size_t grid_height, std::mt19937 engine
) :   MovableObject(std::move(map), grid_width, grid_height, engine) {
  direction = Direction::kStop;
}

void Pacman::render(SDL_Renderer *sdl_renderer, SDL_Rect block) {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    block.x = static_cast<int>(x_pos) * block.w;
    block.y = static_cast<int>(y_pos) * block.h;
    if (alive) {
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xCC, 0xFF);
    } else {
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    SDL_RenderFillRect(sdl_renderer, &block);
}

void Pacman::Update() {
    if (checkWalls(direction))
      return;
    switch (direction) {
    case Direction::kUp:
      y_pos -= speed;
      break;

    case Direction::kDown:
      y_pos += speed;
      break;

    case Direction::kLeft:
      x_pos -= speed;
      break;

    case Direction::kRight:
      x_pos += speed;
      break;
    case Direction::kStop:
    default:
      break;
  }

  x_pos = fmod(x_pos + grid_width, grid_width);
  y_pos = fmod(y_pos + grid_height, grid_height);
}