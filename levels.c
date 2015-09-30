#include <stdio.h>
#include <cstring>
//#include <string>
#include <stdlib.h>
#include <iostream>
#include "mystruct.h"
#include <SDL.h>
#include <algorithm>

using namespace std;

extern SDL_Surface *backim,*bsur,*ballim,*barim;
extern int level;
SDL_Surface **brickim;//Set global and fills in load_level
SDL_Surface* load_map(std::string map_name, int tran );
void load_music_back(std::string rola);
void load_pattern(std::string file_name);
extern int max_bullet;


void load_level(int stage){
int i,num,j;

cout<<"Initializing Stage "<<stage<<endl;

switch(stage){
	case 1:
		ball.vx=0;
		ball.vy=-20;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas1.bmp",0);
		load_pattern("patterns/patterns1.in");
	        load_music_back("audio/8bit Dungeon Level.mp3");
		break;
	case 2:
		ball.vx=0;
		ball.vy=-21;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas2.bmp",0);
		load_pattern("patterns/patterns2.in");
	        load_music_back("audio/Trips It.mp3");
		break;
	case 3:
		ball.vx=0;
		ball.vy=-22;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas3.bmp",0);
		load_pattern("patterns/patterns3.in");
	        load_music_back("audio/Ice Flow.mp3");
		break;
	case 4:
		ball.vx=0;
		ball.vy=-22;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas4.bmp",0);
		load_pattern("patterns/patterns4.in");
	        load_music_back("audio/In a Heartbeat.mp3");
		break;
	case 5:
		ball.vx=0;
		ball.vy=-27;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas5.bmp",0);
		load_pattern("patterns/patterns5.in");
	        load_music_back("audio/Cut and Run.mp3");
		break;
	case 6:
		ball.vx=0;
		ball.vy=-25;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas6.bmp",0);
		load_pattern("patterns/patterns6.in");
	        load_music_back("audio/Long Time Coming.mp3");

		break;
	case 7:
		ball.vx=0;
		ball.vy=-26;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas7.bmp",0);
		load_pattern("patterns/patterns7.in");
	        load_music_back("audio/Dance Monster.mp3");

		break;
	case 8:
		ball.vx=0;
		ball.vy=-27;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas8.bmp",0);
		load_pattern("patterns/patterns8.in");
	        load_music_back("audio/One Sly Move.mp3");

		break;
	case 9:
		ball.vx=0;
		ball.vy=-28;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas9.bmp",0);
		load_pattern("patterns/patterns9.in");
	        load_music_back("audio/Spacial Harvest.mp3");

		break;
	case 10:
		ball.vx=0;
		ball.vy=-20;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas10.bmp",0);
		load_pattern("patterns/patterns10.in");
	        load_music_back("audio/Spacial Harvest.mp3");

		break;
	case 11:
		ball.vx=0;
		ball.vy=-20;
		bar.vx=15;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas11.bmp",0);
		load_pattern("patterns/patterns11.in");
	        load_music_back("audio/Spacial Harvest.mp3");

		break;
	case 12:
		ball.vx=0;
		ball.vy=-20;
		bar.vx=25;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas12.bmp",0);
		load_pattern("patterns/patterns12.in");
	        load_music_back("audio/Spacial Harvest.mp3");

		break;
	case 13:
		ball.vx=0;
		ball.vy=-20;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas13.bmp",0);
		load_pattern("patterns/patterns13.in");
	        load_music_back("audio/Spacial Harvest.mp3");

		break;
	case 14:
		ball.vx=0;
		ball.vy=-28;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas14.bmp",0);
		load_pattern("patterns/patterns14.in");
	        load_music_back("audio/Spacial Harvest.mp3");

		break;
	case 15:
		ball.vx=0;
		ball.vy=-28;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas15.bmp",0);
		load_pattern("patterns/patterns15.in");
	        load_music_back("audio/Spacial Harvest.mp3");

		break;
	case 16:
		ball.vx=0;
		ball.vy=-28;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas16.bmp",0);
		load_pattern("patterns/patterns16.in");
	        load_music_back("audio/Spacial Harvest.mp3");

		break;
	case 17:
		ball.vx=0;
		ball.vy=-28;
		bar.vx=40;
		bar.vy=0;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas17.bmp",0);
		load_pattern("patterns/patterns17.in");
	        load_music_back("audio/Lightless Dawn.mp3");
		break;

	default :
		ball.vx=0;
		ball.vy=-25;
		bar.vx=50;
		bar.vy=10;
		ball.dx=0;
		ball.dy=0;
		bar.dx=0;
		bar.dy=0;
		backim=load_map("backgrounds/lineas10.bmp",0);
		load_pattern("patterns/patterns10.in");
	        load_music_back("audio/Dance Monster.mp3");
		load_pattern("patterns/patterns13.in");
		break;
	}
}
/*---------------------------------*/
  void load_pattern(std::string file_name){
  const char * c = file_name.c_str();//converts string to const char*

  /*   char *file_name;*/
    char line[80];

    int i;
    FILE *fp;
    char *token;
    char *name;
    //char *imagen_name;
    //std::string imagen_name;
    std::string search = ",";

    fp = fopen(c,"r");
    if( fp == NULL ){
	  cout<<"Error while opening the file " <<c<<endl;
	  exit(0);
    }
    i=0;
    while( ( fgets(line,80,fp) ) != NULL )i+=1;
    fclose(fp);

    input.N=i;
    brick=(struct Physical *)malloc(sizeof(struct Physical)*input.N);
    brickim=(struct SDL_Surface **)malloc(sizeof(SDL_Surface)*input.N);
    i=0;
    fp = fopen(c,"r");
    while(( fgets(line,80,fp ) ) != NULL ){
	  name = strtok(line, search.c_str());
	  token = strtok(NULL,search.c_str());
	  std::string imagen_name(strtok(NULL,search.c_str()));	
	  if('\n' == imagen_name[imagen_name.size() - 1])
	    imagen_name = imagen_name.substr(0, imagen_name.size() - 1);	 
	  brick[i].x=(int)atof(name);
	  brick[i].y=(int)atof(token);
	  brickim[i]=load_map(imagen_name,1);	 
	  i+=1;
	  }
    fclose(fp);
    
  }
