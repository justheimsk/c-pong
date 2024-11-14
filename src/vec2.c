#include "../include/vec2.h"
#include <stdlib.h>

Vec2* vec2_create(float x, float y)
{
  Vec2 *vec = (Vec2*)malloc(sizeof(Vec2));
  vec->x = x;
  vec->y = y;

  return vec;
}
