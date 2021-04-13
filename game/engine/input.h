#pragma once
#include "base.h"


bool IsKeyDown(SDL_Scancode key);
Vec2i GetMousePosition(void);

// SDL_BUTTON_LEFT / SDL_BUTTON_RIGHT
bool IsMouseKeyDown(int key);
bool IsMouseOver(SDL_Rect shape);

// CONTROLLERS //

void InitController();
void CloseController();
bool IsControllerKeyDown(int key);
