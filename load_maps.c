#include <SDL.h>
#include "mystruct.h"
#include "myhead.h"
#include <stdio.h>
#include <string>
#include <SDL_ttf.h>
#include<time.h>
#include <iostream>
using namespace std;
/*------------------------------------------------*/
time_t now_time,end_time;

extern SDL_Surface *s, *ballim,*barim,brickim,*backim,*bulletim;

extern SDL_Surface *text;
extern TTF_Font *font_head,*font_start,*font_power;

SDL_Surface* lowerbarim;
SDL_Surface* load_text(std::string msg ,TTF_Font *font);
SDL_Surface* load_map(std::string map_name , int tran );
SDL_Surface* textim;


//void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );

/*------------------------------------------------*/
void load_maps(){
SDL_Event ev;
SDL_Surface *text_back;
char str[10],buf[10];
long black_sec=5,aaa;
int text_x=0,text_y=0;

ballim=load_map( "objects/ball.bmp",1);
barim=load_map( "objects/bar.bmp",1);
bulletim=load_map( "objects/rocket.bmp",1);
backim=load_map("backgrounds/front.bmp",0);
lowerbarim=load_map("objects/lowerbar.bmp",1);

text=load_text("Score:",font_head);
textim=load_text("O Options",font_power);

now_time=time(NULL);
end_time = now_time + black_sec;

strcpy(str,"s start");
text_back=load_text(str,font_start);
text_x=(input.width - textim->w ) /2;//x-coordinate text  location
text_y=input.high - text_back->h -textim->h;//y-coordinate text location
textim=load_text("10 Points",font_power);

while (now_time<end_time){
//	aaa=(end_time-now_time);
//	sprintf(buf, "%lu",aaa);
//	strcat(str,buf);
        SDL_BlitSurface(backim, NULL, s, NULL);
        apply_surface((input.width - text_back->w ) /2 , input.high - text_back->h ,text_back,s);
	apply_surface(text_x,text_y,textim,s);
        SDL_Flip(s);
//        now_time = time(NULL);
	SDL_PollEvent(&ev);
	if (ev.type==SDL_QUIT){
        	cout<<"Aborting..."<<endl;
		clean_up();
		exit(0);
		}
	switch( ev.type ){
		case SDL_KEYDOWN:
		switch( ev.key.keysym.sym ){
			case SDLK_s:	 
			cout<<"Start :)"<<endl;
        		now_time = end_time;
               		break;
			}
		break;
		}
        }

}
/*------------------------------------------------*/
SDL_Surface* load_map(std::string map_name , int tran ){
const char * c = map_name.c_str();//converts string to const char*

SDL_Surface *temp,*map;
Uint32 colorkey;
	cout <<"Loading bit map "<< c <<" " <<tran<<endl;
        temp = SDL_LoadBMP(c);
        if (temp == NULL){
                printf("Unable to load bitmap: %s\n", SDL_GetError());
                SDL_FreeSurface(temp);
                exit(0);
        }else{
                map = SDL_DisplayFormat(temp);
                colorkey = SDL_MapRGB( map -> format, 132, 0, 12);
                if ( tran==1 ) SDL_SetColorKey( map, SDL_SRCCOLORKEY, colorkey );
                SDL_FreeSurface(temp);
        }
                return map;
 }
/*------------------------------------------------*/
SDL_Surface* load_text(std::string msg ,TTF_Font *font){
const char * c = msg.c_str();//converts string to const char*

   SDL_Surface *temp;
   SDL_Color text_color = {255, 255, 255};
   temp = TTF_RenderText_Solid(font,c,text_color);
   if (temp == NULL)
   {
      fprintf(stderr, "TTF_RenderText_Solid() Failed:%s ", TTF_GetError());
  //    TTF_Quit();
  //    SDL_Quit();
  //    exit(1);
   }
   return temp;
}
