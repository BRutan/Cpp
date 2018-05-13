/* Main.cpp (exercise 3.4.2)
Description:
	* Solutions to problems a-d for exercise 3.4.2.
*/

#include <future>
#include <iostream>
#include <thread>
#include "Functions.hpp"

int main()
{
	/* 3.4.2 */
	// a) Create various instances of shared_future:
	// Default instance:
	std::shared_future<double> sFuture = std::async(func1, 4.0, 5.0);
	std::cout << "Default shared_future<double>: " << sFuture.get() << std::endl;
	// Shared with same state as another shared state:
	std::shared_future<double> sFuture2(sFuture);
	std::cout << "Copied shared_future<double>: " << sFuture2.get() << std::endl;
	// Transfer shared state from a normal future to a shared future:
	std::future<double> future1 = std::async(func1, 4.0, 5.0);
	std::shared_future<double> sFuture3(std::move(future1));
	std::cout << "Transferred future<double>: " << sFuture3.get() << std::endl;	
	// Transfer shared state from a shared future to a shared future:
	std::shared_future<double> sFuture4(std::move(sFuture3));
	std::cout << "Transferred future<double>: " << sFuture4.get() << std::endl;
	// b) Check member functions from std::future that they are also applicable to std::shared_future:
	
	// c) Test what happens when call get() twice on shared_future:
	std::cout << "Second get() call on shared_future: " << sFuture.get() << std::endl;
	// d) Create shared future that waits for infinite loop to finish:
	std::shared_future<double> infLoop = std::async(infFunc);
	std::future_status status = infLoop.wait_for(std::chrono::seconds(4));
	// Abandon infFunc() after 4 seconds:
	if (status == std::future_status::timeout)
	{
		infLoop._Abandon();
	}
	std::cout << "Abandoned infinite loop." << std::endl; 

	system("pause");
	return 0;
}