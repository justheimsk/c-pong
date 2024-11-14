#ifndef BALL_H
#define BALL_H

#include "vec2.h"
#include <SDL2/SDL_render.h>

typedef struct {
  Vec2 *pos;
  Vec2 *vel;
  int w, h;
} Ball;

Ball* ball_create(float, float);
void ball_render(SDL_Renderer*, Ball*);
void ball_upadate(Ball*);
void ball_destroy(Ball*);

#endif
