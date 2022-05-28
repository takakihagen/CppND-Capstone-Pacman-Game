#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include <random>
#include <memory>

#include "gameObject.h"
#include "map.h"

enum class Direction { kUp, kDown, kStop, kLeft, kRight };

class MovableObject : public GameObject {
 public:
    MovableObject();
    MovableObject(
        std::shared_ptr<Map> map,
        std::size_t grid_width, std::size_t grid_height,
        std::shared_ptr<std::mt19937> engine
    );

    // place the object at the begining
    void place();
    // check if next grid is the wall or not
    bool checkWalls(const Direction checkDirection);
    virtual void Update() = 0;

    float x_pos;
    float y_pos;
    Direction direction;

    float speed{0.1f};
    bool alive{true};
    std::size_t grid_width;
    std::size_t grid_height;

    std::shared_ptr<Map> map; // must hold  map to check the place of walls
    std::shared_ptr<std::mt19937> engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;
};

#endif