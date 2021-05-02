#include "integration.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------------- PROGRESS ------------------- */

/* perso part Done*/

// perso done fully (jump can still be improved)

/* fin partie perso */

/* ES part like 70% done*/
    // comment functions here
/* fin partie ES */

/* background part Done*/

// Init background -- Done
// Affiche background -- Done
// Music -- Done
// Scrolling -- Done

/* fin partie background */

/* partie minimap Done*/

// Init minimap -- Done
// Affichage du minimap -- done
// MAJ minimap -- Done
// time -- Done
// Collision -- Done
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

    /* partie ES */
    int running=1,y,minES=600, max = 800,z=1,k,i=1,r=500,c=1,j,t=1,test=0,col;
    int numkeys;
	Uint8 * keys;
	Uint32 timer,elapsed;

    e_coin coin[6];
	const int FPS=5;
    SDL_Surface *image;
    SDL_Surface *image2;
    SDL_WM_SetCaption("LOST LIFE",NULL);
    SDL_Rect rect;
    rect.x=dep_alea (800,0);
    rect.y=700;
    /* fin partie ES */

    /* background down */
    background bg;
    bool run = true;
    bool bouton[4] = {0};
    const int vitesse= 10;
    /* background up */
    
    /* partie minimap */
    minimap m;
    int temps=0,hours,min,collision;
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

    /* partie enigme w/ file */

    int e1,e2,e3,rep,correct_ans,nb_enigme;
    e1=0;e2=0;e3=0;rep=0;correct_ans=0;
    nb_enigme=3;
                int testt=0;

    /* fin partie enigme w/ file */
    
    /* initialisation perso */
    initPerso (&p);
    /* fin initialisation perso */

    /* initialisation ES */
    intialiser_coin(&coin[0],700,800);
  /*  intialiser_coin(&coin[1],1900,540);
    intialiser_coin(&coin[2],5108,750);
    intialiser_coin(&coin[3],6180,750);
    intialiser_coin(&coin[4],8826,750);
    intialiser_coin(&coin[5],8136,750); */
    /* fin initialisation ES */

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

                    /* ES */
                        anim_coin(&c,&coin[0]);
                        affichercoin(coin[0] ,bg.background);
                        collisionBB(p,coin);
                        if (col==1)
                        test=1;
                        image=IMG_Load("e1.png");
                        image2=IMG_Load("e2.png");
                        if (k<rect.x)
                        z=-1;
                        else 
                        z=1;
                        k=dep_alea (800,300);
                        rect.x=dep_alea (1000,1050);
                        rect.y=900;
                        if(z==-1)
                        SDL_BlitSurface(image,NULL, bg.background, &rect);
                        if(z==1)
                        SDL_BlitSurface(image2,NULL, bg.background, &rect);
                    /* fin ES */

                 /* MAJ minimap */
                    MAJMinimap(p,&m);
                 /* fin MAJ Minimap */

                 /* affichage minimap */
                 afficherminimap(m,screen);
                 /* fin affichage minimap */


                 /* affichage du temps */
                    postext.x=screen->w-250;
                    postext.y=25;
                    affichertemps(&temps);
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
                 /* fin affichage temps */

            /* collision detection function */
            collision=collisionPP(p,bg.masque);
            /* fin collision detection */

        /* affichage de l'enigme w/file */
            if (p.position.x==500 && testt==0)
            {
                for (int i=0;i<nb_enigme;i++)
                {
                rep++;
                correct_ans+=enigme(screen,&e1,&e2,&e3,rep);
                }
                testt=1;
            }
        /* fin affichage enigme */
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
                        if (collision!=2) {
                            scrolling_right(&bg,vitesse);
                            deplacer (&p,0 ) ; 
                            calculerscore (&p);
                            animer ( &p,0  ) ; 
                        }
                            break;
                        case SDLK_LEFT:
                        if (collision!=4)
                        {
                            scrolling_left(&bg,vitesse);
                            deplacer (&p,1 ) ; 
                            animer ( &p,1  ) ;
                        }
                            break;
                        case SDLK_SPACE:
                        if (collision!=1)
                        {
                            sautt(&p);
                            if (p.personneisjumping==1)
                            scrolling_up(&bg,vitesse);
                            else
                            scrolling_down(&bg,vitesse);
                        }
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

        /* fin pollevent */
        /* scrolling of the background above */
            /* DON'T TOUCH THIS FLIP IT MAKES THE GAME SHOW !!! */ 
                    /* ------------------------------- */
                               SDL_Flip(screen);
                    /* ------------------------------- */
            }  
 }
