#include "ThreadClass.h"
#include "thread.h"
#include <iostream>
#include <string>
#include <math.h>
#include <array>

/* ---------------------------------------------------- */
/* NAME : Andrew Rein                 User ID: amrein   */
/* DUE DATE : 11/14/2022                                */
/* PROGRAM ASSIGNMENT 4                                 */
/* FILE NAME : thread-main.cpp                          */
/* PROGRAM PURPOSE : This is the main file for the      */                               
/* thread programs. This program gets all of the threads*/ 
/* created and ready to run                             */
/* ---------------------------------------------------- */

using namespace std;

int m, n, t;

int main(int argc, char **argv){

	m = atoi(argv[1]);
	n = atoi(argv[2]);
	t = atoi(argv[3]);

	if(m == 0){
	   m = 10;
	}
	if(n == 0){
	   n = 10;
	}
	if(t == 0){
	   t = 10;
	}

	thread *babies[n];
	thread *mother;

	printf("MAIN: There are %d baby eagles, %d feeding pots, and %d feedings.\n", n, m, t);
	printf("MAIN: Game starts!!!!!\n");

	mother = new thread;
	mother->name = 0;
	printf("Mother eagle started.\n");
	mother->Begin();

	for(int i = 0; i < n; i++){

	   babies[i] = new thread;
	   babies[i]->name = i+1;
	   babies[i]->Begin();

	}

	for(int i = 0; i < n; i++){

	   babies[i]->Join();	

	}
	mother->Join();
	printf("Mother eagle retires after serving %d feedings. Game is over!!!\n", t);

}
