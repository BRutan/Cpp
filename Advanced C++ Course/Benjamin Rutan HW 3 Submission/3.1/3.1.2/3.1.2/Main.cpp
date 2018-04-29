/* Main.cpp (exercise 3.1.2)
Description:
	* Solutions to exercise 3.1.2.
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
	std::chrono::time_point <std::chrono::system_clock> start, end; 
	start = std::chrono::system_clock::now();
	std::mutex mut;
	/* 3.1.2 */
	// b) Create thread for each callable object, with one being detached. 
	int totalCalls = 10;
	std::thread funcObjThd(FObj(), "Function Object", totalCalls, mut);
	std::thread	freeFuncThd(freeFunc, "Free Function.", totalCalls, mut);
	std::thread lambdaThd([](const std::string &s, int count, std::mutex &mut_in) { Iprint(s, count, mut_in); }, "Free Lambda.", totalCalls, mut);
	std::thread boundMemberThd(boundMemberFunc, "Bound Member Function.", totalCalls, mut);
	std::thread storedLambdaThd(storedLambda, "Stored Lambda.", totalCalls, mut);
	storedLambdaThd.detach();

	// c-d) Introduce code to check threads have completed:
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
		/*
		funcObjThd.join();
		freeFuncThd.join();
		lambdaThd.join();
		boundMemberThd.join();
		storedLambdaThd.join(); */
	}

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start; 
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "Finished computation at " << "elapsed time: " << elapsed_seconds.count() << "s\n";

	system("pause");

	return 0;
}