#include "../include/text.h"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

Text* text_create(char *text, TTF_Font *font, SDL_Renderer *renderer, float x, float y)
{
  Vec2 *pos = vec2_create(x, y);
  Text *render = (Text*)malloc(sizeof(Text));
  render->pos = pos;

  SDL_Surface *surface = TTF_RenderText_Blended(font, text, (SDL_Color){255,255,255,255});
  render->rect = (SDL_Rect){.x=x,.y=y,.h=surface->h,.w=surface->w};
  render->texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);

  return render;
}

void text_render(Text *text, SDL_Renderer *renderer) 
{
  if(text) {
    SDL_RenderCopy(renderer, text->texture, NULL, &text->rect);
  }
}

void text_destroy(Text *text)
{
  vec2_destroy(text->pos);
  SDL_DestroyTexture(text->texture);
  free(text);
}
