#include "mystruct.h"
#include <iostream>

using namespace std;
extern int level,power_bar,power_bullet,up_ini;
int power_mag;
int max_bullet,maxpower_bar,max_power_mag,maxpowermag,max_text;
void read(){
	cout<<"Starting Power Systems"<<endl;
	//system options
	input.red=0;
        input.green=0;
        input.blue=0;
        input.width=800;
        input.high=500;
        input.fps=0.016;

	power_bar=0;//lower bar Activation
	maxpower_bar=20;
	power_bullet=0;//Bullets Activation
	max_bullet=30;
	power_mag=0;//manget Activation
	max_power_mag=10;
		
	//videogame options
	input.up=10;//Live
	level=11;
	up_ini=input.up;/*backup*/
	max_text=1;


}
