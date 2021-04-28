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
     SDL_Rect PositionBg;
     SDL_Rect positionperso;
     SDL_Rect camera;
}background ;



void init_back(background *b);
void afficher_back(background b,SDL_Surface *screen );
void music(Mix_Music *music);
void scrolling_right(background *b, const int vitesse);
void scrolling_left(background *b, const int vitesse);
void scrolling_up(background *b, const int vitesse);
void scrolling_down(background *b, const int vitesse);





