/* Functions.hpp (exercise 3.1.1)
Description:
	* 

*/
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <functional>
#include <thread>
#include <string>

/* 3.1.1 */
// Interface function that prints string large number of times :
void Iprint(const std::string &s, int count)
{
	std::cout << std::this_thread::get_id() << std::endl;
	for (unsigned i = 0; i < count; i++)
		std::cout << s  << std::endl;
}
// a) Create free functions, lambda function and stored lambdas etc that call interface Iprint:
struct FObj
{
	static void staticMemberFunc(const std::string s, int i)
	{
		std::cout << std::this_thread::get_id() << std::endl;
		Iprint(s, i);
	}
	void operator()(const std::string s, int i)
	{
		std::cout << std::this_thread::get_id() << std::endl;
		Iprint(s, i);
	}
};

auto storedLambda = [](const std::string &s, int count) 
{ 
	std::cout << std::this_thread::get_id() << std::endl; 
	Iprint(s, count); 
};

auto boundMemberFunc = std::bind(&FObj::staticMemberFunc, std::placeholders::_1, std::placeholders::_2);

void freeFunc(const std::string &s, int count)
{
	std::cout << std::this_thread::get_id() << std::endl;
	Iprint(s, count);
}

#endif
