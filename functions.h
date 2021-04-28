#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"
typedef struct
{
SDL_Surface *map;
SDL_Surface *dot;
SDL_Rect posmap;
SDL_Rect posdot;
} minimap;


void initminimap(minimap *m);
void afficherminimap(minimap m,SDL_Surface *screen);
void MAJMinimap(personne p,minimap *m);
void time(int *time);
int collisionPP(personne p,SDL_Surface *masque);
Uint32 getpixel(SDL_Surface *surface, int x,int y);
#endif // FUNCTIONS_H_INCLUDED
