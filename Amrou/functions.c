#include "functions.h"
#include "perso.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

void initminimap(minimap *m)
{
m->map= IMG_Load("minimap.png");
m->dot= IMG_Load("dot.png");
}
void afficherminimap(minimap m,SDL_Surface* screen)
{
m.posmap.x=screen->w-m.map->w;
m.posmap.y=screen->h-m.map->h; 
SDL_BlitSurface(m.map,NULL,screen,&m.posmap);
m.posdot.x+=m.posmap.x;
m.posdot.y+=m.posmap.y;
SDL_BlitSurface(m.dot,NULL,screen,&m.posdot);
SDL_Flip(screen);
}
void time(int *time)
{
int tempsms;
tempsms= SDL_GetTicks();
*time= tempsms/1000;
}

void MAJMinimap(personne p,minimap *m)
{
m->posdot.x= p.position.x/2;
m->posdot.y= p.position.y/4;
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
printf("box x = %d box y = %d\n",box[i][0],box[i][1]);
for(i=0;i<8;i++)
{
SDL_GetRGB(getpixel(masque,box[i][a],box[i][j]),masque->format,&color.r,&color.g,&color.b);

if (color.r==255 && color.g==255 && color.b==255)
{
collision=1;
printf("collision detected\n");
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

/* Mini map part up */
/* Perso part down */

void initPerso (personne *p ) 
{
  
p->image0= IMG_Load("mario.png") ; 
p->position.x = 100 ;
p->position.y = 550 ;
SDL_SetColorKey(p->image0,SDL_SRCCOLORKEY,SDL_MapRGB(p->image0->format,255,255,255)) ; 
p->sprite.x= 0;
p->sprite.y= 0; 
p->sprite.h= 80;
p->sprite.w= 52;

} 

void afficherPerso (personne p, SDL_Surface *screen) 
{
 
  SDL_BlitSurface (p.image0,&p.sprite, screen , &(p.position) ) ;
printf("pos x = %d y = %d\n",p.position.x,p.position.y);
}

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
    break ; 
   if (event.key.keysym.sym==SDLK_m)
        { 
             p->position.x +=50 ; 
         }
      break ;  
}
 case 1 : 
{  
p->position.x-= 10 ;
 break ; 
 
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


void jump (personne *p)
{
  p->position.h = -28 ;
 p->position.y -= 15 ;   
 
} 

void jump1 (personne *p)
{
  p->position.h = 28 ;
 p->position.y += 15 ; 
 
} 
/* fin partie perso */
