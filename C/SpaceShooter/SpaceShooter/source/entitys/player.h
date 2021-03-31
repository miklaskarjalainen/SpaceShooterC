#pragma once
#include "../../engine/engine.h"

typedef struct Player{
	Vec2i position;
	SDL_Texture* texture;
	bool isDead;
	int score;
} Player;

void CreatePlayer();
void DeletePlayer();

void UpdatePlayer();
void DrawPlayer();

SDL_Rect GetPlayerHitbox();