#include "engine/engine.h"
#include "source/game.h"

extern SDL_Renderer* renderer;
extern SDL_Window* window;

int main(int argc, char** args)
{
	CreateWindow("The awesome game made in c with in 2 hours", 1280, 720, SDL_WINDOW_SHOWN);
	SetRenderScale((Vec2f) {2.0f, 2.0f});

	InitGame();

	while (!ShouldWindowClose())
	{
		DoEvents();
		if (IsKeyDown(SDL_SCANCODE_ESCAPE))
		{
			break;
		}


		static bool switched_fullscreen = false; // Prevents switching fullscreen state every frame.
		if (IsKeyDown(SDL_SCANCODE_F11))
		{
			switched_fullscreen = true;
			ToggleFullscreen();
		}
		else if (!IsKeyDown(SDL_SCANCODE_F11))
		{
			switched_fullscreen = false;
		}


		UpdateGame();

		// Draws //
		ClearScreen(BLACK);

		DrawGame();

		RenderScreen();
	}

	CleanUpGame();

	DestroyWindow();
	return 0;
}