/** 
*@file fonctions.c
*/
#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include "fonctions.h"
#include <string.h>

/** 
* @brief To init person 
* @param p personne
* @return Nothing 
*/

   //******perso(1)****//
void initPerso (personne *p ) 
{
p->image0= IMG_Load("mario.png") ; 
p->position.x = 100 ;
p->position.y = 850 ;
SDL_SetColorKey(p->image0,SDL_SRCCOLORKEY,SDL_MapRGB(p->image0->format,255,255,255)) ; 
p->sprite.x= 0;
p->sprite.y= 0; 
p->sprite.h= 80;
p->sprite.w= 52;

    p->speedup = 1;
    p->speeddown = 20;
    p->ground = 850;
    p->gravity = 0; 
    p->personneisjumping = 0;

  
    p->s.poss.x = 10;
    p->s.poss.y = 40;
    p->s.max = 0;
    p->s.scoree=0 ; 
    char chaine[100];

p->v.nb=3;
p->v.ps1.x=700;
p->v.ps1.y=30;
p->v.vie1 = IMG_Load("viee1.png");
p->v.vie2 = IMG_Load("viee2.png");
p->v.vie3 = IMG_Load("viee3.png");
p->v.gameover = IMG_Load("gameover.png");



}

/** 
* @brief To init personMULTI
* @param h personne
* @return Nothing 
*/
void initPersoMULTI (personne *h ) 
{
h->image0= IMG_Load("mario.png") ; 
h->position.x = 200 ;
h->position.y = 850 ;
SDL_SetColorKey(h->image0,SDL_SRCCOLORKEY,SDL_MapRGB(h->image0->format,255,255,255)) ; 
h->sprite.x= 0;
h->sprite.y= 0; 
h->sprite.h= 80;
h->sprite.w= 52;

    h->speedup = 1;
    h->speeddown = 20;
    h->ground = 850;
    h->gravity = 0; 
    h->personneisjumping = 0;

  
    h->s.poss.x = 1;
    h->s.poss.y = 50;
    h->s.max = 0;
    h->s.scoree=0 ; 
    char chaine[50];

h->v.nb=3;
h->v.ps1.x=700;
h->v.ps1.y=30;
h->v.vie1 = IMG_Load("viee1.png");
h->v.vie2 = IMG_Load("viee2.png");
h->v.vie3 = IMG_Load("viee3.png");
h->v.gameover = IMG_Load("gameover.png");



}

/** 
* @brief To affich perso
* @param p personne
* @param screen the screen 
* @return Nothing 
*/
void afficherPerso (personne p, SDL_Surface *screen) 
{ 
  
  SDL_BlitSurface (p.image0,&p.sprite, screen , &(p.position) ) ;
  SDL_BlitSurface(p.s.texte, NULL, screen, &p.s.poss);

 if (p.v.nb==3)
  SDL_BlitSurface(p.v.vie3,NULL,screen,&p.v.ps1) ;

if (p.v.nb==2) 
  SDL_BlitSurface(p.v.vie2,NULL,screen,&p.v.ps1) ; 
if (p.v.nb==1)
  SDL_BlitSurface(p.v.vie1,NULL,screen,&p.v.ps1) ; 
if (p.v.nb==0)
{
   p.v.ps1.x=0 ; 
   p.v.ps1.y=0;
   SDL_BlitSurface(p.v.gameover,NULL,screen,&p.v.ps1) ;
   p.v.nb=3 ; 
    SDL_Flip(screen) ;
   SDL_Delay (4) ; 
    p.v.ps1.x=100 ; 
    p.v.ps1.y=150; 

}
}
/** 
* @brief To affich persoMULTI
* @param h personne
* @param screen the screen 
* @return Nothing 
*/
void afficherPersoMULTI (personne h, SDL_Surface *screen) 
{ 
  
  SDL_BlitSurface (h.image0,&h.sprite, screen , &(h.position) ) ;
  SDL_BlitSurface(h.s.texte, NULL, screen, &h.s.poss);

 if (h.v.nb==3)
  SDL_BlitSurface(h.v.vie3,NULL,screen,&h.v.ps1) ;

if (h.v.nb==2) 
  SDL_BlitSurface(h.v.vie2,NULL,screen,&h.v.ps1) ; 
if (h.v.nb==1)
  SDL_BlitSurface(h.v.vie1,NULL,screen,&h.v.ps1) ; 
if (h.v.nb==0)
{
   h.v.ps1.x=0 ; 
   h.v.ps1.y=0;
   SDL_BlitSurface(h.v.gameover,NULL,screen,&h.v.ps1) ;
   h.v.nb=3 ; 
    SDL_Flip(screen) ;
   SDL_Delay (4) ; 
    h.v.ps1.x=100 ; 
    h.v.ps1.y=150; 

}
}
/** 
* @brief To calcul score
* @param p personne
* @return Nothing 
*/
void calculerscore (personne *p)
{ 
   
    TTF_Init();
    SDL_Surface *texte=NULL;
    TTF_Font *police= NULL;
    SDL_Color couleurblanche = {250, 250, 250};

    police = TTF_OpenFont("fast99.ttf", 50);
    if(!police) {
	printf("TTF_OpenFont: %s\n", TTF_GetError());
    }
    if (p->position.x >= p->s.max)
{  
    p->s.max =p->position.x ; 
    p->s.scoree+=1;
    SDL_Delay(10);  
}
   
    sprintf(p->s.chaine,"score:%d",p->s.scoree);
    p->s.texte = TTF_RenderText_Blended(police,p->s.chaine,couleurblanche);

    TTF_CloseFont(police);
    TTF_Quit();
}
/** 
* @brief To calcul scoreMULTI
* @param h personne
* @return Nothing 
*/
void calculerscoreMULTI (personne *h)
{ 
   
    TTF_Init();
    SDL_Surface *texte=NULL;
    TTF_Font *police= NULL;
    SDL_Color couleurblanche = {250, 250, 250};

    police = TTF_OpenFont("fast99.ttf", 50);
    if(!police) {
	printf("TTF_OpenFont: %s\n", TTF_GetError());
    }
    if (h->position.x >= h->s.max)
{  
    h->s.max =h->position.x ; 
    h->s.scoree+=1;
    SDL_Delay(10);  
}
   
    sprintf(h->s.chaine,"score:%d",h->s.scoree);
    h->s.texte = TTF_RenderText_Blended(police,h->s.chaine,couleurblanche);

    TTF_CloseFont(police);
    TTF_Quit();
}

/** 
* @brief To move person
* @param p personne
* @param direction the direction 
* @return Nothing 
*/
    //****deplacement***//
void deplacer (personne *p,int direction )
{ 
  SDL_Event event ; 
   SDL_KEYDOWN : 
{
  switch (direction)
{  
  case 0 : 
    { 
     p->position.x+=10 ; 
   if (event.key.keysym.sym==SDLK_m)
        { 
             p->position.x +=50 ; 
         }
      break ;  
}
 case 1 : 
{  
p->position.x-= 10 ;
     if (event.key.keysym.sym==SDLK_m)
        { 
             p->position.x -=50 ; 
         }
      break ;  
}
}
} 
  if (p->position.x<0)
    {
     p->position.x= 0 ; 
    } 
  if (p->position.x +195 > 966 ) 
  { 
     p->position.x = 966-195 ; 
  }   
}


/** 
* @brief To animate person
* @param p personne
* @param direction the direction 
* @return Nothing 
*/
      //****animation***//
void animer ( personne *p, int direction  ) 
{
  switch (direction) 
{ 
case 0:
{ 
  p->sprite.y=80;
  if (p->sprite.x >= 52) 
  {
   p->sprite.x =0 ; 
  }
  else 
    p->sprite.x += 52 ; 


}break ; 
case 1 :
{ 
 
  p->sprite.y=0;
  if (p->sprite.x >= 52) 
  {
   p->sprite.x =0 ; 
  }
  else 
    p->sprite.x += 52 ; 
}break ; 
}
} 

/** 
* @brief To initsaut person
* @param p personne
* @return Nothing 
*/

     /****saut**/


void repterS(personne *p)
{
    p->speedup = 0;
    p->gravity = 0;
    p->speeddown = 20;
    p->position.y = 540;
    
}

/** 
* @brief To jump person
* @param p personne
* @return Nothing 
*/
void saut(personne *p)
{
    
    if (p->gravity == 0)
    {
        SDL_Delay(p->speedup);
        p->position.y -= (p->position.y / 25);
    }
    while (p->speedup <= 10)
    {
        p->speedup += 1;
    }
    if (p->position.y <= 790)
    {
        p->gravity = 1;
    }
    while (p->gravity == 1)
    {

        if (p->speeddown >= 1)
        {
            p->speeddown -= 1;
        }
      
        if (p->position.y >= p->ground) 
          {
            repterS(p);
            p->position.y = 850;
            p->personneisjumping = 0; 
        }
        if (p->position.y != p->ground)
        {
              p->position.y = 850;
           
        }
    }

  
}
/** 
* @brief To ajump person
* @param p personne
* @return Nothing 
*/
void apresS(personne *p)
{
    int speeddown;
    speeddown = p->speeddown; 
    while (speeddown >= 1)
    {
        speeddown -= 1;
    }
    if (p->position.y < p->ground) 
    {
        p->position.y = (p->position.y + p->ground);
        SDL_Delay(speeddown);
    }
    while (p->position.y > p->ground) 
    {
        p->position.y = p->ground;
        p->personneisjumping = 0;
    }
    SDL_Delay(20);
}


/** 
* @brief To move personMULTI
* @param h personne
* @param direction the direction 
* @return Nothing 
*/

void deplacerMULTI (personne *h,int direction )
{ 
  SDL_Event event ; 
   SDL_KEYDOWN : 
{
  switch (direction)
{  
  case 0 : 
    { 
     h->position.x+=10 ; 
   if (event.key.keysym.sym==SDLK_m)
        { 
             h->position.x +=50 ; 
         }
      break ;  
}
 case 1 : 
{  
h->position.x-= 10 ;
     if (event.key.keysym.sym==SDLK_m)
        { 
             h->position.x -=50 ; 
         }
      break ;  
}
}
} 
  if (h->position.x<0)
    {
     h->position.x= 0 ; 
    } 
  if (h->position.x +195 > 966 ) 
  { 
     h->position.x = 966-195 ; 
  }   
}

/** 
* @brief To animate personMULTI
* @param h personne
* @param direction the direction 
* @return Nothing 
*/
      //****animation***//
void animerMULTI ( personne *h, int direction  ) 
{
  switch (direction) 
{ 
case 0:
{ 
  h->sprite.y=80;
  if (h->sprite.x >= 52) 
  {
   h->sprite.x =0 ; 
  }
  else 
    h->sprite.x += 52 ; 


}break ; 
case 1 :
{ 
 
  h->sprite.y=0;
  if (h->sprite.x >= 52) 
  {
   h->sprite.x =0 ; 
  }
  else 
    h->sprite.x += 52 ; 
}break ; 
}
} 

/** 
* @brief To initsaut personMULTI
* @param h personne
* @return Nothing 
*/


     /****saut**/


void repterSMULTI(personne *h)
{
    h->speedup = 0;
    h->gravity = 0;
    h->speeddown = 20;
    h->position.y = 540;
}

/** 
* @brief To jump personMULTI
* @param h personne
* @return Nothing 
*/
void sautMULTI(personne *h)
{
    
    if (h->gravity == 0)
    {
        SDL_Delay(h->speedup);
        h->position.y -= (h->position.y / 25);
    }
    while (h->speedup <= 10)
    {
        h->speedup += 1;
    }
    if (h->position.y <= 790)
    {
        h->gravity = 1;
    }
    while (h->gravity == 1)
    {

        if (h->speeddown >= 1)
        {
            h->speeddown -= 1;
        }
      
        if (h->position.y >= h->ground)
        {
            repterS(h);
            h->position.y = 850;
            h->personneisjumping = 0; 
        }
        if (h->position.y != h->ground) 
        {
            h->position.y = 850;
        }
    }

  
}
/** 
* @brief To ajump person
* @param h personne
* @return Nothing 
*/
void apresSMULTI(personne *h)
{
    int speeddown;
    speeddown = h->speeddown; 
    while (speeddown >= 1)
    {
        speeddown -= 1;
    }
    if (h->position.y < h->ground) 
    {
        h->position.y = (h->position.y + h->ground);
        SDL_Delay(speeddown);
    }
    while (h->position.y > h->ground) 
    {
        h->position.y = h->ground;
        h->personneisjumping = 0;
    }
    SDL_Delay(20);
}




















 

 

  
  
  

