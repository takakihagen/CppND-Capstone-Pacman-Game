#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<iostream>

#include "SDL.h"

using namespace std;

class GameObject {
public:
    virtual void render(SDL_Renderer *sdl_renderer, SDL_Rect block) = 0;
};

#endif