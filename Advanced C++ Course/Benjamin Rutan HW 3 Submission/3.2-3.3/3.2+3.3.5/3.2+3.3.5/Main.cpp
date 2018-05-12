/* Main.cpp (exercise 3.2+3.3.5)
Description:
	*


*/

#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

#include "Barber.hpp"
#include "Customer.hpp"

int main()
{
	std::mutex *m = new std::mutex();
	std::lock_guard<std::mutex> guard(*m);
	std::atomic<bool> custArrived = false;
	std::atomic<bool> finishedService = true;
	std::atomic<bool> shopClosed = false;
	std::atomic<unsigned> freeChairs = MAXFREECHAIRS;

	Barber barber(m, custArrived, freeChairs, finishedService, shopClosed);
	Customer cust();
	// Start producer consumer threads:
	std::thread(barber);
	// Randomly start customer threads:


	return 0;
}