#include "ThreadClass.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "thread.h"

/* ---------------------------------------------------- */
/* NAME : Andrew Rein                 User ID: amrein   */
/* DUE DATE : 11/14/2022                                */
/* PROGRAM ASSIGNMENT 4                                 */
/* FILE NAME : thread.cpp                               */
/* PROGRAM PURPOSE : This program contains the          */
/* instructions for the threads to run. Both the baby   */
/* and the mother have a unique set of instructions     */
/* ---------------------------------------------------- */

using namespace std;
extern int m, n, t, feeding, food;

void thread::ThreadFunc()
{
	Thread::ThreadFunc();

	if (name == 0)
	{ // Thread pattern for the mother eagle

		while (feeding < t)
		{ // Loop until feedings are up
			goto_sleep();

			srand(time(0));
			int random = (rand() % 20) + 1;

			for (int i = 0; i < random; i++)
			{ // Delay some random amount
				Delay();
			}

			food_ready();
		}

		for (int i = 0; i < 100; i++)
		{
			Delay();
		}
		goto_sleep();
	}
	else
	{ // Thread pattern for baby eagles

		printf("%*saby eagle %d started.\n", name + 1, "B", name);
		while (1)
		{

			if (feeding >= t && food <= 0){ // Checks for end of feedings

				break;
			}

			srand(time(0));
			int random = (rand() % 15) + 1;

			for (int i = 0; i < random; i++)
			{
				Delay();
			}

			ready_to_eat(name); // This eagle is ready

			random = (rand() % 15) + 1;

			for (int i = 0; i < random; i++) // Delay some random amount
			{ 
				Delay();
			}

			finish_eating(name); // Signals that the eagle is done eating for now
		}
	}
}
