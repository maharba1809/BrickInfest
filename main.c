#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "myhead.h"
#include "mystruct.h"
#include <SDL_ttf.h>
using namespace std;

/*------------------------------------------------*/
SDL_Surface *s;
SDL_Surface *ballim, *barim,*backim,*bulletim;
SDL_Surface *text;

float dt;
int pause=0,start1=0;
int score=0,stage_score=0,up_ini,level,power_bar,power_bullet;/* score,screen score,life,levels*/
int black_activate=0;


//Define ouside from header to set global
struct Inputs input;
struct Physical ball;
struct Physical bar;
struct Physical back;
struct Physical lowerbar;
struct Physical *brick;
struct Physical *bullet;
struct Physical *texts;

/*------------------------------------------------*/
int main (int argn,char **argv)
 {
int active;
float t1,t2;
struct timespec start, end;

read();
initialize_video();
load_music();
load_maps();
load_level(level);
initialize_balls();
draw();
SDL_Flip(s);

dt=0.01;
active=1;
while (active==1){
	/* Start time */
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
	t1=convert(&start);
	SDL_FillRect(s,NULL,SDL_MapRGBA(s->format,0,0,0,0));
	/* Manage Events, Keyboard, returns 0 if exit event ocurrs. Set position=velocity*/
	active=event_manager();
	/* physics*/ 
	if (pause==0){
		if(start1==1){
			physics_calculation();
			draw();
		        SDL_Flip(s);
		}
	}
	/* End time */
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
	t2=convert(&end);
	if( black_activate==1) black_activate=0;
	else dt =(t2-t1)*input.fps;
	}
clean_up();
}	
