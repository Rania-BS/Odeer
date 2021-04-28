#include "functions.h"
#include "perso.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
/* partie perso */

personne p; 
SDL_Event event ;
initPerso (&p ) ;
/*fin partie perso*/
minimap m;
int boucle=1,temps=0,h,min,col=0;
char buffer[20],str_time[20];
SDL_Rect pos;
pos.x=0;
pos.y=0;
SDL_Surface *screen=NULL;
SDL_Surface *bg=NULL;
SDL_Surface *masque=IMG_Load("masque.png");
// font
TTF_Font* police=NULL;
SDL_Surface *texte=NULL;
SDL_Rect postext;
postext.x=966-75;
postext.y=25;
//
//
SDL_Color white={255,255,255};
TTF_Init();
police=TTF_OpenFont("./fonts/Roboto-Medium.ttf",25);
//
bg=IMG_Load("carte.PNG");
  SDL_Init(SDL_INIT_VIDEO);
  screen= SDL_SetVideoMode(966,964,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
//SDL_BlitSurface(bg,NULL,screen,&pos);
initminimap(&m);
//afficherminimap(m,screen);
while (boucle)
{
time(&temps);
h=temps/60;
min=temps%60;
sprintf(buffer,"%d",h);
strcpy(str_time,buffer);
strcat(str_time,":");
strcpy(buffer,"\0");
sprintf(buffer,"%d",min);
strcat(str_time,buffer);
/*printf("string of mins = %s\n",str_time);
printf("h = %d et mins = %d et temps = %d\n",h,min,temps); */
texte= TTF_RenderText_Blended(police,str_time,white);

SDL_BlitSurface(masque,NULL,screen,&pos);
SDL_BlitSurface(bg,NULL,screen,&pos);
afficherPerso (p,screen);
afficherminimap(m,screen);
MAJMinimap(p,&m);
SDL_BlitSurface(texte,NULL,screen,&postext);
col=0;
/* partie perso */
if (col!=1) {
while ( SDL_PollEvent( &event ) ) 
{ 
switch ( event.type ) 
{
 case SDL_QUIT:
         boucle=0;
break ; 
case SDL_MOUSEMOTION:
	printf("x = %d et y = %d\n",event.motion.x,event.motion.y);
  case SDL_KEYDOWN :
  { 
      switch (event.key.keysym.sym)
     { 
          case SDLK_RIGHT : 
          
           deplacer (&p,0 ) ; 
           animer ( &p,0  ) ; 
           break ; 
          case SDLK_LEFT : 
         deplacer (&p,1 ) ; 
         animer ( &p,1  ) ; 
            break ; 
         case SDLK_UP : 
           jump (&p) ; 
           break ; 
         case SDLK_DOWN: 
           jump1 (&p);
     break ; 
    }
}  
   
 }
 }
 col=collisionPP(p,masque);
} // if collision
/* fin partie perso */
/*SDL_BlitSurface(masque,NULL,screen,&pos);
SDL_BlitSurface(bg,NULL,screen,&pos);
afficherPerso (p,screen);
afficherminimap(m,screen);
MAJMinimap(p,&m);
SDL_BlitSurface(texte,NULL,screen,&postext); */
SDL_Flip(screen);
}
}
