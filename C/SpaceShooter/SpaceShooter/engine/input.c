#include "input.h"
#include "renderer.h"

const Uint8* KeyboardStates;

bool IsKeyDown(SDL_Scancode key) {
	return KeyboardStates[key];
}

Vec2i GetMousePosition(void) {
	int mx, my;
	SDL_GetMouseState(&mx, &my);
	
	// Takes in count Window's render scale //
	Vec2f rs = GetRenderScale();
	mx /= (int)rs.x;
	my /= (int)rs.y;

	return (Vec2i) { mx, my };
}

bool IsMouseKeyDown(int key) {
	return SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(key);
}

bool IsMouseOver(SDL_Rect sh) {
	Vec2i mp = GetMousePosition();

	return	(mp.x >= sh.x && mp.x < sh.x + sh.w) &&
			(mp.y >= sh.y && mp.y < sh.y + sh.h);
}
