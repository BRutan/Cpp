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
	/* 3.1.2 */
	std::chrono::time_point <std::chrono::system_clock> start, end; 
	start = std::chrono::system_clock::now();
	std::mutex mut;
	 
	int totalCalls = 10;
	std::thread funcObjThd(FObj(), "Function Object", totalCalls, std::ref(mut));
	std::thread	freeFuncThd(freeFunc, "Free Function.", totalCalls, std::ref(mut));
	std::thread lambdaThd([](const std::string &s, int count, std::mutex &mut_in) { Iprint(s, count, mut_in); }, "Free Lambda.", totalCalls, std::ref(mut));
	std::thread boundMemberThd(boundMemberFunc, "Bound Member Function.", totalCalls, std::ref(mut));
	std::thread storedLambdaThd(storedLambda, "Stored Lambda.", totalCalls, std::ref(mut));
	storedLambdaThd.detach();

	funcObjThd.join();
	freeFuncThd.join();
	lambdaThd.join();
	boundMemberThd.join();
	storedLambdaThd.join();
	/*
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
		std::cout << "Caught exception. " << std::endl;
	}*/

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start; 
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "Finished computation at " << "elapsed time: " << elapsed_seconds.count() << "s\n";

	system("pause");

	return 0;
}