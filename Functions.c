#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "Functions.h"

//---------------------------------------------------------------------------------------------------------------------
void init_back(background *b)
{

SDL_Init(SDL_INIT_VIDEO);
b->background=IMG_Load("back.jpg");
b->perso=IMG_Load("yoshi.jpg");


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

