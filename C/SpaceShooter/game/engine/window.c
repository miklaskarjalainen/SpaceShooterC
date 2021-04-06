#include "window.h"

extern const Uint8* KeyboardStates;
SDL_Renderer* renderer = NULL;

SDL_Window* window = NULL;
bool close_window = false;

void CreateWindow(const char* title, int width, int height, SDL_WindowFlags flags) {

	// SWTICH //
	#ifdef __SWITCH__
		romfsInit();
    		chdir("romfs:/");
	#endif

	// Init SDL //
	GIF_ASSERT(!SDL_Init(SDL_INIT_EVERYTHING),  SDL_GetError());
	GIF_ASSERT( IMG_Init(IMG_INIT_PNG),			SDL_GetError());

	// Window //
	window   = SDL_CreateWindow  (title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	GIF_ASSERT(window, "Failed To Create a SDL Window");
	
	// Renderer //
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
	GIF_ASSERT(renderer, "Failed To Create a SDL Renderer");

	KeyboardStates = SDL_GetKeyboardState(NULL);

	printf("Window Created\n");
}

void DestroyWindow() {
	SDL_DestroyWindow  (window);
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
	SDL_Quit();
	printf("Window Destroyed\n");
}

void DoEvents() {
	SDL_Event ev;
	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_QUIT:
			close_window = true; break;
		default:
			break;
		}
	}
}

extern void CalcFrameTimes(); // in fps_calc.c
void RenderScreen() {
	SDL_RenderPresent(renderer);
	CalcFrameTimes();
	//SDL_Delay(16); // Stay at 60fps
}

void ClearScreen(SDL_Color color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(renderer);
}

bool ShouldWindowClose() {
	return close_window;
}

// Setters & Getters //

void ToggleFullscreen() {
	SDL_SetWindowFullscreen(window, !(SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN));
}

void SetFullscreen(bool state) {
	SDL_SetWindowFullscreen(window, state);
}
