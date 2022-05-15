#include "map.h"

vector<vector<int>> Map::generateFullMap() {
  vector<vector<int>> fullWalls =  walls;
  // generate upper right part
  for (int y = walls.size()-1; y >= 0; y--) {
    for (int x = walls.size()-2; x >=0; x--) {
      fullWalls[y].push_back(walls[y][x]);
    }
  }
  // generate lower part
  for (int y = walls.size()-2; y >= 0; y--) {
    fullWalls.push_back(fullWalls[y]);
  }

  return fullWalls;
}

void Map::render(SDL_Renderer *sdl_renderer, SDL_Rect block)
{
  auto fullWalls = generateFullMap();
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0xFF, 0xFF);
  //upper left and middle
  for (int y = 0; y < fullWalls.size(); y++) {
    for (int x = 0; x < fullWalls.size(); x++) {
        block.x = x * block.w;
        block.y = y * block.h;
        if (fullWalls[y][x] == 1)
          SDL_RenderFillRect(sdl_renderer, &block);
    }
  }
}