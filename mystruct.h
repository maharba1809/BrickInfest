#ifndef MySTRUCT_H
#define MySTRUCT_H
struct Inputs
{
        int red,green,blue;
        int width,high;
        float vx,vy;
        float fps;
	int N;
	int up;
};
struct Physical
{
        float vx,vy;
        float x,y;
        float h,w;
	int dx,dy;
	int visible;
};
extern struct Inputs input;
extern struct Physical ball;
extern struct Physical bar;
extern struct Physical back;
extern struct Physical lowerbar;
extern struct Physical *brick;
extern struct Physical *bullet;
extern struct Physical *texts;
#endif
