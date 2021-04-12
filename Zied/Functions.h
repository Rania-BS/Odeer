#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct 
{
     SDL_Surface *background;
     SDL_Surface *perso;
     SDL_Rect camera;
     SDL_Rect positionperso;
}background ;

void init(background *b);
void afficher(background b , SDL_Surface *screen );
void music(Mix_Music *music);
void scrolling_right(SDL_Rect *camera, SDL_Rect *positionperso, const int vitesse);
void scrolling_left(SDL_Rect *camera, SDL_Rect *positionperso, const int vitesse);
void scrolling_up(SDL_Rect *camera,SDL_Rect *positionperso, const int vitesse);
void scrolling_down(SDL_Rect *camera, SDL_Rect *positionperso, const int vitesse);
