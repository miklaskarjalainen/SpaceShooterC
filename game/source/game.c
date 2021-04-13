#include "game.h"

#define KEY_RESTART (IsControllerKeyDown(SDL_CONTROLLER_BUTTON_START) ||IsKeyDown(SDL_SCANCODE_RETURN))

// Game Files //
#include "entities/player.h"
#include "entities/enemy.h"
#include "entities/bullet.h"

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
		if (KEY_RESTART)
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
