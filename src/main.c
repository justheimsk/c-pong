#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/player.h"
#include "../include/ball.h"
#include "../include/defs.h"
#include "../include/input.h"
#include "../include/text.h"

void quit() {
  SDL_Quit();
  TTF_Quit();
}

int main() 
{
  srand(time(NULL));
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_Log("Failed to init SDL2: %s", SDL_GetError());
    return -1;
  }
  
  if(TTF_Init() < 0) {
    SDL_Log("Failed to init SDL2 TTF: %s", SDL_GetError());
    return -1;
  }

  
  SDL_Window *window = SDL_CreateWindow("C-PONG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, 0);
  if(!window) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    quit();
    return -1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(!renderer) {
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    SDL_DestroyWindow(window);
    quit();
    return -1;
  }

  TTF_Font *font = TTF_OpenFont("assets/fonts/arial.ttf", 24);
  if(!font) {
    SDL_Log("Failed to load font: %s", TTF_GetError());
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    quit();
    return -1;
  }

  Player *player = player_create(0, WINDOW_H / 2);
  Player *player2 = player_create(WINDOW_W - PLAYER_W, WINDOW_H / 2);
  Ball* ball = ball_create(WINDOW_W / 2, WINDOW_H / 2);

  int scores[2] = {0,0};
  char first_score[999] = "0";
  char second_score[999] = "0";

  Text *score1 = text_create(first_score, font, renderer, WINDOW_W / 4, 25);
  Text *score2 = text_create(second_score, font, renderer, WINDOW_W / 1.35, 25);

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
    int round_reset = ball_upadate(ball, player, player2);
    if (round_reset > 0)
    {
      text_destroy(score1);
      text_destroy(score2);
  
      scores[round_reset - 1] += 1;
      if(round_reset == 1) 
      {
        snprintf(first_score, sizeof(first_score), "%d", scores[round_reset-1]);
      } else 
      {
        snprintf(second_score, sizeof(second_score), "%d", scores[round_reset-1]);
      }
      
      score1 = text_create(first_score, font, renderer, WINDOW_W / 4, 25);
      score2 = text_create(second_score, font, renderer, WINDOW_W / 1.35, 25);

      ball_destroy(ball);
      ball = ball_create(WINDOW_W / 2, WINDOW_H / 2);
    }

    player_render(renderer, player);
    player_render(renderer, player2);

    text_render(score1, renderer);
    text_render(score2, renderer);

    SDL_RenderDrawLine(renderer, WINDOW_W / 2, 0, WINDOW_W / 2, WINDOW_H);
    SDL_RenderPresent(renderer);
  }

  player_destroy(player);
  player_destroy(player2);
  text_destroy(score1);
  text_destroy(score2);
  ball_destroy(ball);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(font);
  quit();
  return 0;
}
