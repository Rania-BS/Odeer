#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <time.h>

SDL_Surface *screen;

//*******struct BACK***********
typedef struct BACKGROUND
{ 
SDL_Surface* f;
SDL_Rect position,camera;
}BACKGROUND ;


//********struct ENEMI coin**********

typedef struct e_coin 
{ 
SDL_Surface* image_coin;
SDL_Rect pos;

}e_coin ;


/******* HEAD coin *********/

void intialiser_coin(e_coin *coin,int x,int y);
void affichercoin(e_coin coin,SDL_Surface *ecran);
void anim_coin(int *i,e_coin *coin);
int dep_alea ( int positionmax, int positionmin   );
void Collision_diamond(e_coin coin,SDL_Surface *ecran,SDL_Rect pos,int *col);

#endif
