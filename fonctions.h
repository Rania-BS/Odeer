#ifndef FONCTIONS_H_ 
#define FONCTIONS_H_ 
#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h> 
/**
* @struct vie 
* @brief struct for vie
*/
typedef struct 
{
 int nb ; 
 SDL_Surface *vie1 ; /*!< surface. */
 SDL_Surface *vie2 ; /*!< surface. */
 SDL_Surface *vie3 ; /*!< surface. */
 SDL_Surface *gameover ;  /*!< surface. */
  
SDL_Rect ps1 ; /*!< rectangle*/
} vie ; 
/**
* @struct score
* @brief struct for score 
*/
typedef struct
{
    SDL_Rect poss; /*!< rectangle*/
    SDL_Surface *texte;/*!< surface. */
    char chaine[20];
    int scoree;
    int max ; 
}score;

/**
* @struct personne 
* @brief struct for personne
*/
typedef struct 
{

SDL_Surface *image0 , *image1 ; /*!< surface. */
SDL_Rect position ; /*!< rectangle*/
SDL_Rect sprite ; /*!< rectangle*/
int speedup,speeddown,ground,gravity;
int personneisjumping;
vie v; 
score s;
SDL_Rect pos ; /*!< rectangle*/


} personne ; 



void initPerso (personne *p ) ;
void afficherPerso (personne p, SDL_Surface *screen)  ;
void calculerscore (personne *p);
void deplacer (personne *p,int direction ) ; 
void animer ( personne *p, int direction  ) ; 
void apresS( personne *p);
void repterS( personne *p ) ;
void saut(personne *p);

void afficherPersoMULTI (personne h, SDL_Surface *screen) ;
void initPersoMULTI (personne *h )  ; 
void calculerscoreMULTI (personne *h) ; 
void sautMULTI(personne *h);
void deplacerMULTI (personne *h,int direction );
void animerMULTI ( personne *h, int direction  )  ;
void repterSMULTI(personne *h) ;
void apresSMULTI(personne *h);

#endif 
