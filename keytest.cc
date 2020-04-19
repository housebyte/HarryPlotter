#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "keymaps.h"
#include "xfunc_wrap_.h"

using namespace std;



class keytest{
public:
double pos,minus,mult,div;

double line;

graph gp;

keytest(){


pos=1;minus=1;mult=1;div=1;


init_keymap(7);		//Map 6 keys


keymap('l',&mult,0.00123,'*');
keymap(',',&div,0.00123,'/');
keymap('k',&minus,0.00000123,'-');
keymap('m',&pos,0.123,'+');
keymap('j',&div,1.23,'/');
keymap('n',&pos,0.0000123,'+');


}

double modu(double val){

return sqrt(pow(val,2));

}

void startline(){

double timeseries=0;

start_keythread();

gp.run();

double tx=1,yx=-1;
int counter=0;

timeseries=0;

while(1){

timeseries = (1-minus - yx*mult + modu(tx)/div)+pos;

yx  = tx;
tx = timeseries;

cout<<"timeseries ="<<timeseries<<"\n";

gp.runfunc(counter*10,timeseries/5,0,0,counter*10,0);

counter++;

sleep(1);		

	}
	
}


};


int main(){

keytest *keyprog;

keyprog = new keytest;

keyprog->startline();

}
