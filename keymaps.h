#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <string.h>
#include <termios.h>
#include <sys/types.h>

void *keythread(void *);
void keymap(char key_,double *var,double val,char oper);
void init_keymap(int numkeys_);
void start_keythread();
