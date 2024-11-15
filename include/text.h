#ifndef TEXT_H
#define TEXT_H

#include "vec2.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

typedef struct {
  SDL_Texture *texture;
  Vec2 *pos;
  SDL_Rect rect;
} Text;

Text* text_create(char*, TTF_Font*, SDL_Renderer*, float, float);
void text_render(Text*, SDL_Renderer*);
void text_destroy(Text*);

#endif
