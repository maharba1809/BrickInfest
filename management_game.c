#include <string>
#include <time.h>
#include "mystruct.h"
#include "myhead.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>


extern int level,score,stage_score,up_ini;
extern int pause,start1;
extern SDL_Surface *s;
extern TTF_Font *font_head,*font_start;

SDL_Surface *bsur,*black_text;
SDL_Surface* load_map(std::string map_name , int tran );
SDL_Surface* load_text(std::string msg ,TTF_Font *font);

//void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
void load_pattern(std::string file_name);
void load_chunk(std::string rola);

extern int black_activate;
/*------------------------------------------------*/
void lost_ball(){
TTF_Font *f;
time_t now_time;
time_t end_time;
long black_sec=3,aaa;
char str[100],buf[100],label_lost[100];

	Mix_HaltMusic();
	load_chunk("audio/nice-try-noob-01.wav");
	black_activate=1;
	input.up-=1;
	bsur=load_map("backgrounds/black_metal.bmp",0);
        printf("\t You Lost :( Remain %d Up\n",input.up);
	if (input.up==0){
		printf("Game Over :( \n");
		stage_score=0;
		score=0;
		level=1;
		input.up=up_ini;
                strcpy(label_lost,"Game Over. Loading Level...  ");
		f=font_start;
		black_sec=3;
	} else {
                strcpy(label_lost,"You Lost. Loading Level...  ");
		f=font_head;
		}
/* Set black screen*/
	now_time = time(NULL);
	end_time = now_time + black_sec;
	strcpy(str,label_lost);
        sprintf(buf, "%d",level);
       	strcat(str,buf);
       	strcat(str," Initializing... ");
	while (now_time<end_time){
        	aaa = (end_time-now_time);
        	sprintf(buf, "%lu",aaa);
		strcpy(label_lost,str); /*reutilized as buffer*/
        	strcat(label_lost,buf);

		black_text=load_text(label_lost,f);
		SDL_BlitSurface(bsur, NULL, s, NULL);
		apply_surface((input.width - black_text->w)/2 , input.high - 1.5 * black_text->h ,black_text,s);
		SDL_Flip(s);
		now_time = time(NULL);
	}
	stage_score=score;
	load_level(level);
        initialize_balls();
	start1=0;
}
/*------------------------------------------------*/
void win(){
time_t now_time;
time_t end_time;
long black_sec=2,aaa;
char str[100],buf[100],win_label[100];
	Mix_HaltMusic();
	load_chunk("audio/robot-letsrock.wav");
	bsur=load_map("backgrounds/black_metal.bmp",0);
	black_activate=1;
	score+= input.N*10+100;
	stage_score=score;
        printf("You Won Level %d :) Score %d Ups %d \n",level,score,input.up);
	level+=1;
	stage_score=score;
	start1=0;
	load_level(level);
        initialize_balls();
	now_time = time(NULL);
	end_time = now_time + black_sec;
	strcpy(str,"You Win. Loading Level... ");
        sprintf(buf, "%d",level);
       	strcat(str,buf);
       	strcat(str," in ");
	while (now_time<end_time){
        	aaa = (end_time-now_time);
	        sprintf(buf, "%lu",aaa);
       		strcpy(win_label,str);
        	strcat(win_label,buf);
		black_text=load_text(win_label,font_head);
		SDL_BlitSurface(bsur, NULL, s, NULL);
		apply_surface((input.width - black_text->w)/2 ,input.high-1.5*black_text->h ,black_text,s);
		SDL_Flip(s);
		now_time = time(NULL);
	}
}
