#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>




#include <math.h>
#include <iostream>
#include <fstream>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <pthread.h>
#include <queue>


void *runfunc_temp(void *);
void *runprog_temp_0(void *);
void *runprog_temp_1(void *);
void *runprog_temp_2(void *);
void *runprog_temp_3(void *);
void *runkeys_temp(void *);
void *savefunc_temp(void *);
void *plot_temp(void *);
void wait(int seconds);
int algo(double &x, double &y, double &z);


				//pointer to use for taking data from algo


class window {

private:

Display *dpy;
Window w;
GC gc;

Status rc;

Colormap screen_colormap;	
XColor red,brown,blue,yellow,green,black,white;

XEvent report;

//double width;

double **dat;

public:
XColor *clr;

double **data;
double width,height,center;

window();
void opendisplay(double width,double height);
void closedisplay();
void keypress();
void drawtext();
void drawaxis();
void drawline(double *x, double *y,XColor color);
void drawcirc(double *x,double w,XColor color);
void setcolor(XColor color);
void flush();
void clearall();
void runprog(int d_stream);
void rplot();
};

class program{

public:

window win1;				//instantiate window thread here also
window win2;
double **data;		//mutex data
	
pthread_t plot_thread;		
pthread_t prog_thread;
pthread_t win_thread0;
pthread_t win_thread1;
pthread_t win_thread2;
pthread_t win_thread3;
pthread_t win_thread4;
pthread_t key_thread;
pthread_t save_thread;	   //save data whilst it is being made load data from windows 
			  //thread			  				


program();
void start();
void stop();
void runplot();

void runwin(int d_stream);
void closedisplay();
void clear();
void runkeys();
void savefunc();
void runfunc();
void plot(double *x1,double *y1,int clr);
void circ(double *c, double w, int clr);
void setcolor(int clr);
void flush();
};


class graph{

public:

void run();
void stop();
void clear();
void plot(double *x,double *y,int clr);
void circ(double *c, double w, int clr);
void runfunc(double x,double y,double z,int save,int count,int dat_stream);
void setcolor(int clr);
void flush();
};


//program prog;

















