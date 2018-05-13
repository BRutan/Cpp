/* Main.cpp (exercise 3.4.3)
Description:
	* Solutions to exercise 3.4.3 problems a-d.
*/

#include <future>
#include <iostream>
#include <thread>

#include "Functions.hpp"

int main()
{
	/* 3.4.3 */
	// a) Create various instances of promises:
	// Default promise:
	std::promise<void> p1;
	// Promise with empty shared state:
	std::promise<void> p2;
	// Promise based on move constructor:
	std::promise<void> p3(std::move(p2));

	// b) Create promise with double as stored value:
	std::promise<double> p4;
	std::shared_future<double> fut = p4.get_future();
	// c) Start a thread with the new future from part b. Create a thread function that uses the value of the
	// shared data. 
	std::thread thd(testPromise, std::move(p4));
	// Wait for promise:
	// d) Use promise to set the value of the shared data:
	fut.wait();
	std::cout << "Result of thread: " << fut.get() << std::endl;
	
	thd.join();

	system("pause");

	return 0;
}