#include "functions.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>







int enigme (SDL_Surface *screen,int *e1,int *e2,int *e3,int rep ){
//lecture aleatoire des questions et reponses a partir du fichier

int nb_ligne_fichier=4;


FILE* fichier_question=NULL;
FILE* fichier_reponse=NULL;

char question[256]=""; // enregistre question dans chaine
char reponse[256]=""; // enregistre reponse dans chaine

int res=0;//donne le resultat de la resolution : vrai->1 | faux->0 (par defaut)
int r=0;//enregistre la val aleatoire

//enregistrer un nombre de ligne aleatoire dans e(i) =>enigme(i)
do {
  srand(time(NULL));

  r=rand()%nb_ligne_fichier+1;


} while(r==(*e1) ||r==(*e3) ||r==(*e2));

if (rep==1) (*e1)=r;
if (rep==2) (*e2)=r;
if(rep==3) (*e3)=r;

fichier_question=fopen("question.txt","r");
fichier_reponse=fopen("reponse.txt", "r");

int cont_ligne=0;
while (fgets(question,256,fichier_question)!=NULL && fgets(reponse,256,fichier_reponse)!=NULL){

cont_ligne++;

if(cont_ligne==r)
break;

}

//affichage des questions et reponses dans l'ecran / la fenetre
TTF_Init();

//declaration
SDL_Surface *texte_question=NULL, *texte_reponse=NULL, *bg=NULL;
SDL_Rect  position;
TTF_Font *police=NULL;
SDL_Color couleur_noire={0,0,0}; //type RBG

//initialisation
bg=IMG_Load("back.jpg");
police=TTF_OpenFont("font.ttf",30);//(nom font, taille)
texte_question=TTF_RenderText_Blended(police,question,couleur_noire);
texte_reponse=TTF_RenderText_Blended(police,reponse,couleur_noire);



//boucle pseudo infinie
int done=1;
SDL_Event event;

while(done){



  //affichage question
  position.x=150;
  position.y=200;
  SDL_BlitSurface(texte_question,NULL,screen,&position);

  //affichage reponse
  position.x=150;
  position.y=400;
  SDL_BlitSurface(texte_reponse,NULL,screen,&position);

  SDL_Flip(screen);


//recuperation de la reponse

if(SDL_PollEvent(&event)){
switch (event.type) {

      case SDL_QUIT:
       done=0;
  break;

  case SDL_KEYDOWN:
switch (event.key.keysym.sym) {

  case SDLK_KP1:
if (r==2) res=1;
done=0;
  break;

  case SDLK_KP2:
  if (r==4) res=1;
  done=0;
  break;

  case SDLK_KP3:
  if (r==1 || r==3) res=1;
  done=0;
  break;

}
  break;
}//fin switch event
}



}//fin while

TTF_CloseFont(police);
TTF_Quit();
SDL_FreeSurface(texte_reponse);
SDL_FreeSurface(texte_question);
SDL_FreeSurface(bg);

TTF_Quit();
return res;
}

