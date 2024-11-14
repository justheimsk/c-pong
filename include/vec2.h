#ifndef VEC2_H
#define VEC2_H

typedef struct {
  float x, y;
} Vec2;

Vec2* vec2_create(float, float);
void vec2_destroy(Vec2*);

#endif
