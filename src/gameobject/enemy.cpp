#include "enemy.h"
#include <cmath>

Enemy::Enemy() : MovableObject(){}
Enemy::Enemy(
    std::shared_ptr<Map> map,
    std::size_t grid_width, std::size_t grid_height, std::mt19937& engine
) : MovableObject(std::move(map), grid_width, grid_height, engine),
    target_x{1000},
    target_y{1000} {
  direction = Direction::kStop;
}

void Enemy::render(SDL_Renderer *sdl_renderer, SDL_Rect block) {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    block.x = static_cast<int>(x_pos) * block.w;
    block.y = static_cast<int>(y_pos) * block.h;
    if (alive) {
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    } else {
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0xFF, 0xFF);
    }
    SDL_RenderFillRect(sdl_renderer, &block);
}

Direction Enemy::getOpsite(Direction direction) {
  switch (direction)
      {
      case Direction::kUp:
          return Direction::kDown;
          break;
      case Direction::kDown:
          return Direction::kUp;
          break;
      case Direction::kRight:
          return Direction::kLeft;
          break;
      case Direction::kLeft:
          return Direction::kRight;
          break;
      case Direction::kStop:
      default:
          return Direction::kStop;
          break;      
      }
}

bool Enemy::checkDirectionValidation(const Direction targetDirection) {
    if (!checkWalls(targetDirection) && targetDirection != getOpsite(direction))
      return true;

    return false;
}
 
void Enemy::decideDirection() {
	if (!checkAtTarget())
		return;

    std::uniform_int_distribution<int> random_d(0, 3);

    Direction newDirection;
    while(true) { 
      int d_i = random_d(engine);
      switch (d_i)
      {
      case 0:
          newDirection = Direction::kDown;
          break;
      case 1:
          newDirection = Direction::kUp;
          break;
      case 2:
          newDirection = Direction::kLeft;
          break;
      case 3:
          newDirection = Direction::kRight;
          break;
      }
      if (checkDirectionValidation(newDirection)) {
          direction = newDirection;
          registerTarget();
          break;
      }
    }
}

void Enemy::registerTarget() {
    switch (direction)
	{
		case Direction::kDown:
			target_x = static_cast<int>(x_pos);
			target_y = static_cast<int>(y_pos) + 1;
			break;
		case Direction::kUp:
			target_x = static_cast<int>(x_pos);
			target_y = static_cast<int>(y_pos) - 1;
			break;
		case Direction::kRight:
			target_x = static_cast<int>(x_pos) + 1;
			target_y = static_cast<int>(y_pos);
			break;
		case Direction::kLeft:
			target_x = static_cast<int>(x_pos) - 1;
			target_y = static_cast<int>(y_pos);
			break;
	}
}

bool Enemy::checkAtTarget() {
	if (target_x == 1000 && target_y == 1000)
		return true;
    int grid_x = static_cast<int>(x_pos);
    int grid_y = static_cast<int>(y_pos);
    if (grid_x == target_x && grid_y == target_y) {
        return true;
    }
    return false;
}

void Enemy::Update() {
    int a = -1;
    switch (direction) {
      case Direction::kUp:
        y_pos -= speed;
        a = 0;
        break;

      case Direction::kDown:
        y_pos += speed;
        a = 1;
        break;

      case Direction::kLeft:
        x_pos -= speed;
        a = 2;
        break;

      case Direction::kRight:
        x_pos += speed;
        a = 3;
        break;
      case Direction::kStop:
      default:
        a = 4;
        break;
    }
    x_pos = fmod(x_pos + grid_width, grid_width);
    y_pos = fmod(y_pos + grid_height, grid_height);
}