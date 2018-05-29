/* Main.cpp (exercise 3.2+3.3.5)
Description:
	*


*/

#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <Vector>

#include "ProducerConsumer.hpp"
#include "SynchronisedQueue.hpp"

int main()
{
	/* 3.2+3.3.5 */
	// Start barber thread:	
	std::thread barberThd(Consumer);
	// Start customer threads:
	std::vector<std::thread> custThds;
	
	for (std::size_t numCusts = 0; numCusts < 102; numCusts++)
	{
		custThds.push_back(std::thread(Producer(numCusts)));
	}
	for (std::size_t numCusts = 0; numCusts < 102; numCusts++)
	{
		custThds[numCusts].join();
	}
	
	barberThd.join();

	return 0;
}