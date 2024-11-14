#ifndef PLAYER_H
#define PLAYER_H

#include "vec2.h"
#include <SDL2/SDL_render.h>

typedef struct {
  Vec2* pos;
  int w, h;
} Player;

Player* player_create(float, float);
void player_render(SDL_Renderer*, Player*);
void player_destroy(Player*);

#endif
