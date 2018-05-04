/* Main.cpp (exercise 3.2+3.3.3)
Description:
	*

*/

#include <thread>
#include "ActiveObject.hpp"
#include "Functions.hpp"

int main()
{
	/* 3.2+3.3.3 */
	// a) Create thread and function that will be its thread function:
	std::thread thread1(ThreadFunction);
	// b) Create an active object based upon a thread with no associated thread function:
	try
	{
		ActiveObject test1();
	}
	catch (...)
	{
		std::cout << "Caught exception. " << std::endl;
	}

	// c) Implement thread functions using function objects, stored lambdas and lambdas:
	ActiveObject test2(new std::thread(storedLambda, 54.0));
	ActiveObject test3(new std::thread([](double d) { std::cout << d << std::endl; }, 45.0));

	if (thread1.joinable())
		thread1.join();

	return 0;
}