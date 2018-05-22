/* Main.cpp (exercise 3.5.6)
Description:
	* Test the StopWatch class.
*/

#include <chrono>
#include <iostream>
#include "StopWatch.hpp"

int main()
{
	/* 3.5.6 */
	// b) Test the StopWatch class.
	StopWatch test;
	unsigned long i = 0;
	test.StartStopWatch();
	while (i < 100000000)
	{
		i++;
	}
	test.StopStopWatch();

	std::cout << "Elapsed time: " << test.GetTime() << " milliseconds." << std::endl;
	test.Reset();
	std::cout << "Elapsed time following reset: " << test.GetTime() << " milliseconds. " << std::endl;
	test.StopStopWatch();
	std::cout << "Elapsed time following erroneous stopping: " << test.GetTime() << " milliseconds. " << std::endl;

	system("pause");

	return 0;
}