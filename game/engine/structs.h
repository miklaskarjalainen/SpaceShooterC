#pragma once

#define RED     (SDL_Color){255, 90, 90, 255 }
#define BLUE    (SDL_Color){90,  90, 255,255 }
#define GREEN   (SDL_Color){90, 255, 90, 255 }
#define WHITE   (SDL_Color){217, 217, 217, 255 }
#define BLACK   (SDL_Color){18, 18, 18, 255 }
#define GRAY    (SDL_Color){90, 90, 90, 255 }

typedef struct Vec2i {
    int x, y;
} Vec2i;

typedef struct Vec2f {
    float x, y;
} Vec2f;