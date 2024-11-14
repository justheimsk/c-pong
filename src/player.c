#include "../include/player.h"
#include "../include/defs.h"
#include <SDL2/SDL_render.h>

Player* player_create(float x, float y)
{
  Player *player = (Player*)malloc(sizeof(Player));
  player->h = PLAYER_H;
  player->w = PLAYER_W;
  player->velocity = 4;
  player->pos = vec2_create(x, y);

  return player;
}

void player_render(SDL_Renderer *renderer, Player *player) 
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
  SDL_RenderFillRect(renderer, &(SDL_Rect){ .x=player->pos->x, .y=player->pos->y, .w=player->w, .h=player->h });
}

void player_move(int dir, Player *player)
{
  if (dir == 1) {
    if (player->pos->y < WINDOW_H - player->h) {
      player->pos->y += player->velocity;
    }
  } else if (dir == 0) {
    if(player->pos->y > 0) {
      player->pos->y -= player->velocity;
    }
  }
}

void player_destroy(Player *player) 
{
  vec2_destroy(player->pos);
  free(player);
}
