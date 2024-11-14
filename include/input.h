#ifndef INPUT_H
#define INPUT_H

#include "player.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>

void handle_wasd(Player*, Uint8*);
void handle_arrows(Player*, Uint8*);

#endif
