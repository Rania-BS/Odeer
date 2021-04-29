/**
*@file main.c
*/
#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include "fonctions.h"


int main ()
 { 
personne p ;
personne h ;  
vie v ;     
score s ;                               
SDL_Event event ;
SDL_Surface *screen=NULL , *carte=NULL ;
SDL_Rect positioncarte ;
  
int a=1 ;
initPerso (&p ) ;
initPersoMULTI (&h) ; 
 if (SDL_Init(SDL_INIT_VIDEO) != 0 ) 
{ printf ("unuable to initialize SDL : %s \n ",SDL_GetError() ) ; 
return 1 ; 
}

screen = SDL_SetVideoMode (966,964,32,SDL_HWSURFACE | SDL_RESIZABLE ) ;
carte = IMG_Load("carte.PNG") ; 

 positioncarte.x = 0 ;
 positioncarte.y = 0 ;

 SDL_EnableKeyRepeat (10,10) ; 

while (a)
 { 
while ( SDL_PollEvent( &event ) ) 
{ 
switch ( event.type ) 
{
 case SDL_QUIT:
         a=0;
break ; 
  case SDL_KEYDOWN :
  { 
      switch (event.key.keysym.sym)
     {   
          
          case SDLK_RIGHT : 
           deplacer (&p,0 ) ; 
           calculerscore (&p);
           animer ( &p,0  ) ; 
           break ; 

         case SDLK_LEFT :
           deplacer (&p,1 ) ; 
           animer ( &p,1  ) ;

           break ; 
         
         case SDLK_SPACE:
           saut(&p);
          break ; repterS(&p);
         //MULTI//
          case SDLK_b : 
           deplacerMULTI (&h,0 ) ; 
           calculerscoreMULTI (&h);
           animerMULTI ( &h,0  ) ; 
           break ; 
             
          case SDLK_c :
           deplacerMULTI (&h,1 ) ; 
           animerMULTI ( &h,1  ) ;
            break ; 
          
          case SDLK_v:
           sautMULTI(&h);
          break ; repterSMULTI(&h);
   
              
       
    }
}  
  
   
 }
 
SDL_BlitSurface (carte,NULL, screen , &positioncarte ) ;
afficherPerso (p,screen) ;
afficherPersoMULTI (h,screen) ; 
SDL_Flip(screen);
}
}
 return 0; 
}
 


 
