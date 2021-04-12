#ifndef FONCTIONS_H_ 
#define FONCTIONS_H_ 
#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
typedef struct 
{
SDL_Surface *image0 ,*image1 ;
SDL_Rect position ;
SDL_Rect sprite ; 
//int x,y;
int box[8][2];
} personne ; 

/*typedef struct 
{
  SDL_Surface *iscore ; 
SDL_Rect ps ; 
int score ; 
} score ; */

typedef struct 
{
 int nb ; 
 SDL_Surface *vie1 ; 
 SDL_Surface *vie2 ; 
 SDL_Surface *vie3 ; 
 SDL_Surface *gameover ;  
  
SDL_Rect ps1 ; 
} vie ; 




void initPerso (personne *p ) ;
 

//void initscore (score *s) ;

void initvie (vie *vie) ;


void afficherPerso (personne p, SDL_Surface *screen)  ;

void afficherVie (vie vie, SDL_Surface *screen) ; 

/*void afficherScore(score *s, SDL_Surface *screen) ; */

void deplacer (personne *p,int direction ) ; 
void animer ( personne *p, int direction  ) ; 
void jump (personne *p) ; 
void jump1 (personne *p) ; 
 





#endif 
