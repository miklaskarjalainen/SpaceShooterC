#pragma once
#include "../../engine/engine.h"

typedef struct Enemy {
	Vec2i position;
	Vec2i motion;
	SDL_Color color;
	int health;
	int shoot_timer;
} Enemy;

void InitEnemies();
void DeleteEnemies();
void CreateEnemy();
void UpdateEnemies();
void DrawEnemies();

SDL_Rect GetEnemyHitbox(Enemy* e);