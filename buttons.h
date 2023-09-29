#pragma once
#include <SDL2/SDL.h>

typedef struct {
	SDL_Rect rect;
	int value;
} Button;

int isMouseOnButton(Button* button, int x, int y);
void intiButton(Button* button, int x, int y, int w, int h);