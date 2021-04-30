#include "integration.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------------- PROGRESS ------------------- */

/* perso part */

// perso done fully (jump can still be improved)

/* fin partie perso */

/* background part */

// Init background -- Done
// Affiche background -- Done
// Music -- Done
// Scrolling -- Done

/* fin partie background */

/* partie minimap */

// Init minimap -- Done (Change minimap background to match the main background)
// Affichage du minimap -- done (problem fil niveau ta3 l pos (l pos ta3 l dot < pos ta3 l perso belwa9t))
// MAJ minimap -- Done (just needs the character's position to update the dot's location)
// time -- Done
// Collision -- No (Needs the character for it to be implemented into the integration)
// Collision -- side of the collision still needs to be developped
// getpixel -- Works.


/* fin partie minimap */

/*  TASKS    --------------------PLEASE UPDATE AFTER EVERY IMPLIMENTATION---------------------------------------- */



void main()
{
    /* lire les evenements */ SDL_Event event;
    /* music du jeu */ Mix_Music *musique;
   /* main surface du jeu */ SDL_Surface *screen=NULL;
    /* background du jeu */
   /* boucle du jeu */ int boucle=1;

    /* partie perso */
    personne p; 
    personne h ;  
    vie v ;     
    score s ;  
    /*fin partie perso*/

    /* background down */
    background bg;
    bool run = true;
    bool bouton[4] = {0};
    const int vitesse= 10;
    /* background up */
    
    /* partie minimap */
    minimap m;
    int temps=0,hours,min;
    char buffer[20],str_time[20];
    SDL_Rect pos;
    pos.x=0;
    pos.y=0;
    // font
    TTF_Font* police=NULL;
    SDL_Surface *texte=NULL;
    SDL_Rect postext;
    SDL_Color white={255,255,255};
    TTF_Init();
    police=TTF_OpenFont("./fonts/Roboto-Medium.ttf",25);
    //
    
    /* initialisation perso */
    initPerso (&p);
    /* fin initialisation perso */

    /* initialisation minimap */
    initminimap(&m);
    /* fin initialisation minimap */

    /* fin partie minimap */

    /* initialisation video */
     SDL_Init(SDL_INIT_VIDEO);
     screen=SDL_SetVideoMode(1440,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
     /* fin initisalisation video */

     /* initialisation du background */
     init_back(&bg);
     /* fin initialisation background */

     /* initialisation du son */ 
        music(musique);
     /* fin initialisation son */

    /* debut boucle du jeu */ while (boucle)
    {

             /* affichage du background */
            afficher_back(bg,screen);
                 /* fin affichage background */
                
                /* affichage du perso */
            afficherPerso (p,screen);
            /* fin affichage perso */

                 /* affichage minimap */
                 afficherminimap(m,screen);
                 /* fin affichage minimap */


                 /* affichage du temps */
                    postext.x=screen->w-250;
                    postext.y=25;
                    time(&temps);
                    hours=temps/60;
                    min=temps%60;
                    sprintf(buffer,"%d ",hours);
                    strcpy(str_time,buffer);
                    strcat(str_time,"min(s) : ");
                    strcpy(buffer,"\0");
                    sprintf(buffer,"%d sec(s)",min);
                    strcat(str_time,buffer);
                    texte= TTF_RenderText_Blended(police,str_time,white);
                    SDL_BlitSurface(texte,NULL,screen,&postext);
                   // printf("time = %s\n",str_time);
                 /* fin affichage temps */

             /* lire les events */    
        while ( SDL_PollEvent( &event ) ) 
        { 
        switch ( event.type ) 
            {
            case SDL_QUIT:
                    boucle=0;
                        break;
                        case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                       
                        case SDLK_RIGHT:
                            scrolling_right(&bg,vitesse);
                            deplacer (&p,0 ) ; 
                            calculerscore (&p);
                            animer ( &p,0  ) ; 
                            break;
                        case SDLK_LEFT:
                            scrolling_left(&bg,vitesse);
                            deplacer (&p,1 ) ; 
                            animer ( &p,1  ) ;
                            break;
                        case SDLK_ESCAPE:
                            run = false;
                            break;
                        case SDLK_SPACE:
                            sautt(&p);
                            if (p.personneisjumping==1)
                            scrolling_up(&bg,vitesse);
                            else
                            scrolling_down(&bg,vitesse);
                        break ; //repterS(&p);
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
                         /* MAJ minimap */
                    MAJMinimap(p,&m);
                 /* fin MAJ Minimap */
        /* fin pollevent */

        /* scrolling of the background above */


            /* DON'T TOUCH THIS FLIP IT MAKES THE GAME SHOW !!! */ 
                    /* ------------------------------- */
                               SDL_Flip(screen);
                    /* ------------------------------- */
            }  

 }
