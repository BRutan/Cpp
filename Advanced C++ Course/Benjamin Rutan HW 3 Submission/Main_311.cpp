/* Main.cpp (exercise 2.3.1)
Description:
	* Solutions to exercise 2.3.1.
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
	/////// TODO: watch video.
	std::chrono::time_point <std::chrono::system_clock> start, end; 
	start = std::chrono::system_clock::now();
	/* 3.1.1 */
	// b) Create thread for each callable object, with one being detached. 
	int totalCalls = 10;
	std::thread funcObjThd(FObj(), "Function Object", totalCalls);
	std::thread	freeFuncThd(freeFunc, "Free Function.", totalCalls);
	std::thread lambdaThd([](const std::string &s, int count) { Iprint(s, count); }, "Free Lambda.", totalCalls);
	std::thread boundMemberThd(boundMemberFunc, "Bound Member Function.", totalCalls);
	std::thread storedLambdaThd(storedLambda, "Stored Lambda.", totalCalls);
	storedLambdaThd.detach();

	// c) Introduce code to check threads have completed:
	try
	{
		if (funcObjThd.joinable())
		{
			funcObjThd.joinable();
		}
		if (freeFuncThd.joinable())
		{
			freeFuncThd.join();
		}
		if (lambdaThd.joinable())
		{
			lambdaThd.join();	
		}
		if (boundMemberThd.joinable())
		{
			boundMemberThd.join();
		}
		if (storedLambdaThd.joinable())
		{
			storedLambdaThd.join();
		}
	}
	catch (...)
	{
		if (funcObjThd.joinable())
		{
			funcObjThd.joinable();
		}
		if (freeFuncThd.joinable())
		{
			freeFuncThd.join();
		}
		if (lambdaThd.joinable())
		{
			lambdaThd.join();
		}
		if (boundMemberThd.joinable())
		{
			boundMemberThd.join();
		}
		if (storedLambdaThd.joinable())
		{
			storedLambdaThd.join();
		}
	}

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start; 
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "Finished computation at " << "elapsed time: " << elapsed_seconds.count() << "s\n";

	return 0;
}