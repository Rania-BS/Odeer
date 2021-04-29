#include "integration.h"
#include "perso.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* Partie minimap below */

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
/*b->perso=IMG_Load("yoshi.jpg");


b->positionperso.x=0;
b->positionperso.y=0;
*/

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
SDL_BlitSurface(b.perso,NULL,screen,&(b.positionperso));
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

if(b->camera.x >=8000-1440)
    {
      b->positionperso.x+=vitesse;
      b->camera.x =8000-1440;
      if(b->positionperso.x>1440)
      {
        b->camera.x = 0;
        b->positionperso.x=0;
      }
    }
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_left(background *b, const int vitesse)
{

 b->positionperso.x-=2;
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