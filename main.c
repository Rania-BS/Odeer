#include "functions.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>




int main()
{
    int hauteur_fenetre = 800,
        largeur_fenetre = 1100;



    SDL_Init(SDL_INIT_VIDEO);

    //FENETRE PRINCIPALE
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(largeur_fenetre, hauteur_fenetre, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("My Game", NULL); // titre de la fenetre

//declaration et initialisation elements enigme
int e1,e2,e3,rep,correct_ans,nb_enigme;
e1=0;e2=0;e3=0;rep=0;correct_ans=0;
nb_enigme=3;

for (int i=0;i<nb_enigme;i++)
{
  rep++;
 correct_ans+=enigme(screen,&e1,&e2,&e3,rep);
}

 



    SDL_Quit();

    return 0;
}
