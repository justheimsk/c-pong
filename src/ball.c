#include "../include/ball.h"
#include "../include/defs.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

int check_player_colision(Ball* ball, Player* player) {
  if(ball->pos->x < player->pos->x + player->w &&
      ball->pos->x + ball->w > player->pos->x &&
      ball->pos->y < player->pos->y + player->h &&
      ball->pos->y + ball->h > player->pos->y) return 1;

  return 0;
}

int generate_random(int max, int min) 
{
  return rand() % (max + 1 - min) + min;
}

Ball* ball_create(float x, float y) 
{
  Vec2 *pos = vec2_create(x, y);
  Vec2 *vel = vec2_create(2, 3);
  Vec2 *dir = vec2_create(1, 1);

  
  if(generate_random(1, 0)) dir->x = 1;
  else dir->x = -1;

  if(generate_random(1, 0)) dir->y = 1;
  else dir->y = -1;

  Ball *ball = (Ball*)malloc(sizeof(Ball));
  ball->pos = pos;
  ball->vel = vel;
  ball->dir = dir;
  ball->w = 10;
  ball->h = 10;

  return ball;
}

void ball_render(SDL_Renderer *renderer, Ball *ball)
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
  SDL_RenderFillRect(renderer, &(SDL_Rect){ .x=ball->pos->x, .y=ball->pos->y, .w=ball->w, .h=ball->h });
}

int ball_upadate(Ball *ball, Player* player1, Player* player2)
{
  if (ball->vel->x < 5) ball->vel->x += 0.01;

  ball->pos->y += (ball->vel->y * ball->dir->y);
  ball->pos->x += (ball->vel->x * ball->dir->x);

  if(ball->pos->y <= 0 || ball->pos->y >= WINDOW_H - ball->h) ball->dir->y *= -1;
  if(check_player_colision(ball, player1) || check_player_colision(ball, player2)) ball->dir->x *= -1;

  if(ball->pos->x >= WINDOW_W - ball->w) return 1;
  if(ball->pos->x <= 0) return 2;
  return 0;
}

void ball_destroy(Ball *ball)
{
  vec2_destroy(ball->pos);
  vec2_destroy(ball->vel);
  free(ball);
}
