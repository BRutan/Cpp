/* Functions.hpp (exercise 3.2+3.3.3)
Description:
	* Functions to 


*/

#include <iostream>

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

void ThreadFunction()
{
	for (std::size_t i = 0; i < 100; i++)
	{
		std::cout << i << std::endl;
	}
}

struct ThreadFunctionObject
{
	double data;
	ThreadFunctionObject(double data_in) : data(data_in)
	{

	}
	void operator()()
	{
		std::cout << data << std::endl;
	}
};

auto storedLambda = [](double d) { std::cout << d << std::endl; };

#endif
