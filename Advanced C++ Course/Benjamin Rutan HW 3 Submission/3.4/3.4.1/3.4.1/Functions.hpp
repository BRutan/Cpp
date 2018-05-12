/* Functions.hpp (exercise 3.4.1)
Description:
	* Functions to test std::future<> and std::async.
*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <future>

void func1()
{
	std::cout << "func1() called. " << std::endl;
}

double func2(double a, double b)
{
	return a * b;
}


#endif
