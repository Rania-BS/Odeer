#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <string.h>
#include "header.h"
#include "fonction.c"

void main()
{
int running=1,y,min=600, max = 800,i=1,r=500,c=1,j,t=1,test=0,col;

int numkeys;
	Uint8 * keys;

	Uint32 timer,elapsed;

e_coin coin[6];
BACKGROUND back;
	const int FPS=5;


SDL_Event event;
SDL_Surface *ecran=NULL ;

SDL_Surface *image;
SDL_Surface *image2;
SDL_Init(SDL_INIT_VIDEO);
ecran=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("LOST LIFE",NULL);
SDL_Rect pos;

intialiser_back(&back);
//intialiser_entite(&entite);
intialiser_coin(&coin[0],700,690);
intialiser_coin(&coin[1],1900,540);
intialiser_coin(&coin[2],5108,750);
intialiser_coin(&coin[3],6180,750);
intialiser_coin(&coin[4],8826,750);
intialiser_coin(&coin[5],8136,750);


while(running)
{

SDL_PollEvent(&event);

for(j=0;j<6;j++)
{anim_coin(&c,&coin[j]);} 



affichback(&back,ecran);
for(j=0;j<6;j++)
   {
     affichercoin(coin[j] ,ecran);
   }

Collision_coin(coin[j],ecran,pos,&col);
if (col==1)
{test=1;}

image=IMG_Load("e1.png");
image2=IMG_Load("e2.png");

SDL_Rect rect;
int k=dep_alea (800,300);
rect.x=dep_alea (800,0);
rect.y=700;

int z=1;

if (k<rect.x)
z=-1;
else 
z=1;


		rect.x=dep_alea (900,1050);
		rect.y=700;


	if(z==-1)
		SDL_BlitSurface(image,NULL, ecran, &rect);

		

if(z==1)
		SDL_BlitSurface(image2,NULL, ecran, &rect);
		
		




SDL_Flip(ecran);
}
SDL_FreeSurface(back.f);
SDL_FreeSurface(ecran);		

}

