#include <SDL.h>
#include <stdio.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>



//-----------------------------------------------
extern SDL_Surface *s;
extern SDL_Surface *ballim;
extern SDL_Surface *barim;
extern SDL_Surface *backim;
extern SDL_Surface *brickim;
extern SDL_Surface *textim;
extern SDL_Surface *text;
extern Mix_Music *backmusic;
extern Mix_Chunk *snd;
extern TTF_Font *font_head,*font_start,*font_power;
//-----------------------------------------------
void clean_up(){

SDL_FreeSurface(s);
SDL_FreeSurface(ballim);
SDL_FreeSurface(barim);
SDL_FreeSurface(backim);
SDL_FreeSurface(brickim);
SDL_FreeSurface(text);
SDL_FreeSurface(textim);
TTF_CloseFont(font_head);
TTF_CloseFont(font_start);
TTF_CloseFont(font_power);
Mix_CloseAudio();
TTF_Quit();
SDL_Quit();
Mix_FreeMusic(backmusic);
Mix_FreeChunk(snd);
printf("Cleaning Memory...:(\n");

}
//-----------------------------------------------
