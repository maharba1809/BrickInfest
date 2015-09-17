#include <SDL.h>
#include <math.h>
#include "mystruct.h"
#include "myhead.h"
#include <SDL_ttf.h>
#include <string>
#include <iostream>

using namespace std;

SDL_Surface* load_text(std::string msg ,TTF_Font *font);

extern SDL_Surface *s;
extern SDL_Surface *ballim,*barim,*backim,*bulletim,*lowerbarim,*textim;
extern SDL_Surface **brickim;
extern SDL_Surface *text;
extern int stage_score,level;
extern TTF_Font *font_head,*font_power;
extern int power_bar,power_bullet,max_bullet,max_text;

void draw(){
int i;
char str[100],buf[100];
//Draw Ball Bar Back
	apply_surface( back.x,back.y,backim,s);
	apply_surface( bar.x,bar.y,barim,s);
	apply_surface( ball.x,ball.y,ballim,s);
//Draw Bricks
	for (i=0;i<input.N;i++)
		if (brick[i].visible==1)
			apply_surface( brick[i].x,brick[i].y,brickim[i],s);

//Draw bullets
	if ( power_bullet==1 )
		for (i=0;i<max_bullet;i++)
			if (bullet[i].visible==1)
				apply_surface( bullet[i].x,bullet[i].y,bulletim,s);
//Draw Lower Bar
	if(power_bar==1)apply_surface( lowerbar.x,lowerbar.y,lowerbarim,s);
//Draw Power Text
	for( i=0;i<max_text;i++)
		if (texts[i].visible==1)apply_surface(texts[i].x,texts[i].y,textim,s);



	strcpy(str,"Score ");
	sprintf(buf, "%d ", stage_score);
	strcat(str,buf);

	strcat(str,"          Level ");
	sprintf(buf, "%d ", level);
	strcat(str,buf);

	strcat(str,"         Up ");
	sprintf(buf, "%d ", input.up);
	strcat(str,buf);

	strcat(str,"          Velocity ");
	sprintf(buf, "%d ", (int)sqrt(ball.vx*ball.vx + ball.vy*ball.vy));
	strcat(str,buf);

//Draw Score Card
	text=load_text(str,font_head);
	apply_surface((input.width - text->w)/2,0,text,s);


}
//------------------------------------------------
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ){
    //Holds offsets
    SDL_Rect offset;
    //Get offsets
    offset.x = x;
    offset.y = y;
    //Blit
   if( SDL_BlitSurface( source, NULL, destination, &offset )!=0){
	fprintf(stderr,"ERROR in Blit_Surface %s %d %d \n",SDL_GetError(),x,y);
	}
}
