/* Functions.hpp (exercise 2.3.2)
Description:
	* 

*/
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <functional>
#include <mutex>
#include <thread>
#include <string>

/* 3.1.2 */
// Interface function that prints string large number of times :
void Iprint(const std::string &s, int count, std::mutex &mutex_in)
{
	if (mutex_in.try_lock())
	{
		for (unsigned i = 0; i < count; i++)
			std::cout << s << std::endl;
		mutex_in.unlock();
	}
}
// a) Create free functions, lambda function and stored lambdas etc that call interface Iprint:
struct FObj
{
	static void staticMemberFunc(const std::string s, int i, std::mutex &mutex_in)
	{
		std::cout << std::this_thread::get_id() << std::endl;
		mutex_in.lock();
		Iprint(s, i, mutex_in);
	}
	void operator()(const std::string s, int i, std::mutex &mutex_in)
	{
		std::cout << std::this_thread::get_id() << std::endl;
		mutex_in.lock();
		Iprint(s, i, mutex_in);
	}
};

auto storedLambda = [](const std::string &s, int count, std::mutex &mutex_in)
{
	std::cout << std::this_thread::get_id() << std::endl;
	mutex_in.lock();
	Iprint(s, count, mutex_in);
};

auto boundMemberFunc = std::bind(&FObj::staticMemberFunc, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

void freeFunc(const std::string &s, int count, std::mutex &mutex_in)
{
	std::cout << std::this_thread::get_id() << std::endl;
	mutex_in.lock();
	Iprint(s, count, mutex_in);
}

#endif