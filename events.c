#include <SDL.h>
#include <time.h>
#include "mystruct.h"
#include "myhead.h"
#include <time.h>
#include <iostream>

using namespace std;

int touch=0;
bool move_magnetic=false;
extern int pause,start1,black_activate;
extern int max_bullet,power_bullet,power_mag,power_bar,power_bullet;
void load_chunk(std::string rola);
extern int ib;
int vx,vy,dx,dy;
/*------------------------------------------------*/
int event_manager(){
int a=1,i;
float aa,dtev;

SDL_Event ev;
while (SDL_PollEvent(&ev))
{
 		if (ev.type==SDL_QUIT){
			a=0;
			cout<<"Closing Window.."<<endl;
			}
	        switch( ev.type )
		{
        		case SDL_KEYDOWN:
         		       	switch( ev.key.keysym.sym )
				{
		                    case SDLK_LEFT:
        	 	                bar.dx = -1;
					if (start1==0)touch-=1;
					if((power_mag==1)&&(ball.dx==0)&&(ball.dy==0)){
						cout<<"Moving Ball to the left"<<endl;
						ball.dy=0;
						ball.dx=bar.dx;//Same bar direction - activate movement
						ball.vx=1.1*bar.vx;//same bar velocity same bar position- always positive
						move_magnetic=true;//Flag movement under magentic power is activated
						}
                		        break;
	               		    case SDLK_RIGHT:
	                        	bar.dx= 1;
					if (start1==0)touch+=1;
					if((power_mag==1)&&(ball.dx==0)&&(ball.dy==0)){
						cout<<"Moving Ball to the right"<<endl;
						ball.dy=0;
						ball.dx=bar.dx;
						ball.vx=1.1*bar.vx;
						move_magnetic=true;
						}
		               	        break;
		                    case SDLK_UP:
        		                bar.dy = -1;
					if((power_mag==1)&&(ball.dx==0)&&(ball.dy==0)){
						cout<<"Moving Ball up"<<endl;
						ball.dx=0;
						ball.dy=bar.dy;
						ball.vy=1.1*bar.vy;
						move_magnetic=true;
						}
                		        break;
		                    case SDLK_DOWN:
        		                bar.dy =  1;
					if((power_mag==1)&&(ball.dx==0)&&(ball.dy==0)){
						cout<<"Moving Ball down"<<endl;
						ball.dx=0;
						ball.dy=bar.dy;
						ball.vy=0.98*bar.vy;
						ball.y=0.98*ball.y;
						move_magnetic=true;
						}
					break;
		                    case SDLK_w:
					if ((power_mag==0 ) && (start1==1)){
						power_mag=1;
						cout<<"Magnetic Force Activated"<<endl;
						}
					else {
						power_mag=0;
						cout<<"Magnetic Force Deactivated"<<endl;
						}
					break;
		                    case SDLK_e:
					if (power_bar==0){
						power_bar=1;
						cout<<"Security Bar Activated"<<endl;
						}
						
					else {
						power_bar=0;
						cout<<"Security Bar Deactivated"<<endl;
						}
					break;
		                    case SDLK_q:
					if (power_bullet==0){
						power_bullet=1;
						cout<<"Bullets Loaded"<<endl;
						}
					else{
						power_bullet=0;
						cout<<"Bullets Unloaded"<<endl;
						}
					break;
		                    case SDLK_p:
					load_chunk("audio/paused.wav");
					switch (pause){
						case 0:
						 	pause=1;
	               		 	        	break;
						case 1:
							pause=0;
							break;
						default:
							pause=0;
							break;
						}
               		 	        break;
		                    case SDLK_SPACE:
					load_chunk("audio/tic.wav");
					if((pause==0 )&& (start1==0) ){
	        		                ball.dy = 1;
        			                ball.dx = 1;
						start1=1;
						/* Sentitivity mode logic */
						if ((touch > 6) || (touch < -6)){
							if (touch>6) touch=5;
							else touch=-5;
						}
						aa=-(float)(touch)/2.0;
						ball.vx =aa * ball.vy;
						power_mag=0;//avoid magnetizing before o kick 

						}
					touch=0;
					if((start1==1) && (move_magnetic==false) && (power_mag==1)){
						cout<<"Free Magnetic Force"<<endl;
						ball.dy=1;//set unity to direct x-y calculation 
						ball.dx=1;
						ball.vx=vx;//remember what the velocity was with physic logic
						ball.vy=vy;
						}
               		 	        break;
		                    case SDLK_a:
					if ((start1==1) && (power_bullet==1) &&  (ib<max_bullet) ){
						if ( bullet[ib].visible==0 ){
							cout<<"Shoot Bullet"<< endl;
							bullet[ib].visible=1;
							bullet[ib].x=bar.x+bar.w/2;
							bullet[ib].y=bar.y-bullet[ib].h;
							bullet[ib].vx=0;
							bullet[ib].vy=-30;
							}
						ib+=1;
						}
               		 	        break;
	               		    default:
	                	        break;
		                }
		       	        break;
//----------------------
		        case SDL_KEYUP:
			        switch( ev.key.keysym.sym )
			 	{
                        		case SDLK_LEFT:
                			    if( bar.dx< 0 )
		                            	bar.dx = 0;
						if (move_magnetic){
							cout<<"Lost Magnetic at the left"<<endl;
							ball.dx=1;//stop ball magnetic movements
							ball.dy=1;//stop ball magnetic movements
							ball.vx=vx;
							ball.vy=vy;
							move_magnetic=false;//return flag that ball stops

							}
	                		    break;
			                case SDLK_RIGHT:
                			    if( bar.dx > 0 )
		        	                bar.dx = 0;
						if (move_magnetic){
							cout<<"Lost Magnetic Ball at the right"<<endl;
							ball.dx=1;
							ball.dy=1;
							ball.vx=vx;
							ball.vy=vy;
							move_magnetic=false;
							}
                			    break;
			                case SDLK_UP:
        	        		    if( bar.dy < 0 )
			                        bar.dy = 0;
						if (move_magnetic){
							cout<<"Lost Magnetic ball  up"<<endl;
							ball.dy=1;
							ball.dx=1;
							ball.vx=vx;
							ball.vy=vy;
							move_magnetic=false;
							}
                			    break;
		                	case SDLK_DOWN:
	                		    if( bar.dy > 0 )
			                        bar.dy = 0;
						if (move_magnetic){
							cout<<"Lost Manetic Ball down"<<endl;
							ball.dy=1;
							ball.dx=1;
							ball.vx=vx;
							ball.vy=vy;
							move_magnetic=false;
							}
                			    break;
		        	        default:
                			    break;
			        }
			        break;
              	     	default:
                	    break;
	       	}
	}
return a;
}
