#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include "../include/player.h"
#include "../include/defs.h"

int main() 
{
  SDL_Init(SDL_INIT_VIDEO);
  
  SDL_Window *window = SDL_CreateWindow("C-PONG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  Player *player = player_create(10, 10);
  Player *player2 = player_create(WINDOW_W - PLAYER_W - 10, WINDOW_H - PLAYER_H - 10);

  while(1) 
  {
    SDL_Event ev;
    if(SDL_PollEvent(&ev))
    {
      if(ev.type == SDL_QUIT) break;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
    SDL_RenderClear(renderer);
    player_render(renderer, player);
    player_render(renderer, player2);
    SDL_RenderPresent(renderer);
  }

  player_destroy(player);
  player_destroy(player2);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
