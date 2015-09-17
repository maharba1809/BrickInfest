#include <time.h>
#define BILLION 1000000000L

extern float dt;

float convert(struct timespec *ts)
{
	float t;
        t=0.0;
        t = (float)ts->tv_sec;/*sec*/
        t*= BILLION; /*nsec*/
        t+= (float)ts->tv_nsec; /* nsec add */
        t/= 1000000.0f;/*msec*/
        return t;
}

