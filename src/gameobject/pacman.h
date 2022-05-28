#ifndef PACMAN_H
#define PACMAN_H

#include "movableObject.h"
#include <random>
#include <memory>

class Pacman : public MovableObject {
 public:
    Pacman();
    Pacman(std::shared_ptr<Map> map,
        std::size_t grid_width, std::size_t grid_height, std::mt19937& engine);
    void render(SDL_Renderer *sdl_renderer, SDL_Rect block) override;
    void Update() override;
};

#endif