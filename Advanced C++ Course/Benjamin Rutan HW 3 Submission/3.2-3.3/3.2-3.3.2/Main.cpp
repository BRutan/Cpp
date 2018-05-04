/* Main.cpp (exercise 3.2+3.3.2)
Description:
	* Solutions to problems a-c in exercise 3.2+3.3.2.
*/

#include <iostream>
#include <thread>
#include "Functions.hpp"
#include "X.hpp"

int main()
{
	/* 3.2+3.3.2 */
	std::thread *thread_array[100];
	
	PointerType item(new X);
	double updateVal = 0;
	item->val = 30;
	
	// b) Create array of 100 threads, fire each one. 	
	for (std::size_t i = 0; i < 100; i++)
	{
		thread_array[i] = new std::thread(Modify,item, updateVal++);
		thread_array[i]->detach();
	}
	// c) Following testing, with removing the sleep_for() method for varying amounts of time, increasing the number of threads increases the likelihood of
	// race condition. In this case, the output of the increasing updateVal becomes garbled on the standard output, in the incorrect order or both.

	system("pause");

	return 0;
}