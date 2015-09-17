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
printf("Initializing Stage %d ...\n",stage);
stage=1;
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
	/*
		load_pattern("patterns/patterns1.in");
   		for (i=0;i < input.N;i++){
			brickim[i]=load_map("objects/brick1.bmp",1);
			if (i==0)brickim[i]=load_map("objects/brick1.bmp",1);
			if (i==10)brickim[i]=load_map("objects/brick1.bmp",1);
			if (i==18)brickim[i]=load_map("objects/brick1.bmp",1);
			if (i==24)brickim[i]=load_map("objects/brick1.bmp",1);
			if (i==27)brickim[i]=load_map("objects/brick1.bmp",1);
			if (i==9)brickim[i]=load_map("objects/brick1.bmp",1);
			if (i==17)brickim[i]=load_map("objects/brick1.bmp",1);
			if (i==23)brickim[i]=load_map("objects/brick1.bmp",1);
			if (i==27)brickim[i]=load_map("objects/brick1.bmp",1);
			if (i==29)brickim[i]=load_map("objects/brick1.bmp",1);

			if (i==1)brickim[i]=load_map("objects/brick11.bmp",1);
			if (i==11)brickim[i]=load_map("objects/brick11.bmp",1);
			if (i==19)brickim[i]=load_map("objects/brick11.bmp",1);
			if (i==25)brickim[i]=load_map("objects/brick11.bmp",1);
			if (i==8)brickim[i]=load_map("objects/brick11.bmp",1);
			if (i==16)brickim[i]=load_map("objects/brick11.bmp",1);
			if (i==22)brickim[i]=load_map("objects/brick11.bmp",1);
			if (i==26)brickim[i]=load_map("objects/brick11.bmp",1);

			if (i==2)brickim[i]=load_map("objects/brick3.bmp",1);
			if (i==12)brickim[i]=load_map("objects/brick3.bmp",1);
			if (i==20)brickim[i]=load_map("objects/brick3.bmp",1);
			if (i==7)brickim[i]=load_map("objects/brick3.bmp",1);
			if (i==15)brickim[i]=load_map("objects/brick3.bmp",1);
			if (i==20)brickim[i]=load_map("objects/brick3.bmp",1);
			if (i==21)brickim[i]=load_map("objects/brick3.bmp",1);

			if (i==3)brickim[i]=load_map("objects/brick2.bmp",1);
			if (i==13)brickim[i]=load_map("objects/brick2.bmp",1);
			if (i==6)brickim[i]=load_map("objects/brick2.bmp",1);
			if (i==14)brickim[i]=load_map("objects/brick2.bmp",1);

			if (i==4)brickim[i]=load_map("objects/brick7.bmp",1);
			if (i==5)brickim[i]=load_map("objects/brick7.bmp",1);

			if (i==30)brickim[i]=load_map("objects/brick6.bmp",1);
			if (i==31)brickim[i]=load_map("objects/brick6.bmp",1);
			}
			*/
	        //load_music_back("Shiny Tech.mp3");
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
   		for (i=0;i<10;i++) brickim[i]=load_map("objects/brick1.bmp",1);
		for (i=10;i<10+9;i++) brickim[i]=load_map("objects/brick2.bmp",1);
		for (i=10+9;i<10+9+8;i++)brickim[i]=load_map("objects/brick3.bmp",1);
		for (i=10+9+8;i<10+9+8+7;i++) brickim[i]=load_map("objects/brick1.bmp",1);
		for (i=10+9+8+7;i<10+9+8+7+8;i++) brickim[i]=load_map("objects/brick2.bmp",1);
		for (i=10+9+8+7+8;i<10+9+8+7+8+9;i++) brickim[i]=load_map("objects/brick3.bmp",1);
		for (i=10+9+8+7+8+9;i<input.N;i++) brickim[i]=load_map("objects/brick1.bmp",1);
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

   		for (i=0;i<4;i++) brickim[i]=load_map("objects/brick6.bmp",1);
		for (i=4;i<4+4;i++) brickim[i]=load_map("objects/brick2.bmp",1);
		for (i=4+4;i<4+4+4;i++) brickim[i]=load_map("objects/brick3.bmp",1);
		for (i=4+4+4;i<4+4+4+7;i++) brickim[i]=load_map("objects/brick1.bmp",1);
		for (i=4+4+4+7;i<4+4+4+7+8;i++) brickim[i]=load_map("objects/brick5.bmp",1);
		for (i=4+4+4+7+8;i<4+4+4+7+8+9;i++) brickim[i]=load_map("objects/brick11.bmp",1);
		for (i=4+4+4+7+8+9;i<4+4+4+7+8+9+10;i++) brickim[i]=load_map("objects/brick1.bmp",1);
		for (i=4+4+4+7+8+9+10;i<4+4+4+7+8+9+10+4;i++) brickim[i]=load_map("objects/brick3.bmp",1);
		for (i=4+4+4+7+8+9+10+4;i<4+4+4+7+8+9+10+4+4;i++) brickim[i]=load_map("objects/brick2.bmp",1);
		for (i=4+4+4+7+8+9+10+4+4;i<input.N;i++) brickim[i]=load_map("objects/brick6.bmp",1);

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
   		for (i=0;i < input.N;i++){
			brickim[i]=load_map("objects/brick12.bmp",1);
			if ( i%2==0 ) brickim[i]=load_map("objects/brick17.bmp",1); 
			if ( i%3==0 ) brickim[i]=load_map("objects/brick18.bmp",1); 
			if ( i%4==0 ) brickim[i]=load_map("objects/brick19.bmp",1); 
			if ( i%5==0 ) brickim[i]=load_map("objects/brick20.bmp",1); 
			}
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

   		for (i=0;i<4;i++) brickim[i]=load_map("objects/brick6.bmp",1);
		for (i=4;i<4+4;i++) brickim[i]=load_map("objects/brick2.bmp",1);
		for (i=4+4;i<4+4+4;i++) brickim[i]=load_map("objects/brick3.bmp",1);
		for (i=4+4+4;i<4+4+4+4;i++) brickim[i]=load_map("objects/brick1.bmp",1);
		for (i=4+4+4+4;i<4+4+4+4+4;i++) brickim[i]=load_map("objects/brick5.bmp",1);
		for (i=4+4+4+4+4;i<4+4+4+4+4+4;i++) brickim[i]=load_map("objects/brick11.bmp",1);

		for (i=4+4+4+4+4+4;i<4+4+4+4+4+4+4;i++) brickim[i]=load_map("objects/brick11.bmp",1);
		for (i=4+4+4+4+4+4+4;i<4+4+4+4+4+4+4+4;i++) brickim[i]=load_map("objects/brick5.bmp",1);
		for (i=4+4+4+4+4+4+4+4;i<4+4+4+4+4+4+4+4+4;i++) brickim[i]=load_map("objects/brick1.bmp",1);
		for (i=4+4+4+4+4+4+4+4+4;i<4+4+4+4+4+4+4+4+4+4;i++) brickim[i]=load_map("objects/brick3.bmp",1);
		for (i=4+4+4+4+4+4+4+4+4+4;i<4+4+4+4+4+4+4+4+4+4+4;i++) brickim[i]=load_map("objects/brick2.bmp",1);
		for (i=4+4+4+4+4+4+4+4+4+4+4;i<input.N;i++) brickim[i]=load_map("objects/brick6.bmp",1);
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


   		for (i=0;i<1;i++) brickim[i]=load_map("objects/brick20.bmp",1);
   		for (i=1;i<1+2;i++) brickim[i]=load_map("objects/brick13.bmp",1);
   		for (i=1+2;i<1+2+3;i++) brickim[i]=load_map("objects/brick20.bmp",1);
   		for (i=1+2+3;i<1+2+3+4;i++) brickim[i]=load_map("objects/brick13.bmp",1);
   		for (i=1+2+3+4;i<1+2+3+4+5;i++) brickim[i]=load_map("objects/brick20.bmp",1);
   		for (i=1+2+3+4+5;i<1+2+3+4+5+6;i++) brickim[i]=load_map("objects/brick13.bmp",1);
   		for (i=1+2+3+4+5+6;i<1+2+3+4+5+6+7;i++) brickim[i]=load_map("objects/brick20.bmp",1);
   		for (i=1+2+3+4+5+6+7;i<1+2+3+4+5+6+7+8;i++) brickim[i]=load_map("objects/brick13.bmp",1);
   		for (i=1+2+3+4+5+6+7+8;i<input.N;i++) brickim[i]=load_map("objects/brick20.bmp",1);
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
		load_pattern("patterns/patterns8.in");
	        load_music_back("audio/Dance Monster.mp3");

   		for (i=0;i < input.N;i++){
			brickim[i]=load_map("objects/brick11.bmp",1);
			if ( i%2==0 ) brickim[i]=load_map("objects/brick2.bmp",1);
			if ( i%3==0 ) brickim[i]=load_map("objects/brick1.bmp",1);
			}
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
		load_pattern("patterns/patterns9.in");
	        load_music_back("audio/One Sly Move.mp3");
   		for (i=0;i < input.N;i++)brickim[i]= brickim[i]=load_map("objects/brick13.bmp",1);


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
		load_pattern("patterns/patterns10.in");
	        load_music_back("audio/Spacial Harvest.mp3");
   		for (i=0;i < input.N;i++){brickim[i]=load_map("objects/square8.bmp",1);
		if (i%2==0) brickim[i]=load_map("objects/square2.bmp",1);
		if (i%3==0) brickim[i]=load_map("objects/square4.bmp",1);
		}

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
		load_pattern("patterns/patterns11.in");
	        load_music_back("audio/Spacial Harvest.mp3");
   		for (i=0;i < input.N;i++){brickim[i]=load_map("objects/sred.bmp",1);
		}

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
   		for (i=0;i < input.N;i++){
		brickim[i]=load_map("objects/bloody_brick9.bmp",1);
	if((i==1)||(i==2)||(i==3))brickim[i]=load_map("objects/bloody_brick10.bmp",1);
	if((i==11)||(i==18)||(i==24)||(i==31)||(i==37)||(i==44)||(i==50))brickim[i]=load_map("objects/bloody_brick7.bmp",1);
	if((i==15)||(i==21)||(i==28)||(i==34)||(i==41)||(i==47)||(i==54))brickim[i]=load_map("objects/bloody_brick8.bmp",1);
	if((i==13)||(i==26)||(i==39)||(i==52)||(i==58)||(i==59))brickim[i]=load_map("objects/bloody_brick10.bmp",1);
		}
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
   		for (i=0;i < input.N;i++){
			brickim[i]=load_map("objects/bloody_brick7.bmp",1);
			if((i==6)||(i==9)||(i==11)||(i==12)||(i==21)||(i==22)||(i==33)||(i==34))brickim[i]=load_map("objects/bloody_brick9.bmp",1);
			if((i>=0)&&(i<=5))brickim[i]=load_map("objects/bloody_brick8.bmp",1);
			if((i==14)||(i==18)||(i==19)||(i==24)||(i==25)||(i==26)||(i==30)||(i==31))brickim[i]=load_map("objects/bloody_brick1.bmp",1);
		}
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
//   		for (i=0;i < input.N;i++)brickim[i]=load_map("objects/bloody_brick9.bmp",1);

/*
   		for (i=0;i < input.N;i++){
		brickim[i]=load_map("objects/bloody_brick10.bmp",1);
		if((i>=7)&&(i<=14)||(i>=63)&&(i<=70))brickim[i]=load_map("objects/bloody_brick7.bmp",1);
		if((i>=35)&&(i<=42))brickim[i]=load_map("objects/bloody_brick8.bmp",1);
		if((i>=18)&&(i<=19))brickim[i]=load_map("objects/bloody_brick9.bmp",1);
		if((i==24)||(i==27)||(i==50)||(i==53))brickim[i]=load_map("objects/bloody_brick5.bmp",1);
		}
*/
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
   		for (i=0;i < input.N;i++){
		brickim[i]=load_map("objects/bloody_brick9.bmp",1);
		}
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
   		for (i=0;i < input.N;i++){brickim[i]=load_map("objects/bloody_brick9.bmp",1);
		}
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
   		for (i=0;i < input.N;i++){brickim[i]=load_map("objects/bloody_brick9.bmp",1);
		}
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
   		for (i=0;i < input.N;i++){brickim[i]=load_map("objects/bloody_brick9.bmp",1);
		}
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
   		for (i=0;i < input.N;i++)brickim[i]=load_map("objects/square13.bmp",1);
		break;
	}
/*printf("\tlevel:%d vx:%f vy:%f N:%d vx:%f vy:%f...\n",stage,ball.vx,ball.vy,input.N,bar.vx,bar.vy);*/
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
