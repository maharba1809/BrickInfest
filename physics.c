#include "mystruct.h"
#include <SDL.h>
#include <math.h>
#include "myhead.h"
#include <iostream>


using namespace std;
extern float dt;
extern int score,stage_score,level;
extern int power_bar,power_bullet,power_mag;
extern int max_bullet,maxpower_bar,max_power_mag;
extern SDL_Surface* lowerbarim;
extern int vx,vy,dx,dy;
extern bool move_magnetic;

int found_col;/*used by collision, kinematics_ball*/
void load_chunk(std::string rola);

void object_collisions(struct Physical *ball,struct Physical *o );
void detect_collision(struct Physical *ball, struct Physical *o,float xi, float yi, float x, float y);

bool wall_collisions_man(struct Physical *o,struct Inputs *input );
bool wall_collisions_auto(struct Physical *o,struct Inputs *input );
void spatial_calculation(struct Physical *o);
void control_limits();
void limits_between(float *var,float min,float max,float val);
float max_brick;
extern int max_text;
int powerbarcol=0,powerballcol=0;


/*sion1------------------------------------------------*/
void physics_calculation(){
	int n,i;
	int found_visible=0;
	int local_score=0;
	float bh,pcnt;	
	bool wcollision1=false,wcollision2=false,wcollision_text=false;
	found_col=1;/*start searching*/
	max_brick=0;
	//Ball Bar collision

	object_collisions(&ball,&bar);
	if (power_mag==1){
		if (powerballcol<max_power_mag){
			if (found_col==0){
//				if (move_magnetic==false){
					vx=ball.vx;//remember logic velocity before to be trapped
					vy=ball.vy;
//					}
				powerballcol+=1;
				pcnt=100-(float)powerballcol/(float) max_power_mag*100;
				cout<<"Magnetic Force "<<pcnt<<"%"<<endl;

				//dx=ball.dx;
				//dy=ball.dy;
				ball.dy=0;//stops ball movement
				ball.dx=0;
				}
			}
		else{
			power_mag==0;
			}
		}
	
		
	//Brick Ball collision
	//Text Collision
	for (n=0;n<input.N;n++){
		found_col=1;
		if (brick[n].visible==1) {
			object_collisions(&ball,&brick[n]);
			found_visible=1;
			if (found_col==0){
				stage_score+=10;
				printf("Score: %d\n",stage_score);
				//Activate Text 
				texts[max_text-1].x=brick[n].x;
				texts[max_text-1].y=brick[n].y;
				texts[max_text-1].visible=1;
//			cout<< "texto "<< max_text <<endl;
				//max_text+=1;
				//texts=(struct Physical *)malloc(sizeof(struct Physical)*max_text);
				}
			bh=brick[n].y+ brick[n].h;
			/*if (bh >= max_brick) max_brick=bh; */
			}

		}

	//Text Physical Movement and reward?
	for (n=0;n<max_text;n++){
		if (texts[n].visible==1){
			spatial_calculation(&texts[n]);
			if(texts[n].y+texts[n].h>input.high-bar.h) wcollision_text=true;
			if(wcollision_text)texts[n].visible=0;
			}
		}
	//Brick Rocket collision
	if (power_bullet==1){
		for (i=0;i<max_bullet;i++){
			if ((bullet[i].visible==1)) {
				for (n=0;n<input.N;n++){
					found_col=1;
					if (brick[n].visible==1){
       	        	 		        object_collisions(&bullet[i],&brick[n]);
			                        found_visible=1;
                			        if (found_col==0){
							bullet[i].visible=0;
		        	                        stage_score+=10;
                		        	        printf("Score: %d\n",stage_score);
							cout<<"Bullets "<<100-(float) (i+1)/(float) (max_bullet)*100<<"%"<<endl;
                        				}
		      		                  bh=brick[n].y+ brick[n].h;
                			}        /*if (bh >= max_brick) max_brick=bh; */
	               		}
			if (bullet[i].y<=0) bullet[i].visible=0;
			if (bullet[i].visible==1)spatial_calculation(&bullet[i]);
			}
		}
	}
	if (found_visible==0){ 
		win();
	}
	wcollision1=wall_collisions_auto(&ball , &input);
	wcollision2=wall_collisions_man(&bar , &input );

		
//Collisions while magnetic movements will lost magnetic power and ball continues normall movement
	if (move_magnetic){
		if ((wcollision1 ) || (wcollision2) ) {
			cout<<"Lost Magnetic power in collision "<< move_magnetic << endl;
              		ball.dx=1;//stop ball magnetic movement
			ball.dy=1;//stop ball magnetic movements
       		        ball.vx=vx;
	    	        ball.vy=vy;
		//	cout<<"vx vy "<< ball.vx<< " " << ball.vy <<endl;
	                move_magnetic=false;//return flag that ball stops
			}
		} 
	control_limits();
	spatial_calculation(&ball);
	spatial_calculation(&bar);
}
/*------------------------------------------------*/
void spatial_calculation(struct Physical *o){
	o->x += dt * o->vx * (float) o->dx;
	o->y += dt * o->vy * (float) o->dy;		
}
/*------------------------------------------------*/
void control_limits(){
/*limits_between(&ball.vx,-10,-0.1,-11);*/
/*limits_between(&ball.vx,0.1,10,11);*/
limits_between(&ball.x,-input.width,0,2);
limits_between(&ball.x,input.width-ball.w,input.width*2,input.width-1-ball.w);
limits_between(&ball.y,-input.high,0,2);
if (power_bar==1)limits_between(&ball.y,input.high-ball.h-lowerbarim->h,input.high*100,input.high-1-ball.h-lowerbarim->h);
limits_between(&bar.y,-input.high,0,2);
limits_between(&bar.y,input.high-bar.h,input.high*2,input.high-bar.h-1);
limits_between(&bar.x,-input.width,0,2);
limits_between(&bar.x,input.width-bar.w,input.width,input.width-1-bar.w);
//limits_between(&ball.vx,50,99999,49);
//limits_between(&ball.vx,-99999,-50,-49);
//limits_between(&ball.vy,-10,-0.1,-11);
//limits_between(&ball.vy,0.1,10,11);
//limits_between(&ball.vy,500,999999,250);
//limits_between(&ball.vy,-500,-999999,-250);
if (power_bar==1) limits_between(&bar.y,input.high-lowerbarim->h-bar.h,9999,input.high-lowerbarim->h-bar.h-1);
else limits_between(&bar.y,500,9999,499);
}
/*------------------------------------------------*/
void limits_between(float *var,float min,float max,float val){
	if ((*var >=  min) &&  (*var <= max)){
//	printf("Red Line:%f->%f\n",*var,val);
		*var=val;
	}
}		
/*------------------------------------------------*/
bool wall_collisions_auto(struct Physical *o,struct Inputs *input ){
/*changes velocity directly*/
	bool choque =false;
        if(o->x <= 1 || o->x+o->w >= input->width){
                o->vx = -o->vx;
		load_chunk("audio/tic.wav");
		choque=true;
	}
//       if(o->y <= 1 || o->y + o->h >= input->high){
       if(o->y <= 1 ) {
		o->vy = -o->vy;
		choque=true;
		}
	else {
		if(power_bar==1){
			if( o->y +o->h > input->high-lowerbarim->h ){

				powerbarcol+=1;
				cout<<"Lower Bar "<<100-(float)powerbarcol/(float)(maxpower_bar+1)*100<<"%"<<endl;

				if (powerbarcol>maxpower_bar){
					powerbarcol=0;
					power_bar=0;
					}
				o->vy = -o->vy;
				load_chunk("audio/tic.wav");
				choque=true;
				}
//cout<< "X Y"<< o->vx << " " << o->vy <<endl;
			}
		else {
			if( o->y > input->high ) {
				lost_ball();
				choque=false;
				}
			}
		}
	//		load_chunk("tic.wav");
	return choque;
}
/*------------------------------------------------*/
bool wall_collisions_man(struct Physical *o,struct Inputs *input ){
	bool choque =false;

/*Changes manual direction flag dirxy used beetween bar and walls*/
	if((o->x <0 ) || (o->x + o->w > input->width) ){
			load_chunk("audio/tic.wav");
		o->dx = 0;
		choque=true;
	} 
	if (power_bar==1){
		if((o->y < 0 ) || ( o->y+o->h > input->high-lowerbarim->h)){
			o->dy = 0;
			choque=true;
			}
		}
	else{
		 if((o->y < 0 ) || ( o->y+o->h > input->high)){
			choque=true;
			load_chunk("audio/tic.wav");
			o->dy = 0;
		}
	}
return choque;
}
/*------------------------------------------------*/

void object_collisions(struct Physical *ball,struct Physical *o )
{
	float h,w;
	float x,y;
	float xi,yi;
	float dw3,dh1,dw5,dh7,dw2,dh2,dw4,dh8;
	float px1,px2,px3,px4,px5,px6,px7,px8,px9;
	float py1,py2,py3,py4,py5,py6,py7,py8,py9;
	float px1i,px2i,px3i,px4i,px5i,px6i,px7i,px8i,px9i;
	float py1i,py2i,py3i,py4i,py5i,py6i,py7i,py8i,py9i;
/*	printf("ballvx:%f ballvy:%f ballx:%f bally:%f \n",ball.vx,ball.vy,ball.x,ball.y);*/
/*	printf("1 dx %d dy %d \n",bar.dx,bar.dy);*/
	xi=ball->x;
	yi=ball->y;
	spatial_calculation(&*ball);
	x=ball->x;
	y=ball->y;
	h=ball->h;
	w=ball->w;
	dw3=w/2.0;
	dh1=h/2.0;
	dw5=w;
	dh7=h;
	dw2=dw3*(1.0-sin(45.0*3.141592/180.0));
	dh2=dh1*(1.0-sin(45.0*3.141592/180.0));
	dw4=dw5-dw2;
	dh8=dh7-dh2;

	px1i=xi;
	py1i=yi+dh1;
	px2i=xi+dw2;
	py2i=yi+dh2;
	px3i=xi+dw3;
	py3i=yi;
	px4i=xi+dw4;
	py4i=yi+dh2;
	px5i=xi+dw5;
	py5i=yi+dh1;
	px6i=xi+dw4;
	py6i=yi+dh8;
	px7i=xi+dw3;
	py7i=yi+dh7;
	px8i=xi+dw2;
	py8i=yi+dh8;
	px9i=xi+dw3;
	py9i=yi+dh1;
	
	px1=x;
	py1=y+dh1;
	px2=x+dw2;
	py2=y+dh2;
	px3=x+dw3;
	py3=y;
	px4=x+dw4;
	py4=y+dh2;
	px5=x+dw5;
	py5=y+dh1;
	px6=x+dw4;
	py6=y+dh8;
	px7=x+dw3;
	py7=y+dh7;
	px8=x+dw2;
	py8=y+dh8;
	px9=x+dw3;
	py9=y+dh1;
	detect_collision(&*ball , &*o, px1i , py1i , px1 , py1 );
	detect_collision(&*ball , &*o, px2i , py2i , px2 , py2 );
	detect_collision(&*ball , &*o, px3i , py3i , px3 , py3 );
	detect_collision(&*ball , &*o, px4i , py4i , px4 , py4 );
	detect_collision(&*ball , &*o, px5i , py5i , px5 , py5 );
	detect_collision(&*ball , &*o, px6i , py6i , px6 , py6 );
	detect_collision(&*ball , &*o, px7i , py7i , px7 , py7 );
	detect_collision(&*ball , &*o, px8i , py8i , px8 , py8 );
	detect_collision(&*ball , &*o, px9i , py9i , px9 , py9 );
	ball->x=xi;
	ball->y=yi;
}

/*------------------------------------------------*/
void detect_collision(struct Physical *ball, struct Physical *o,float xi, float yi, float x, float y){
float m,yp,xp,x0,y0;
	if (found_col == 1){
	x0=o->x;
	y0=o->y;
        	if((x > o->x) && (x < o->x + o->w) && (y > o->y) && (y < o->y + o->h)){
			load_chunk("audio/soft-hit-wooden-block.wav");
			if (x-xi==0) {
				x= x*1.01;
			}
			m= (y - yi) / (x - xi);
			if ( (yi <= y0) && (y0 <= y) ){
				yp=y0;
			}
			else{
				yp=y0+o->h;
			}
			xp=(yp - yi) / m + xi;
			if ((x0 < xp) && (xp < x0+o->w) ){
				if ((o->dy < 0) && (ball->vy < 0) &&  (o->y > ball->y) || (o->dy > 0) && (ball->vy > 0) &&  (o->y < ball->y)  ){
					ball->vy = ball->vy+o->vy * (float)o->dy;}
				else{ ball->vy = -ball->vy+o->vy * (float)o->dy;}
//				ball->vx = ball->vx + 0.1 * o->vx * (float)o->dx;
				}
			else{
				if( y <= o->y + 0.5*o->h ) { ball->vy=-ball->vy + o->vy * (float)o->dy; }
				else { ball->vy = ball->vy + o->vy * (float)o->dy; }

				if ((o->dx > 0) && (ball->vx > 0) &&  (o->x < ball->x) || (o->dx < 0) && (ball->vx < 0) &&  (o->x > ball->x)  ){
					ball->vx=ball->vx + o->vx*(float)o->dx;}
				else{ball->vx=-ball->vx +o->vx*(float)o->dx;}
				}
		found_col=0;
		o->visible=0;
/*	printf("2b ballvx:%f ballvy:%f ballx:%f bally:%f dx: %d dy: %d \n",ball->vx,ball->vy,ball->x,ball->y,ball->dx,ball->dy);
	printf("2t ballvx:%f ballvy:%f ballx:%f bally:%f dx: %d dy: %d \n",o->vx,o->vy,o->x,o->y,o->dx,o->dy);*/
		}
	}
}
