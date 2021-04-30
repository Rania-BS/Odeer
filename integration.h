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
SDL_Rect sprite ; 
int speedup,speeddown,ground,gravity;
int personneisjumping;
vie v; 
score s;
SDL_Rect pos ; /*!< rectangle*/
} personne ; 

/* fin partie perso */

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
}background ;

/* fin partie background */

/* ----------------- Calling of functions ----------------- */

/* partie perso */

void initPerso (personne *p ) ;
void afficherPerso (personne p, SDL_Surface *screen)  ;
void calculerscore (personne *p);
void deplacer (personne *p,int direction ) ; 
void animer ( personne *p, int direction  ) ; 
void apresS( personne *p);
void repterS( personne *p ) ;
void saut(personne *p);
void sautt(personne *p);

void afficherPersoMULTI (personne h, SDL_Surface *screen) ;
void initPersoMULTI (personne *h )  ; 
void calculerscoreMULTI (personne *h) ; 
void sautMULTI(personne *h);
void deplacerMULTI (personne *h,int direction );
void animerMULTI ( personne *h, int direction  )  ;
void repterSMULTI(personne *h) ;
void apresSMULTI(personne *h);

/* fin partie perso */

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