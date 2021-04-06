#include "player.h"
#include "bullet.h"

#define KEY_DN (IsControllerKeyDown(SDL_CONTROLLER_BUTTON_DPAD_DOWN) || IsKeyDown(SDL_SCANCODE_S))
#define KEY_UP (IsControllerKeyDown(SDL_CONTROLLER_BUTTON_DPAD_UP)   || IsKeyDown(SDL_SCANCODE_W))
#define KEY_SHOOT (IsControllerKeyDown(SDL_CONTROLLER_BUTTON_A)      || IsKeyDown(SDL_SCANCODE_SPACE))

#define PL_COLOR BLUE
#define PL_W  32
#define PL_H  32
#define PL_MV_SPD 4
#define PL_FIRE_SPD 10

#define PL_BL_MOT (Vec2i){6, 0}
#define PL_SH_POS (Vec2i){player.position.x + 32, player.position.y + 12}

Player player;

void CreatePlayer() {
	player.position = (Vec2f){ 24 , (720/2) / 2 }; // At the middle
	player.isDead = false;
	player.score = 0;

	if (player.texture == NULL)
	{
		player.texture = LoadTexture("assets/player.png");
	}
}

void DeletePlayer() {
	DestroyTexture(player.texture);
}

void UpdatePlayer() {
	static int shoot_timer = 0;

	if (KEY_UP && player.position.y > 8)
	{
		player.position.y -= PL_MV_SPD;
	}
	if (KEY_DN && player.position.y < (720/2)-48)
	{
		player.position.y += PL_MV_SPD;
	}


	if (KEY_SHOOT && shoot_timer <= 0)
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
	Vec2i pos;
	pos.x = (int)player.position.x;
	pos.y = (int)player.position.y;

	DrawTextureFrame(player.texture, pos, (SDL_Rect) {0,0,32,32});
}

SDL_Rect GetPlayerHitbox() {
	SDL_Rect dst = { 0,0,PL_W, PL_H };
	dst.x = player.position.x;
	dst.y = player.position.y;
	return dst;
}