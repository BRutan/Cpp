/* Functions.hpp (exercise 3.2+3.3.3)
Description:
	* Global function, stored lambda and lambda functions to support solutions to problems a-d.
*/

#include <iostream>

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

void ThreadFunction()
{
	std::cout << "ThreadFunction()" << std::endl;
}

struct ThreadFunctionObject
{
	ThreadFunctionObject()
	{

	}
	void operator()()
	{
		std::cout << "ThreadFunctionObject()" << std::endl;
	}
};

auto storedLambda = []() { std::cout << "storedLambda()" << std::endl; };

#endif
