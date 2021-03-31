#include "player.h"
#include "bullet.h"

#define PL_COLOR BLUE
#define PL_W  32
#define PL_H  32
#define PL_MV_SPD 4
#define PL_FIRE_SPD 10

#define PL_BL_MOT (Vec2i){6, 0}
#define PL_SH_POS (Vec2i){player.position.x + 32, player.position.y + 12}

extern SDL_Renderer* renderer;
Player player;

void CreatePlayer() {
	Player i;
	i.position = (Vec2i){ 24 , (720/2) / 2 }; // At the middle
	i.texture = LoadTexture("assets/player.png");
	i.isDead = false;
	i.score = 0;
	player = i;
}

void DeletePlayer() {
	DestroyTexture(player.texture);
}

void UpdatePlayer() {
	static int shoot_timer = 0;

	if (IsKeyDown(SDL_SCANCODE_W) && player.position.y > 8)
	{
		player.position.y -= PL_MV_SPD;
	}
	if (IsKeyDown(SDL_SCANCODE_S) && player.position.y < (720/2)-48)
	{
		player.position.y += PL_MV_SPD;
	}


	if (IsKeyDown(SDL_SCANCODE_SPACE) && shoot_timer <= 0)
	{
		CreateBullet(PL_SH_POS, PL_BL_MOT, BLUE);
		shoot_timer = PL_FIRE_SPD;
	}
	else
	{
		shoot_timer -= 1;
	}
}

void DrawPlayer() {
	DrawTexture(player.texture, player.position);
}

SDL_Rect GetPlayerHitbox() {
	SDL_Rect dst = { 0,0,PL_W, PL_H };
	dst.x = player.position.x;
	dst.y = player.position.y;
	return dst;
}