#include "movableObject.h"

MovableObject::MovableObject(
    std::shared_ptr<Map> map,
    std::size_t grid_width, std::size_t grid_height,
    std::mt19937 engine
)
    : grid_width{grid_width},
      grid_height{grid_height},
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      engine(engine),
      map(map)
{}

void MovableObject::place() {
    int x, y;
    while (true) {
        x = random_w(engine);
        y = random_h(engine);
        if (map->fullMap[y][x] != 1) {
            x_pos = x;
            y_pos = y;
            break;
        }
    }
}

bool MovableObject::checkWalls(const Direction checkDirection) {
    float x = 0;
    float y = 0;
    if (checkDirection == Direction::kRight)
        x += 1;
    else if (checkDirection == Direction::kLeft)
        x -= 1;
    else if (checkDirection == Direction::kDown)
        y += 1;
    else if (checkDirection == Direction::kUp)
        y -= 1;

    int grid_x = static_cast<int>(x_pos + x);
    int grid_y = static_cast<int>(y_pos + y);
    return map->fullMap[grid_y][grid_x] == 1;
}