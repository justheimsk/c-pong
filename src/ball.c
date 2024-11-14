#include "../include/ball.h"
#include "../include/defs.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

int check_player_colision(Ball* ball, Player* player) {
  if(ball->pos->x < player->pos->x + player->w &&
      ball->pos->x + ball->w > player->pos->x &&
      ball->pos->y < player->pos->y + player->h &&
      ball->pos->y + ball->h > player->pos->y) {
    return 1;
  }

  return 0;
}

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

void ball_upadate(Ball *ball, Player* player1, Player* player2)
{
  ball->pos->y += ball->vel->y;
  ball->pos->x += ball->vel->x;

  if(ball->pos->x <= 0 || ball->pos->x >= WINDOW_W - ball->w) ball->vel->x *= -1;
  if(ball->pos->y <= 0 || ball->pos->y >= WINDOW_H - ball->h) ball->vel->y *= -1;

  if(check_player_colision(ball, player1) || check_player_colision(ball, player2)) ball->vel->x *= -1; 
}

void ball_destroy(Ball *ball)
{
  vec2_destroy(ball->pos);
  vec2_destroy(ball->vel);
  free(ball);
}
