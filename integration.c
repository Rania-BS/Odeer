#include "integration.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* partie perso below */

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
p->position.y = 935;
p->position2.x=100;
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
  // SDL_BlitSurface(p.s.texte, NULL, screen, &p.s.poss);

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
     p->position.x+=10 ; // 10
     p->position2.x+=10;
          if (p->position.x +195 > 1440 ) 
  { 
     p->position.x = 1440-195 ; 
     p->position2.x-=5;
  }   
   if (event.key.keysym.sym==SDLK_m)
        { 
             p->position.x +=50 ; 
         }
      break ;  
}
 case 1 : 
{  
p->position.x-= 10 ;
   p->position2.x-=10;
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
        p->position2.x=0;
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

/* 
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
    printf("p pos y = %d\n",p->position.y);
    if (p->position.y < 898)
    { 
        p->gravity = 1;
    } 
    if (p->gravity == 1)
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

  
} */

void sautt (personne *p)
{
        if (p->gravity == 0)
    {
        SDL_Delay(p->speedup);
        p->position.y -= 80;
        p->gravity=1;
        p->personneisjumping=1;
    } else
    {
        p->position.y +=80;
        p->gravity=0;
        p->personneisjumping=0;
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

/* fin partie perso */

/* Partie minimap below */

void initminimap(minimap *m)
{
m->map= IMG_Load("minimap.jpg");
m->dot= IMG_Load("dot.png");
}
void afficherminimap(minimap m,SDL_Surface* screen)
{
m.posmap.x=0;
m.posmap.y=0;
SDL_BlitSurface(m.map,NULL,screen,&m.posmap);
m.posdot.x+=m.posmap.x-3;
SDL_BlitSurface(m.dot,NULL,screen,&m.posdot);
}
void time(int *time)
{
int tempsms;
tempsms= SDL_GetTicks();
*time= tempsms/1000;
}

void MAJMinimap(personne p,minimap *m)
{

m->posdot.x=(p.position2.x/6.25);
m->posdot.y= p.position.y/11-p.sprite.h/11;
//printf("dot pos x = %d y = %d\n",m->posdot.x,m->posdot.y);

}

int collisionPP(personne p,SDL_Surface *masque)
{
int collision=0,i,j=1,a=0;
SDL_Color color;
int box[8][2];
box[0][0]=p.position.x;box[0][1]=p.position.y;
box[1][0]=p.position.x+(p.sprite.w/2);box[1][1]=p.position.y;
box[2][0]=p.position.x+p.sprite.w;box[2][1]=p.position.y;
box[3][0]=p.position.x;box[3][1]=p.position.y+(p.sprite.h/2);
box[4][0]=p.position.x+p.sprite.w;box[4][1]=p.position.y+(p.sprite.h/2);
box[5][0]=p.position.x;box[5][1]=p.position.y+p.sprite.h;
box[6][0]=p.position.x+(p.image0->w/2);box[6][1]=p.position.y+p.sprite.h;
box[7][0]=p.position.x+p.sprite.w;box[7][1]=p.position.y+p.sprite.h;
for(i=0;i<8;i++)
for(i=0;i<8;i++)
{
SDL_GetRGB(getpixel(masque,box[i][a],box[i][j]),masque->format,&color.r,&color.g,&color.b);

if (color.r==255 && color.g==255 && color.b==255)
{
collision=1;
}
}
return collision;
}

Uint32 getpixel(SDL_Surface *surface, int x,int y)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

switch (bpp)
{
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
            break;

        case 4:
            return *(Uint32 *)p;
            break;

        default:
            return 0;       /* shouldn't happen, but avoids warnings */
      }
}

/* partie minimap up */

/* Partie background down */

void init_back(background *b)
{

SDL_Init(SDL_INIT_VIDEO);
b->background=IMG_Load("back.jpg");


b->positionperso.x=0;
b->positionperso.y=0;


b->PositionBg.x=0;
b->PositionBg.y=0;


b->camera.x = 0;
b->camera.y = 0;
b->camera.w = 8000;
b->camera.h = 1080;
}

//---------------------------------------------------------------------------------------------------------------------

void afficher_back(background b , SDL_Surface *screen)
{

SDL_BlitSurface(b.background,&(b.camera),screen,&(b.PositionBg));
}
//---------------------------------------------------------------------------------------------------------------------

void music(Mix_Music *music)
{
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024);
music=Mix_LoadMUS("musique.mp3");
Mix_PlayMusic(music,-1);
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_right(background *b, const int vitesse)
{
  
 b->positionperso.x+=2;
  b->camera.x +=vitesse;

if(b->camera.x >=8000-1500)
    {
      b->positionperso.x+=vitesse;
      b->camera.x =8000-1500;
      if(b->positionperso.x>1500)
      {
        b->camera.x = 0;
        b->positionperso.x=0;
      }
    }
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_left(background *b, const int vitesse)
{

 b->positionperso.x-=10;
 b->camera.x-=vitesse;

if(b->camera.x<=0)
    {
      b->positionperso.x-=vitesse;
      b->camera.x =0;
      if(b->positionperso.x<0)
      {
        b->camera.x = 0;
        b->positionperso.x=0;
      }
    }
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_up(background *b, const int vitesse)
{
  b->positionperso.y-=vitesse;
  b->camera.y-=vitesse;
  if(b->positionperso.y<=0)
  {
    b->camera.y=0;
   b->positionperso.y=0;
  }

  
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_down(background *b, const int vitesse)
{
  b->positionperso.y+=vitesse;
  b->camera.y+=vitesse;
  if(b->positionperso.y >=420)
  {
    b->camera.y=1080-900;
    b->positionperso.y=1080-900;
  }


  
}

/* fin partie background */