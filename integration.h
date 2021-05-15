#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

/* partie perso */

typedef struct
{
    SDL_Rect poss; /*!< rectangle*/
    SDL_Surface *texte;/*!< surface. */
    char chaine[20];
    int scoree;
    int max ; 
} score;

typedef struct 
{
 int nb ; 
 SDL_Surface *vie1 ; 
 SDL_Surface *vie2 ; 
 SDL_Surface *vie3 ; 
 SDL_Surface *gameover ;  
  
SDL_Rect ps1 ; 
} vie ; 

typedef struct 
{
SDL_Surface *image0 ,*image1 ;
SDL_Rect position ;
SDL_Rect position2;
SDL_Rect sprite ; 
int speedup,speeddown,ground,gravity;
int personneisjumping;
vie v; 
score s;
SDL_Rect pos ; /*!< rectangle*/
} personne ; 

/* fin partie perso */

/* partie ENTITE SECONDAIRE */

//********struct ENEMI coin**********

typedef struct e_coin 
{ 
SDL_Surface* image_coin;
SDL_Rect pos;
SDL_Rect sprite;
}e_coin ;


/******* HEAD coin *********/

void intialiser_coin(e_coin *coin,int x,int y);
void affichercoin(e_coin coin,SDL_Surface *ecran);
void anim_coin(int *i,e_coin *coin);
int dep_alea ( int positionmax, int positionmin   );
int collisionBB(personne p, e_coin coin);

/* fin partie ES */

/* partie minimap */

typedef struct
{
SDL_Surface *map;
SDL_Surface *dot;
SDL_Rect posmap;
SDL_Rect posdot;
} minimap;

/* fin partie minimap */

/* partie background */

typedef struct 
{
     SDL_Surface *background;
     SDL_Surface *perso;
     SDL_Rect PositionBg;
     SDL_Rect positionperso;
     SDL_Rect camera;
     SDL_Surface *masque;
     SDL_Rect posmasque;
}background ;

/* fin partie background */

/* ----------------- Calling of functions ----------------- */

/* partie perso */

void initPerso (personne *p ) ;
void afficherPerso (personne p, SDL_Surface *screen)  ;
void afficher_scorevie(personne p, SDL_Surface *screen) ; 
void calculerscore (personne *p);
void deplacer (personne *p,int direction ) ; 
void animer ( personne *p, int direction  ) ; 
void apresS( personne *p);
void repterS( personne *p ) ;
void saut(personne *p);
void sautt(personne *p);

void initPersoMULTI (personne *h )  ; 

/* fin partie perso */

/* partie minimap */
void initminimap(minimap *m);
void afficherminimap(minimap m,SDL_Surface *screen);
void MAJMinimap(personne p,minimap *m);
void affichertemps(int *time);
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

/* partie enigme w/ file */

int enigme (SDL_Surface *screen,int *e1,int *e2,int *e3,int rep );

/* fin partie enigme */

/* single player */

void singleplayer(SDL_Surface *screen);

/**

/* menu part */

void indexpage(SDL_Surface *screen,Mix_Music *music);
void optionspage(SDL_Surface *screen,Mix_Music *music);
void play(SDL_Surface *screen,Mix_Music *music);

/* fin part menu */

#endif // FUNCTIONS_H_INCLUDED
