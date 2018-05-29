/* Main.cpp (exercise 3.2+3.3.5)
Description:
	*


*/

#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <Vector>

#include "Barber.hpp"
#include "Customer.hpp"
#include "SynchronisedQueue.hpp"

int main()
{
	/* 3.2+3.3.5 */
	Barber barb(freeChairs, finishedService, shopClosed);
	Customer cust(freeChairs, finishedService, shopClosed);
	// Start consumer thread:
	std::thread barberThd(std::ref(barb));
	// Start customer threads:
	std::vector<std::thread> custThds;
	
	for (std::size_t numCusts = 0; numCusts < 102; numCusts++)
	{
		custThds.push_back(std::thread(std::ref(cust)));
	}
	while (!shopClosed->load())
	{
		// Wait until the shop has closed.
	}
	for (std::size_t numCusts = 0; numCusts < 102; numCusts++)
	{
		custThds[numCusts].join();
	}
	
	barberThd.join();

	return 0;
}