#ifndef MAP_H
#define MAP_H

#include<vector>
#include "gameObject.h"

class Map : public GameObject {
public:
  Map();
  void generateFullMap();
  void render(SDL_Renderer *sdl_renderer, SDL_Rect block) override;

  std::vector<std::vector<int>> fullMap;

  // The field is 21 * 21 and its symmetric
  // Here 11 * 11 map is defined which includes the middle of lines of the map
  const std::vector<std::vector<int>> walls = {
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
      {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
      {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
      {1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1 },
      {1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
      {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1 },
      {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
      {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1 },
  };
};

#endif