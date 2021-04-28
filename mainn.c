#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "Functions.h"

int main ()
{
SDL_Surface *screen=NULL;
background b;
bool run = true;
bool bouton[4] = {0};
const int vitesse= 10;
Mix_Music *musique;


SDL_Event event ;
screen =SDL_SetVideoMode(1500,900,32,SDL_HWSURFACE |SDL_DOUBLEBUF);
init_back(&b);
music(musique);
while(run) {
        
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    run = false;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                       
                        case SDLK_RIGHT:
                            bouton[0] = 1;
                            break;
                        case SDLK_LEFT:
                            bouton[1] = 1;
                            break;
                        case SDLK_UP :
                            bouton[2]= 1;
                            break;
                        case SDLK_DOWN:
                            bouton[3] = 1;
                            break;
                        case SDLK_ESCAPE:
                            run = false;
                            break;
                    }
                    break;

                case SDL_KEYUP:
                    switch(event.key.keysym.sym)
                    {
                        
                        case SDLK_RIGHT:
                            bouton[0] = 0;
                            break;
                        case SDLK_LEFT:
                            bouton[1] = 0;
                            break;
                        case SDLK_UP :
                            bouton[2]= 0;
                            break;
                        case SDLK_DOWN:
                            bouton[3] = 0;
                            break;
                    }
                    break;
            }
        }
if(bouton[0])
        {
          scrolling_right(&b,vitesse);
}
if(bouton[1])
        {
          scrolling_left(&b,vitesse);
}
if(bouton[2])
        {
          scrolling_up(&b,vitesse);
        }
if(bouton[3])
        {
          scrolling_down(&b,vitesse);
        }
             
afficher_back(b,screen );

SDL_Flip(screen);

       
    }
    SDL_FreeSurface(b.background);
    SDL_FreeSurface(b.perso);
    SDL_Quit();
return 0 ;
}

