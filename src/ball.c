#include "../include/ball.h"
#include "../include/defs.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

Ball* ball_create(float x, float y) 
{
  Vec2 *pos = vec2_create(x, y);
  Vec2 *vel = vec2_create(5, 3);

  Ball *ball = (Ball*)malloc(sizeof(Ball));
  ball->pos = pos;
  ball->vel = vel;
  ball->w = 10;
  ball->h = 10;

  return ball;
}

void ball_render(SDL_Renderer *renderer, Ball *ball)
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
  SDL_RenderFillRect(renderer, &(SDL_Rect){ .x=ball->pos->x, .y=ball->pos->y, .w=ball->w, .h=ball->h });
}

void ball_upadate(Ball *ball)
{
  ball->pos->y += ball->vel->y;
  ball->pos->x += ball->vel->x;

  if(ball->pos->x <= 0 || ball->pos->x >= WINDOW_W - ball->w) ball->vel->x *= -1;
  if(ball->pos->y <= 0 || ball->pos->y >= WINDOW_H - ball->h) ball->vel->y *= -1;
}

void ball_destroy(Ball *ball)
{
  vec2_destroy(ball->pos);
  vec2_destroy(ball->vel);
  free(ball);
}
