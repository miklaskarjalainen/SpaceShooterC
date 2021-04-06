#include "bullet.h"
#include "enemy.h"
#include "player.h"

void UpdateBullet(Bullet* b);
void DrawBullet(Bullet* b);
SDL_Rect GetBulletHitbox(Bullet* b);

#define BL_LIFETIME 60*4 // Frames, 10 seconds
#define BL_W 8
#define BL_H 8
#define BL_MV_SPD 6
#define BL_MAX_COUNT 64

extern Enemy enemies[8];
extern Player player;
Bullet all_bullets[BL_MAX_COUNT];

void InitBullets() {
	for (int i = 0; i < BL_MAX_COUNT; i++)
	{
		Bullet no_bullet;
		no_bullet.life_time = -1;
		all_bullets[i] = no_bullet;
	}
}

void CreateBullet(Vec2i pos, Vec2i mot, SDL_Color color) {
	// Creation //
	Bullet b;
	b.position = pos;
	b.motion = mot;
	b.color = color;
	b.life_time = BL_LIFETIME;

	// Find a spot for it in the array //

	for (int i = 0; i < BL_MAX_COUNT; i++)
	{
		if (all_bullets[i].life_time <= 0) // The spot is available
		{
			all_bullets[i] = b;
			break;
		}
	}
}

void UpdateBullets() {
	// Find a spot for it in the array //
	for (int i = 0; i < BL_MAX_COUNT; i++)
	{
		Bullet* b = &all_bullets[i];

		if (b->life_time > 0) // The spot is not empty
		{
			UpdateBullet(b);
		}
	}
}

void DrawBullets() {

	// Find a spot for it in the array //
	for (int i = 0; i < BL_MAX_COUNT; i++)
	{
		Bullet* b = &all_bullets[i];

		if (b->life_time > 0) // The spot is not empty
		{
			DrawBullet(b);
		}
	}
}

void UpdateBullet(Bullet* b) {
	// MOTION //
	b->life_time -= 1;
	b->position.y += b->motion.y;
	b->position.x += b->motion.x;

	// COLLISION //
	if (b->motion.x < 0) // Enemy Bullet
	{
		SDL_Rect bl = GetBulletHitbox(b);
		SDL_Rect pl = GetPlayerHitbox();
		if (RectRect(pl, bl)) // IF COLLISION
		{
			printf("Died with a score of: %i\n", player.score);
			player.isDead = true;
			b->life_time = -1;
		}
	}
	else if (b->motion.x > 0) // Player Bullet
	{
		for (int i = 0; i < 8; i++)
		{
			Enemy* e = &enemies[i];
			SDL_Rect bl = GetBulletHitbox(b);
			SDL_Rect en = GetEnemyHitbox(e);

			if (RectRect(en, bl) && e->health > 0) // IF COLLISION
			{
				e->health -= 1;
				b->life_time = -1;
				player.score += 1;
				break; // don't hit 2 enemies with 1 bullet
			}
		}
	}

}

void DrawBullet(Bullet* b) {
	SDL_Rect dst = GetBulletHitbox(b);
	DrawFillRect(dst, b->color);
}

SDL_Rect GetBulletHitbox(Bullet* b) {
	SDL_Rect dst = { 0,0, BL_W, BL_H };
	dst.x = b->position.x;
	dst.y = b->position.y;
	return dst;
}
