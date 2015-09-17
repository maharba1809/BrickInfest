#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "mystruct.h"
#include <stdio.h>
#include <string>
#include <iostream>

extern SDL_Surface *s;
int volback;

TTF_Font *font_head,*font_start,*font_power;
using namespace std;
TTF_Font* load_font(std::string font_name,int size_font);

void initialize_video()
{
	volback=50;
        printf("Initializing Audio Settings...\n");
        if( SDL_Init(SDL_INIT_AUDIO)<0 ){
		printf("SDL_Init failed: %s\n", SDL_GetError());
                exit(0);
	        }

        if ( Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096) < 0 ){
               fprintf(stderr,"SDL_Mixer ERROR: %s\n",Mix_GetError());
                exit(0);
	        }
	Mix_VolumeMusic(volback);
        printf("Audio Done :) \n");


	printf("Initializing Video...\n ");
        if( SDL_Init(SDL_INIT_VIDEO)<0 ){
                fprintf(stderr,"Could not initialize SDL: %s\n",SDL_GetError());
                exit(0);
        	}
	printf("Done :)\n");
	SDL_WM_SetCaption("Infest Brick", "Playing");
        printf("Initializing Surface...\n");
        s = SDL_SetVideoMode(input.width,input.high,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
        if(!s){
                fprintf(stderr,"Could not set video mode: %s\n",SDL_GetError());
                exit(0);
	        }
        printf("Done :) \n");
        printf("Initializing TTF Fonts...\n");
	if (TTF_Init() != 0)
	{
		fprintf(stderr,"TTF_Init() Failed: %s \n",TTF_GetError());
		SDL_Quit();
		exit(1);
		}
        printf("Done :)\n");

font_head=load_font("fonts/FreeSans.ttf",17);/*Only font is loaded and is used to load text function*/
font_start=load_font("fonts/Auptimagh AH.ttf",30);/*Only font is loaded and is used to load text function*/
font_power=load_font("fonts/Auptimagh AH.ttf",15);
}
//-------------------------------------------------------------------
TTF_Font* load_font(std::string font_name,int size_font){
const char * c = font_name.c_str();//converts string to const char*

   TTF_Font *f;
/*   char *font_name;
   int size_font;*/
/*   font_name="FreeSans.ttf";
   size_font=17;*/
cout << c <<endl;
   f = TTF_OpenFont(c, size_font);
   if (f == NULL)
   {
      fprintf(stderr, "TTF_OpenFont() Failed: %s \n", TTF_GetError());
              TTF_Quit();
              SDL_Quit();
              exit(1);
   }
   cout << "Text TTF Initialized." <<c << " Size " << size_font<<endl;
   return f;
}


