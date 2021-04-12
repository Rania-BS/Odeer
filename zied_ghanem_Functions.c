#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "Functions.h"

//---------------------------------------------------------------------------------------------------------------------
void init(background *b)
{

SDL_Init(SDL_INIT_VIDEO);
b->background=IMG_Load("back.jpg");
b->perso=IMG_Load("yoshi.jpg");
b->camera.x = 0;
b->camera.y = 0;
b->camera.w = 2560;
b->camera.h = 1440;
b->positionperso.x=0;
b->positionperso.y=0;
}

//---------------------------------------------------------------------------------------------------------------------

void afficher(background b , SDL_Surface *screen)
{
SDL_BlitSurface(b.background,NULL,screen,&b.camera);
SDL_BlitSurface(b.perso,NULL,screen,&b.positionperso);
}
//---------------------------------------------------------------------------------------------------------------------

void music(Mix_Music *music)
{
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024);
music=Mix_LoadMUS("musique.mp3");
Mix_PlayMusic(music,-1);
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_right(SDL_Rect *camera, SDL_Rect *positionperso, const int vitesse)
{
  positionperso->x+=15;
  camera->x +=vitesse;
  if(camera->x>=2560-1500)
  {
    camera->x=0;
    positionperso->x=0;
  }
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_left(SDL_Rect *camera, SDL_Rect *positionperso, const int vitesse)
{
  positionperso->x-=15;
  camera->x-=vitesse;
  if(camera->x<=0)
  {
    camera->x=2560-1500;
    positionperso->x=2560-1500;
  }
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_up(SDL_Rect *camera,SDL_Rect *positionperso, const int vitesse)
{
  positionperso->y-=15;
  camera->y-=vitesse;
  if(camera->y<=0)
  {
    camera->y=1440-900;
    positionperso->y=1440-900;
  }

  
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_down(SDL_Rect *camera, SDL_Rect *positionperso, const int vitesse)
{
  positionperso->y+=15;
  camera->y+=vitesse;
  if(camera->y >=1440-900)
  {
    camera->y=0;
    positionperso->y=0;
  }

  
}

