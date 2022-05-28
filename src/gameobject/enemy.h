#ifndef ENEMY_H
#define ENEMY_H

#include "movableObject.h"

class Enemy : public MovableObject {
public:
    Enemy();
    Enemy(std::shared_ptr<Map> map,
        std::size_t grid_width, std::size_t grid_height, std::shared_ptr<std::mt19937> engine);
    void render(SDL_Renderer *sdl_renderer, SDL_Rect block) override;
    void Update() override;

    void decideDirection();

private:
    void registerTarget();
    Direction getOpsite(Direction direction);
    bool checkDirectionValidation(const Direction targetDirection);
    bool checkAtTarget();

    std::size_t target_x;
    std::size_t target_y;
};

#endif