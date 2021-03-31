#pragma once
#include "base.h"


void CreateWindow(const char* title, int width, int height, SDL_WindowFlags flags);
void DestroyWindow();

// Place holder events, just to make the window work, make own sdl event loop later if needed
void DoEvents();
void RenderScreen();
void ClearScreen(SDL_Color color);
bool ShouldWindowClose();

//

void ToggleFullscreen();
void SetFullscreen(bool state);