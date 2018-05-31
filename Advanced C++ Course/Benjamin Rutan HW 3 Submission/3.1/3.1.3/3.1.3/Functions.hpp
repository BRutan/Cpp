/* Functions.hpp (exercise 3.1.3)
Description:
	* Functions to test multithreading.
*/
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <functional>
#include <mutex>
#include <thread>
#include <string>
#include <system_error>

std::size_t try_locks = 0;
unsigned counter = 0;
unsigned update = 1000000;

/* 3.1.3 */
void updateCounter(int incrementer, std::timed_mutex &mutex_in)
{
	// d) Apply unique_lock::try_lock_for that tries to lock mutex that blocks until specific timeout duration has lapsed
	std::unique_lock<std::timed_mutex> locker(mutex_in);
	try
	{
		locker.try_lock_until(std::chrono::high_resolution_clock::now() + std::chrono::seconds(4));
	}
	catch (const std::system_error &err)
	{
		if (err.code() == std::errc::resource_deadlock_would_occur)
		{
			// Mutex is already locked.
			std::cout << "Error: mutex is already locked. " << std::endl;
		}
		else if (err.code() == std::errc::operation_not_supported)
		{
			// No associated mutex error caught.
			std::cout << "Error: no associated mutex." << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "Error: Unknown error occurred while locking mutex." << std::endl;
	}
	// Increment/decrement the counter:
	for (unsigned i = 0; i < update; i++)
	{
		counter += incrementer;
	}
	// Unlock the unique_lock:
	try
	{
		locker.unlock();
	}
	catch (const std::system_error &err)
	{
		if (err.code() == std::errc::operation_not_permitted)
		{
			std::cout << "Error: no associated mutex, or tried to unlock mutex that is not locked." << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "Error: Unknown error occurred while unlocking mutex." << std::endl;
	}
	// g) lock_guard and unique_lock destructors will unlock associated mutex when end of scope is reached.
}
// a) Create free functions, lambda function and stored lambdas etc that call updateCounter:
struct FObj
{
	static void staticMemberFunc(int update, std::timed_mutex &mutex_in)
	{
		updateCounter(update, std::ref(mutex_in));
	}
	void operator()(int update, std::timed_mutex &mutex_in)
	{
		updateCounter(update, std::ref(mutex_in));
	}
};

auto storedLambda = [](int update, std::timed_mutex &mutex_in)
{  
	updateCounter(update, std::ref(mutex_in));
};

auto boundMemberFunc = std::bind(&FObj::staticMemberFunc, std::placeholders::_1, std::placeholders::_2);

void freeFunc(int update, std::timed_mutex &mutex_in)
{
	updateCounter(update, std::ref(mutex_in));
}


#endif