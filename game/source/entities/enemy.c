#include <stdlib.h>
#include "enemy.h"
#include "bullet.h"

void UpdateEnemy(Enemy* e);
void DrawEnemy(Enemy* e);

#define EN_W 32
#define EN_H 32
#define EN_SPAWN_POS	(Vec2i){ 600, rand() % 304 + 16}
#define EN_SPAWN_TIMER	rand() % 240 + 60
#define EN_SHT_TIMER	rand() % 45 + 15
#define EN_SHT_POS		(Vec2i){e->position.x - 8, e->position.y + 12}

extern SDL_Renderer* renderer;
SDL_Texture* en_texture = NULL;
Enemy enemies[8];

void InitEnemies() {
	if (en_texture == NULL)
	{
		en_texture = LoadTexture("assets/enemy.png");
	}

	for (int i = 0; i < 8; i++)
	{
		Enemy no_enemy;
		no_enemy.health = -1;
		enemies[i] = no_enemy;
	}
}

void DeleteEnemies() {
	DestroyTexture(en_texture);
}

void CreateEnemy() {
	// Creation //
	Enemy e;
	e.health = 3;
	e.position = EN_SPAWN_POS;
	e.motion = (Vec2i){ 0, 2 };
	e.color = RED;
	e.shoot_timer = EN_SHT_TIMER;

	// Find a spot for it in the array //
	for (int i = 0; i < 8; i++)
	{
		if (enemies[i].health <= 0) // The spot is available
		{
			enemies[i] = e;
			break;
		}
	}

}

void UpdateEnemies() {
	static int spawn_timer = 0;

	if (spawn_timer <= 0)
	{
		spawn_timer = EN_SPAWN_TIMER;
		CreateEnemy();
	}
	spawn_timer -= 1;

	// Find a spot for it in the array //
	for (int i = 0; i < 8; i++)
	{
		Enemy* e = &enemies[i];

		if (e->health > 0) // The spot is not empty
		{
			UpdateEnemy(e);
		}
	}
}

void DrawEnemies() {
	// Find a spot for it in the array //
	for (int i = 0; i < 8; i++)
	{
		Enemy* e = &enemies[i];

		if (e->health > 0) // The spot is not empty
		{
			DrawEnemy(e);
		}
	}
}

SDL_Rect GetEnemyHitbox(Enemy* e) {
	SDL_Rect dst;
	dst.x = e->position.x;
	dst.y = e->position.y;
	dst.w = EN_W;
	dst.h = EN_H;
	return dst;
}

void UpdateEnemy(Enemy* e) {
	e->shoot_timer -= 1;
	e->position.x += e->motion.x;
	e->position.y += e->motion.y;

	// Bouncing //
	if (e->position.y <= 16 || e->position.y >= (720 / 2) - 40)
		e->motion.y *= -1;

	// Shooting //
	if (e->shoot_timer <= 0)
	{
		CreateBullet(EN_SHT_POS, (Vec2i){ -8, 0 }, RED);
		e->shoot_timer = EN_SHT_TIMER;
	}

}

void DrawEnemy(Enemy* e) {
	DrawTextureFrame(en_texture, e->position, (SDL_Rect) { 0, 0, 32, 32 });
}

