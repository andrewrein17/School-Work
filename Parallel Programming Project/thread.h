#include "ThreadClass.h"
#include <iostream>
#ifndef THREAD_H
#define THREAD_H

class thread : public Thread{

	public:
		int name;

	private:
		void ThreadFunc();

};
#endif

void ready_to_eat(int name);
void finish_eating(int name);
void goto_sleep();
void food_ready();

