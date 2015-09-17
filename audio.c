#include "mystruct.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <iostream>

Mix_Music *backmusic;
Mix_Chunk *snd;
using namespace std;
extern int volback;
void load_music_back(std::string rola);
void load_chunk(std::string rola);

//-------------------------------------------------------------------------//
void load_music(){
	load_music_back("audio/Lightless Dawn.mp3");
}
//-------------------------------------------------------------------------//
void load_music_back(std::string rola){
const char * c = rola.c_str();//converts string to const char*
//        ifa(Mix_PlayingMusic()==0) Mix_FreeMusic(backmusic);
	Mix_HaltMusic();
	if(Mix_PlayingMusic()==1)Mix_PauseMusic();
        backmusic=Mix_LoadMUS(c);
        if (backmusic == NULL){
                cout<<"No sound File: " << c <<" was Found ERROR:"<<SDL_GetError()<<endl;
                exit(0);
        }

	Mix_PlayMusic(backmusic,-1);
	cout<<"Playing Music :)"<<endl;
	
}
/*---------------------------------------*/
void load_chunk(std::string rola){
const char * c = rola.c_str();//converts string to const char*
        snd=Mix_LoadWAV(c);
        if (snd == NULL){
                cout<<"No sound File: " << c <<" ERROR:"<<SDL_GetError()<<endl;
               // exit(0);
        }
//	if(Mix_PlayingMusic()==1)Mix_PauseMusic();
        Mix_VolumeMusic(100);
	Mix_PlayChannel( -1, snd, 0 );
	//Mix_Resume(2);
}
