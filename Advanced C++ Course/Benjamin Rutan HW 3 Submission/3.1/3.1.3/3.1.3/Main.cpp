/* Main.cpp (exercise 3.1.3)
Description:
	* Solutions to exercise 3.1.3.
*/

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include "Functions.hpp"

int main()
{
	/* 3.1.3 */
	std::chrono::time_point <std::chrono::system_clock> start, end; 
	start = std::chrono::system_clock::now();
	std::timed_mutex mut;
	 
	std::thread funcObjThd(FObj(), 2, std::ref(mut));
	std::thread	freeFuncThd(freeFunc, -1, std::ref(mut));
	std::thread lambdaThd([](int count, std::timed_mutex &mut_in) { updateCounter(count, mut_in); }, -1, std::ref(mut));
	std::thread boundMemberThd(boundMemberFunc, 1, std::ref(mut));
	std::thread storedLambdaThd(storedLambda, -1, std::ref(mut));

	try
	{
		if (funcObjThd.joinable())
			funcObjThd.join();
		if (freeFuncThd.joinable())
			freeFuncThd.join();
		if (lambdaThd.joinable())
			lambdaThd.join();	
		if (boundMemberThd.joinable())
			boundMemberThd.join();
		if (storedLambdaThd.joinable())
			storedLambdaThd.join();
	}
	catch (...)
	{
		funcObjThd.join();
		freeFuncThd.join();
		lambdaThd.join();
		boundMemberThd.join();
		storedLambdaThd.join();
	}

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start; 
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "Finished computation at " << "elapsed time: " << elapsed_seconds.count() << "s\n";
	std::cout << "Counter: " << counter << std::endl;

	// Correct answer for counter is 0. If race condition occurs, counter is likely to underflow.

	system("pause");

	return 0;
}