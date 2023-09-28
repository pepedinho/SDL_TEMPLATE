#include <SDL2/SDL.h>
#include <stdio.h>

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

    int bruh = 1;
    printf("%d", bruh);
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
