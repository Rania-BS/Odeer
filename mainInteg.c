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
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

if (SDL_Init( SDL_INIT_AUDIO) != 0)
{
printf("Erreur: %s\n",SDL_GetError());
}
if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024) == -1)
{
printf("Erreur : %s\n",SDL_GetError());
}

SDL_Surface *screen=NULL;

Mix_Music *music;
music = Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music, -1);

  screen= SDL_SetVideoMode(1680,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  indexpage(screen,music); //
}
