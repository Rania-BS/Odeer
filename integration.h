#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"

typedef struct
{
SDL_Surface *map;
SDL_Surface *dot;
SDL_Rect posmap;
SDL_Rect posdot;
} minimap;

typedef struct 
{
     SDL_Surface *background;
     SDL_Surface *perso;
     SDL_Rect PositionBg;
     SDL_Rect positionperso;
     SDL_Rect camera;
}background ;

/* partie minimap */
void initminimap(minimap *m);
void afficherminimap(minimap m,SDL_Surface *screen);
void MAJMinimap(personne p,minimap *m);
void time(int *time);
int collisionPP(personne p,SDL_Surface *masque);
Uint32 getpixel(SDL_Surface *surface, int x,int y);
/* partie minimap */

/* partie background */
void init_back(background *b);
void afficher_back(background b,SDL_Surface *screen );
void music(Mix_Music *music);
void scrolling_right(background *b, const int vitesse);
void scrolling_left(background *b, const int vitesse);
void scrolling_up(background *b, const int vitesse);
void scrolling_down(background *b, const int vitesse);
/* partie background */

#endif // FUNCTIONS_H_INCLUDED