#include "integration.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* partie perso below */

/** 
* @brief To init person 
* @param p personne
* @return Nothing 
*/

   //******perso(1)****//
void initPerso (personne *p ) 
{
p->image0= IMG_Load("mario.png") ; 
p->position.x = 100 ;
p->position.y = 935;
p->position2.x=100;
SDL_SetColorKey(p->image0,SDL_SRCCOLORKEY,SDL_MapRGB(p->image0->format,255,255,255)) ; 
p->sprite.x= 0;
p->sprite.y= 0; 
p->sprite.h= 80;
p->sprite.w= 52;

    p->speedup = 1;
    p->speeddown = 20;
    p->ground = 850;
    p->gravity = 0; 
    p->personneisjumping = 0;

  
    p->s.poss.x = 10;
    p->s.poss.y = 40;
    p->s.max = 0;
    p->s.scoree=0 ; 
    char chaine[100];

p->v.nb=3;
p->v.ps1.x=700;
p->v.ps1.y=30;
p->v.vie1 = IMG_Load("viee1.png");
p->v.vie2 = IMG_Load("viee2.png");
p->v.vie3 = IMG_Load("viee3.png");
p->v.gameover = IMG_Load("gameover.png");



}

/** 
* @brief To init personMULTI
* @param h personne
* @return Nothing 
*/
void initPersoMULTI (personne *h ) 
{
h->image0= IMG_Load("mario.png") ; 
h->position.x = 200 ;
h->position.y = 850 ;
SDL_SetColorKey(h->image0,SDL_SRCCOLORKEY,SDL_MapRGB(h->image0->format,255,255,255)) ; 
h->sprite.x= 0;
h->sprite.y= 0; 
h->sprite.h= 80;
h->sprite.w= 52;

    h->speedup = 1;
    h->speeddown = 20;
    h->ground = 850;
    h->gravity = 0; 
    h->personneisjumping = 0;

  
    h->s.poss.x = 1;
    h->s.poss.y = 50;
    h->s.max = 0;
    h->s.scoree=0 ; 
    char chaine[50];

h->v.nb=3;
h->v.ps1.x=700;
h->v.ps1.y=30;
h->v.vie1 = IMG_Load("viee1.png");
h->v.vie2 = IMG_Load("viee2.png");
h->v.vie3 = IMG_Load("viee3.png");
h->v.gameover = IMG_Load("gameover.png");



}

/** 
* @brief To affich perso
* @param p personne
* @param screen the screen 
* @return Nothing 
*/
void afficherPerso (personne p, SDL_Surface *screen) 
{ 
  SDL_BlitSurface (p.image0,&p.sprite, screen , &(p.position) ) ;
 }
/** 
* @brief To afficher vie,score
* @param p personne
* @param screen the screen 
* @return Nothing 
*/
void afficher_scorevie(personne p, SDL_Surface *screen)
{
  SDL_BlitSurface(p.s.texte, NULL, screen, &p.s.poss);

  if (p.v.nb == 3)
    SDL_BlitSurface(p.v.vie3, NULL, screen, &p.v.ps1);

  if (p.v.nb == 2)
    SDL_BlitSurface(p.v.vie2, NULL, screen, &p.v.ps1);
  if (p.v.nb == 1)
    SDL_BlitSurface(p.v.vie1, NULL, screen, &p.v.ps1);
  if (p.v.nb == 0)
  {
    p.v.ps1.x = 0;
    p.v.ps1.y = 0;
    SDL_BlitSurface(p.v.gameover, NULL, screen, &p.v.ps1);
    p.v.nb = 3;
    SDL_Flip(screen);
  }
}


/** 
* @brief To calcul score
* @param p personne
* @return Nothing 
*/
void calculerscore (personne *p)
{ 
   
    TTF_Init();
    SDL_Surface *texte=NULL;
    TTF_Font *police= NULL;
    SDL_Color couleurblanche = {250, 250, 250};

    police = TTF_OpenFont("fast99.ttf", 50);
    if(!police) {
	printf("TTF_OpenFont: %s\n", TTF_GetError());
    }
    if (p->position.x >= p->s.max)
{  
    p->s.max =p->position.x ; 
    p->s.scoree+=1;
    SDL_Delay(10);  
}
   
    sprintf(p->s.chaine,"score:%d",p->s.scoree);
    p->s.texte = TTF_RenderText_Blended(police,p->s.chaine,couleurblanche);

    TTF_CloseFont(police);
    TTF_Quit();
}

/** 
* @brief To move person
* @param p personne
* @param direction the direction 
* @return Nothing 
*/
    //****deplacement***//
void deplacer (personne *p,int direction )
{ 
  SDL_Event event ; 
   SDL_KEYDOWN : 
{
  switch (direction)
{  
  case 0 : 
    { 
     p->position.x+=10 ; // 10
     p->position2.x+=10;
          if (p->position.x +195 > 1440 ) 
  { 
     p->position.x = 1440-195 ; 
     p->position2.x-=5;
  }   
   if (event.key.keysym.sym==SDLK_m)
        { 
             p->position.x +=50 ; 
         }
      break ;  
}
 case 1 : 
{  
p->position.x-= 10 ;
   p->position2.x-=10;
     if (event.key.keysym.sym==SDLK_m)
        { 
             p->position.x -=50 ;
         }
      break ;  
}
}
} 
  if (p->position.x<0)
    {
     p->position.x= 0 ; 
        p->position2.x=0;
    } 
}


/** 
* @brief To animate person
* @param p personne
* @param direction the direction 
* @return Nothing 
*/
      //****animation***//
void animer ( personne *p, int direction  ) 
{
  switch (direction) 
{ 
case 0:
{ 
  p->sprite.y=80;
  if (p->sprite.x >= 52) 
  {
   p->sprite.x =0 ; 
  }
  else 
    p->sprite.x += 52 ; 


}break ; 
case 1 :
{ 
 
  p->sprite.y=0;
  if (p->sprite.x >= 52) 
  {
   p->sprite.x =0 ; 
  }
  else 
    p->sprite.x += 52 ; 
}break ; 
}
} 

/** 
* @brief To initsaut person
* @param p personne
* @return Nothing 
*/

     /****saut**/


void repterS(personne *p)
{
    p->speedup = 0;
    p->gravity = 0;
    p->speeddown = 20;
    p->position.y = 540;
    
}

/** 
* @brief To jump person
* @param p personne
* @return Nothing 
*/

/* 
void saut(personne *p)
{
    if (p->gravity == 0)
    {
        SDL_Delay(p->speedup);
        p->position.y -= (p->position.y / 25);
    } 
    while (p->speedup <= 10)
    {
        p->speedup += 1;
    }
    printf("p pos y = %d\n",p->position.y);
    if (p->position.y < 898)
    { 
        p->gravity = 1;
    } 
    if (p->gravity == 1)
    {

        if (p->speeddown >= 1)
        {
            p->speeddown -= 1;
        }
      
        if (p->position.y >= p->ground) 
          {
            repterS(p);
            p->position.y = 850;
            p->personneisjumping = 0; 
        } 
        if (p->position.y != p->ground)
        {
              p->position.y = 850;
           
        }
    }

  
} */

void sautt (personne *p)
{
        if (p->gravity == 0)
    {
        SDL_Delay(p->speedup);
        p->position.y -= 80;
        p->gravity=1;
        p->personneisjumping=1;
    } else
    {
        p->position.y +=80;
        p->gravity=0;
        p->personneisjumping=0;
    }
}

/** 
* @brief To ajump person
* @param p personne
* @return Nothing 
*/
void apresS(personne *p)
{
    int speeddown;
    speeddown = p->speeddown; 
    while (speeddown >= 1)
    {
        speeddown -= 1;
    }
    if (p->position.y < p->ground) 
    {
        p->position.y = (p->position.y + p->ground);
        SDL_Delay(speeddown);
    }
    while (p->position.y > p->ground) 
    {
        p->position.y = p->ground;
        p->personneisjumping = 0;
    }
    SDL_Delay(20);
}




/* fin partie perso */

/* partie ES below */

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
    int a;
    (*i)++;
    if(*i>10)
    {
        *i=1;
    }
    sprintf(lien,"%d.png",*i);
    
    coin->image_coin = IMG_Load(lien);
}


/*void Collision_coin(e_coin coin,SDL_Surface *ecran,SDL_Rect pos,int *col)
{ 
pos.x=pos.x-ecran->w;
  
  *col=1;
  
   if ((pos.y +ecran->h < coin.pos.y + coin.image_coin->h)||(coin.pos.x+coin.image_coin->w < pos.x)||(coin.pos.y+coin.image_coin->h < pos.y)||(coin.pos.x > pos.x+ecran->w ))// trop en bas
   {*col=0;}

   if ((pos.x > coin.pos.x + coin.image_coin->w) ||(coin.pos.y+coin.image_coin->h < pos.y)||(coin.pos.y > pos.y+ecran->h)||(coin.pos.x+coin.image_coin->w > pos.x+ecran->w ))    // trop à droite   
   {*col=0;}
   
   if ((pos.x + ecran->w < coin.pos.x)||(coin.pos.y+coin.image_coin->h < pos.y)||(coin.pos.y > pos.y+ecran->h)||(coin.pos.x < pos.x)) // trop à gauche
   {*col=0;}
   
   
   
   if ((pos.y + ecran->h < coin.pos.y) ||(pos.y > coin.pos.y)||(coin.pos.x+coin.image_coin->w < pos.x)||(coin.pos.x > pos.x+ecran->w ))  // trop en haut
   {*col=0;}

}*/

int collisionBB(personne p, e_coin coin)
{
int collision=0; 
if ((coin.pos.x>p.pos.x+p.sprite.w) || (p.pos.x>=coin.pos.x+coin.sprite.w) || (p.pos.y>=coin.pos.y+coin.sprite.h) || (coin.pos.y>=p.pos.y+p.sprite.h))
{
collision=0;
}
else 
collision=1;
return collision;
}

/* fin partie ES */

/* Partie minimap below */

void initminimap(minimap *m)
{
m->map= IMG_Load("minimap.jpg");
m->dot= IMG_Load("dot.png");

}

void afficherminimap(minimap m,SDL_Surface* screen)
{
m.posmap.x=0;
m.posmap.y=0;
SDL_BlitSurface(m.map,NULL,screen,&m.posmap);
m.posdot.x+=m.posmap.x-3;
SDL_BlitSurface(m.dot,NULL,screen,&m.posdot);
}

void affichertemps(int *time)
{
int tempsms;
tempsms= SDL_GetTicks();
*time= tempsms/1000;
}

void MAJMinimap(personne p,minimap *m)
{

m->posdot.x=(p.position2.x/6.25);
m->posdot.y= p.position.y/11-p.sprite.h/11;

}

int collisionPP(personne p,SDL_Surface *masque) // edit needed
{
int collision=0,i,j=1,a=0;
SDL_Color color;
int box[8][2];
box[0][0]=p.position.x;box[0][1]=p.position.y;
box[1][0]=p.position.x+(p.sprite.w/2);box[1][1]=p.position.y;
box[2][0]=p.position.x+p.sprite.w;box[2][1]=p.position.y;
box[3][0]=p.position.x;box[3][1]=p.position.y+(p.sprite.h/2);
box[4][0]=p.position.x+p.sprite.w;box[4][1]=p.position.y+(p.sprite.h/2);
box[5][0]=p.position.x;box[5][1]=p.position.y+p.sprite.h;
box[6][0]=p.position.x+(p.image0->w/2);box[6][1]=p.position.y+p.sprite.h;
box[7][0]=p.position.x+p.sprite.w;box[7][1]=p.position.y+p.sprite.h;

for(i=0;i<8;i++) // 1 up -- 2 right -- 3 bottom -- 4 left
{
SDL_GetRGB(getpixel(masque,box[i][a],box[i][j]),masque->format,&color.r,&color.g,&color.b);
if (color.r==255 && color.g==255 && color.b==255)
{
  if (i==0 || i == 1 || i == 2)
    collision = 1;
            else if (i==3)
            collision=4;
                else if (i==4)
                  collision = 2;
                      else if (i==5 || i == 6 || i == 7)
                          collision=3;
}

}

return collision;
}

Uint32 getpixel(SDL_Surface *surface, int x,int y)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

switch (bpp)
{
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
            break;

        case 4:
            return *(Uint32 *)p;
            break;

        default:
            return 0;       /* shouldn't happen, but avoids warnings */
      }
}

/* partie minimap up */

/* Partie background down */

void init_back(background *b)
{

SDL_Init(SDL_INIT_VIDEO);
b->background=IMG_Load("back.jpg");


b->positionperso.x=0;
b->positionperso.y=0;


b->masque = IMG_Load("masque.jpg");
b->posmasque.x=0;
b->posmasque.y=-5;

b->PositionBg.x=0;
b->PositionBg.y=0;
b->camera.x = 0;
b->camera.y = 0;
b->camera.w = 8000;
b->camera.h = 1080;


}

//---------------------------------------------------------------------------------------------------------------------

void afficher_back(background b , SDL_Surface *screen)
{
SDL_BlitSurface(b.masque,NULL,screen,&(b.posmasque));
SDL_BlitSurface(b.background,&(b.camera),screen,&(b.PositionBg));
}
//---------------------------------------------------------------------------------------------------------------------

void music(Mix_Music *music)
{
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024);
music=Mix_LoadMUS("musique.mp3");
Mix_PlayMusic(music,-1);
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_right(background *b, const int vitesse)
{
  
 b->positionperso.x+=2;
  b->camera.x +=vitesse;

if(b->camera.x >=8000-1500)
    {
      b->positionperso.x+=vitesse;
      b->camera.x =8000-1500;
      if(b->positionperso.x>1500)
      {
        b->camera.x = 0;
        b->positionperso.x=0;
      }
    }
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_left(background *b, const int vitesse)
{

 b->positionperso.x-=10;
 b->camera.x-=vitesse;

if(b->camera.x<=0)
    {
      b->positionperso.x-=vitesse;
      b->camera.x =0;
      if(b->positionperso.x<0)
      {
        b->camera.x = 0;
        b->positionperso.x=0;
      }
    }
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_up(background *b, const int vitesse)
{
  b->positionperso.y-=vitesse;
  b->camera.y-=vitesse;
  if(b->positionperso.y<=0)
  {
    b->camera.y=0;
   b->positionperso.y=0;
  }

  
}
//---------------------------------------------------------------------------------------------------------------------
void scrolling_down(background *b, const int vitesse)
{
  b->positionperso.y+=vitesse;
  b->camera.y+=vitesse;
  if(b->positionperso.y >=420)
  {
    b->camera.y=1080-900;
    b->positionperso.y=1080-900;
  }


  
}

/* fin partie background */

/* partie enigme w/ file */

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
bg=IMG_Load("backenigme.jpg");
police=TTF_OpenFont("font.ttf",30);//(nom font, taille)
texte_question=TTF_RenderText_Blended(police,question,couleur_noire);
texte_reponse=TTF_RenderText_Blended(police,reponse,couleur_noire);



//boucle pseudo infinie
int done=1;
SDL_Event event;


while(done){

printf("value of done = %d\n",done);

  //affichage background
  position.x=0;
  position.y=0;
  SDL_BlitSurface(bg,NULL,screen,&position);

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

  case SDL_KEYDOWN:
switch (event.key.keysym.sym) {

  case SDLK_KP1:
if (r==2) { res=1;
done=0; }
  break;

  case SDLK_KP2:
  if (r==4) {res=1;
  done=0; }
  break;

  case SDLK_KP3:
  if (r==1 || r==3) { res=1;
  done=0; }
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

/* fin partie enigme */
