#include <SDL2/SDL.h>
#include <stdio.h>
#include "buttons.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;    

int initSDL();
void cleanUp();

#undef main 

int main(int argc, char* argv[])
{
    if (initSDL() < 0)
    {
        return -1;
    } 

    Button addButton;
    intiButton(&addButton, 100, 100, 100, 50);

    int quit = 0;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
				SDL_GetMouseState(&mouseX, &mouseY);
				printf("Clic de souris : x=%d, y=%d\n", mouseX, mouseY);
                if (isMouseOnButton(&addButton, mouseX, mouseY))
                {
                    addButton.value++;
                    printf("Compteur : %d\n", addButton.value);
					fflush(stdout);
                }
                printf("Positon du boutton : x=%d, y=%d, w=%d, h=%d\n", addButton.rect.x, addButton.rect.y, addButton.rect.w, addButton.rect.h);
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderFillRect(renderer, &addButton.rect);

        SDL_RenderPresent(renderer);
    }


    cleanUp(); 

    return 0;
}


int initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Erreur lors de l'initialisation de la SDL : %s\n", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow("Game Ball", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        fprintf(stderr, "Erreur lors de la creation de la fenetre : %s\n", SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (renderer == NULL) {
        fprintf(stderr, "Erreur lors de l'initialisation du rendu : %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}

void cleanUp()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
