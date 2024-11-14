#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include "../include/player.h"
#include "../include/ball.h"
#include "../include/defs.h"
#include "../include/input.h"

int main() 
{
  SDL_Init(SDL_INIT_VIDEO);
  
  SDL_Window *window = SDL_CreateWindow("C-PONG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  Player *player = player_create(10, 10);
  Player *player2 = player_create(WINDOW_W - PLAYER_W - 10, WINDOW_H - PLAYER_H - 10);
  Ball* ball = ball_create(WINDOW_W / 2, WINDOW_H / 2);

  SDL_Event ev;
  int running = 1;
  while(running) 
  {
    while(SDL_PollEvent(&ev))
    {
      if(ev.type == SDL_QUIT) 
      {
        running = 0;
        break;
      }
    }

    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    handle_wasd(player, keystate);
    handle_arrows(player2, keystate);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
    SDL_RenderClear(renderer);

    ball_render(renderer, ball);
    ball_upadate(ball, player, player2);
    player_render(renderer, player);
    player_render(renderer, player2);

    SDL_RenderPresent(renderer);
    SDL_Delay(16);
  }

  player_destroy(player);
  player_destroy(player2);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
