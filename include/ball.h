#ifndef BALL_H
#define BALL_H

#include "player.h"
#include "vec2.h"
#include <SDL2/SDL_render.h>

typedef struct {
  Vec2 *pos;
  Vec2 *vel;
  Vec2 *dir;
  int w, h;
} Ball;

Ball* ball_create(float, float);
void ball_render(SDL_Renderer*, Ball*);
int ball_upadate(Ball*, Player*, Player*);
void ball_destroy(Ball*);

#endif
