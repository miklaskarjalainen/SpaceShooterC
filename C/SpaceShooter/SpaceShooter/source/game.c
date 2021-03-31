#include "game.h"

// Game Files //
#include "entitys/player.h"
#include "entitys/enemy.h"
#include "entitys/bullet.h"

extern Player player;

void InitGame() {
	InitEnemies();
	InitBullets();
	CreatePlayer();
}

void UpdateGame() {
	if (!player.isDead)
	{
		UpdateBullets();
		UpdateEnemies();
		UpdatePlayer();
	}
	else
	{
		if (IsKeyDown(SDL_SCANCODE_RETURN))
		{
			InitGame();
		}
	}
}

void DrawGame() {
	DrawBullets();
	DrawEnemies();
	DrawPlayer();
}

void CleanUpGame() {
	DeletePlayer();
	DeleteEnemies();
}