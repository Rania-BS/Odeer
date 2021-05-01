#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <string.h>
#include "header.h"

void affichback(BACKGROUND *back,SDL_Surface *ecran)
{ 

//SDL_Delay(20);
//SDL_BlitSurface( back->fond[0],NULL, ecran,&back->position);

SDL_BlitSurface( back->f,&back->position, ecran,NULL);
}


void intialiser_back(BACKGROUND *back)
{ 

back->f=IMG_Load("stage.png");//FormerlyPNG

if(back->f==NULL)
exit(EXIT_FAILURE);

back->position.x=0;
back->position.y=600;  //a cause du truc vert en haut
back->position.h=1080;
back->position.w=1920;
back->camera.x=0;
back->camera.y=540;  //a cause du truc vert en haut
back->camera.h=1500;
back->camera.w=1920;
}


void intialiser_coin(e_coin *coin,int x,int y)
{
    coin->pos.x=x;
    coin->pos.y=y;
}



void affichercoin(e_coin coin,SDL_Surface *ecran)
{
    SDL_Rect pos;
    pos.x=coin.pos.x-(coin.image_coin)->w;
    pos.y=coin.pos.y;
    SDL_BlitSurface( coin.image_coin,NULL, ecran,&pos);
}



int dep_alea ( int positionmax, int positionmin   )
{
    int pos;
    srand(time(NULL));
    pos=rand()%(positionmax-positionmin+1)+positionmin;


    return pos;
}



void anim_coin(int *i,e_coin *coin)
{
    char lien[40];

    (*i)++;
    if(*i>10)
    {
        *i=1;
    }
    sprintf(lien,"%d.png",*i);
    SDL_Delay(20);

    coin->image_coin = IMG_Load(lien);
}


void Collision_coin(e_coin coin,SDL_Surface *ecran,SDL_Rect pos,int *col)
{ 
//pos.x=pos.x-ecran->w;
  
  *col=1;
  
   if ((pos.y +ecran->h < coin.pos.y + coin.image_coin->h)||(coin.pos.x+coin.image_coin->w < pos.x)||(coin.pos.y+coin.image_coin->h < pos.y)||(coin.pos.x > pos.x+ecran->w ))// trop en bas
   {*col=0;}

   if ((pos.x > coin.pos.x + coin.image_coin->w) ||(coin.pos.y+coin.image_coin->h < pos.y)||(coin.pos.y > pos.y+ecran->h)||(coin.pos.x+coin.image_coin->w > pos.x+ecran->w ))    // trop à droite   
   {*col=0;}
   
   if ((pos.x + ecran->w < coin.pos.x)||(coin.pos.y+coin.image_coin->h < pos.y)||(coin.pos.y > pos.y+ecran->h)||(coin.pos.x < pos.x)) // trop à gauche
   {*col=0;}
   
   
   
   if ((pos.y + ecran->h < coin.pos.y) ||(pos.y > coin.pos.y)||(coin.pos.x+coin.image_coin->w < pos.x)||(coin.pos.x > pos.x+ecran->w ))  // trop en haut
   {*col=0;}

}
