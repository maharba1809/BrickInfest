#include <SDL.h>
#include "mystruct.h"
#include "myhead.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

extern SDL_Surface *s;
extern SDL_Surface *ballim,*barim,*backim,*bulletim,*lowerbarim,*textim;
extern SDL_Surface **brickim;
extern int power_bar;
int ib;

void initialization_brick();
SDL_Surface* load_map(std::string map_name , int tran );
extern int max_bullet,max_text;

void initialize_balls()
{
	int n;
//Ball
	ball.x=(input.width-ballim->w)/2.0;
	if (power_bar==1)ball.y=input.high-ballim->h-barim->h-lowerbarim->h;
	else ball.y=input.high-ballim->h-barim->h;

	ball.w=ballim->w;
	ball.h=ballim->h;
//Bar
	bar.x=(input.width-barim->w)/2.0;
	if (power_bar==1)bar.y=input.high-barim->h-lowerbarim->h;
	else bar.y=input.high-barim->h-1;
	bar.w=barim->w;
	bar.h=barim->h;
//Bricks
	initialization_brick();
//Background	
	back.x=0;
	back.y=0;
	back.w=backim->w;
	back.h=backim->h;
//Bullet	
	bullet=(struct Physical *)malloc(sizeof(struct Physical)*max_bullet);
	for (n=0;n < max_bullet;n++) {
		bullet[n].vx=0;
	        bullet[n].vy=0;
	        bullet[n].w=bulletim->w;
	        bullet[n].h=bulletim->h;
		bullet[n].dx=1;
		bullet[n].dy=1;
		bullet[n].visible=0;
		}
	ib=0;
//Lower Bar
	lowerbar.x=0;
	lowerbar.y=input.high-lowerbarim->h;
//Texts
	texts=(struct Physical *)malloc(sizeof(struct Physical)*max_text);
	for (n=0;n < max_text;n++) {
		texts[n].x=0;
	        texts[n].y=0;
		texts[n].vx=0;
	        texts[n].vy=20;
	        texts[n].w=textim->w;
	        texts[n].h=textim->h;
		texts[n].dx=1;
		texts[n].dy=1;
		texts[n].visible=0;
		}
}
//-------------------------------------------------------------------------
void initialization_brick(){
	int n;
/*	brick=(struct Physical *)malloc(sizeof(struct Physical)*input.N);*/
	if ( brick == NULL){
		printf("Error in brick allocating the data array.\n");
		exit(0);
	}
	for (n=0;n < input.N;n++) {
		brick[n].vx=0;
	        brick[n].vy=0;
	        brick[n].w=brickim[n]->w;
	        brick[n].h=brickim[n]->h;
		brick[n].dx=0;
		brick[n].dy=0;
		brick[n].visible=1;
	}	
}
//-------------------------------------------------------------------------
