#ifndef MYHEAD_H
#define MYHEAD_H
#include <SDL.h>

void read();
float convert(struct timespec *ts);
void initialize_video();
void initialize_video();
void load_music_back();
void load_music();
//struct Physical;
void load_maps();
void load_level(int stage);
void initialize_balls();
void lost_ball();
void physics_calculation();
int event_manager();
void win();
void load_pause();
void black_screen();
void clean_up();
void draw();
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );

#endif
