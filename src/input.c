#include "../include/input.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>

void handle_wasd(Player *player, Uint8 *keystate) 
{
  if(keystate[SDL_SCANCODE_W]) {
    player_move(0, player);
  } else if(keystate[SDL_SCANCODE_S]) {
    player_move(1, player);
  }
}

void handle_arrows(Player *player, Uint8 *keystate)
{
  if(keystate[SDL_SCANCODE_UP]) {
    player_move(0, player);
  } else if (keystate[SDL_SCANCODE_DOWN]) {
    player_move(1, player);
  }
}
