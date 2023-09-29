#include "buttons.h"


int isMouseOnButton(Button* button, int x, int y)
{
	return (x >= button->rect.x && x <= button->rect.x + button->rect.w && y >= button->rect.y && y <= button->rect.h);
}

void intiButton(Button* button, int x, int y, int w, int h)
{
	button->rect.x = x;
	button->rect.y = y;
	button->rect.w = w;
	button->rect.h = h;
	button->value = 0;
}