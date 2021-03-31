#pragma once
#include "../../engine/engine.h"

typedef struct Bullet {
	Vec2i position;
	Vec2i motion;
	SDL_Color color; // used to check what side the bullet is on
	int life_time;  // if -1, this spot is free
} Bullet;

void InitBullets();
void CreateBullet(Vec2i pos, Vec2i mot, SDL_Color color);

void UpdateBullets();
void DrawBullets();