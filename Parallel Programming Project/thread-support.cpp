#include "ThreadClass.h"
#include "thread.h"
#include <iostream>
#include <string>

/* ---------------------------------------------------- */
/* NAME : Andrew Rein                 User ID: amrein   */
/* DUE DATE : 11/14/2022                                */
/* PROGRAM ASSIGNMENT 4                                 */
/* FILE NAME : thread-support.cpp                       */
/* PROGRAM PURPOSE : This program containts each of the */
/* support functions for the threads to use. Thread     */
/* synchronization is done through semaphores           */
/* ---------------------------------------------------- */


using namespace std;

extern int m, n, t;
Semaphore Eating("Eating", 0);//Only allow m eagles to eat
Semaphore Waking("Waking", 1); //
Semaphore Sleeping("Sleeping", 0); //Mother eagle stops and waits to be woken
Semaphore Waiting("Waiting", 1); //Allows one eagle to wake mother, all others wait until food is ready
Semaphore First_wait("First", 0); //Causes the first eagle to wake mother to wait
Semaphore Retire_lock("Retire", m*t); //Keeps track of the total time an eagle will eat
int food = 0; //Counter for food
int pot = 0; //Counter for the pots 
int feeding = 0; //Keeps track of the current feeding
int wait_count = -1; //Counter to keep track of the number of signal calls for the Waiting semaphore
int num; //Allows the mother eagle to grab the name of the baby that wakes it

// --------------------------------------------------------
// FUNCTION  read_to_eat : 
//     This function is called when a baby is ready to eat.
//     if it is possible for the baby to eat, it does.
//     If the pots are gone then a single baby wakes the mother to refill them.
// PARAMETER USAGE : int name, the current thread's name
//    
// FUNCTION CALLED : none
//   
// -------------------------------------------------------
void ready_to_eat(int name){

	printf("%*saby eagle %d is ready to eat.\n", name+1, "B", name);

	if(food == 0 && feeding < t){
		wait_count++;
		Waiting.Wait();
		if(food == 0 && feeding < t){
			printf("%*saby eagle %d sees all feeding pots are empty and wakes up the mother.\n", name+1, "B", name); 
			num = name;
			Sleeping.Signal();
			First_wait.Wait();
		}
	}

	Eating.Wait();
	if(feeding <= t && food > 0){
		food--;
		pot++;
		printf("%*saby eagle %d is eating using feeding pot %d.\n", name+1, "B", name, pot); 
	}

}


// --------------------------------------------------------
// FUNCTION  Finish_eating : 
//     This function is called once a baby has finished eating.
//     It prints the messege and signals a semaphore used
//     by the mother eagle
// PARAMETER USAGE : int name, the current thread's name
//    
// FUNCTION CALLED : none
//   
// -------------------------------------------------------
void finish_eating(int name){

	printf("%*saby eagle %d finishes eating\n", name+1, "B", name);	
	Retire_lock.Signal();

}

// --------------------------------------------------------
// FUNCTION  goto_sleep :
//     This function is called by the mother eagle when
//     it is not woken by a baby eagle. Thread is blocked
//     until woken
// PARAMETER USAGE : none
//
// FUNCTION CALLED : none
//
// -------------------------------------------------------

void goto_sleep(){

	if(feeding == t){

		Retire_lock.Wait();

		for(int i = 0; i < n; i++){

			Eating.Signal();
			Waiting.Signal();
			First_wait.Signal();

		}
		return;

	}	
	printf("Mother eagle takes a nap.\n");
	Sleeping.Wait();
	printf("Mother eagle is awoke by baby eagle %d and starts preparing food.\n", num);

}

// --------------------------------------------------------
// FUNCTION  food_ready :
//     This function is called when the mother eagle is 
//     woken up and signals block baby eagle threads that
//     they can begin to eat. Resets all food counters
//    
// PARAMETER USAGE : none
//
// FUNCTION CALLED : none
//
// -------------------------------------------------------


void food_ready(){

	feeding++;
	printf("Mother eagle says \"Feeding (%d)\"\n", feeding);
	food = m;
	pot = 0;

	for(int i = 0; i < m; i++){

		Eating.Signal();

	}

	for(int i = 0; i < wait_count+1; i++){

		Waiting.Signal();

	}
	wait_count = -1;
	First_wait.Signal();

}


