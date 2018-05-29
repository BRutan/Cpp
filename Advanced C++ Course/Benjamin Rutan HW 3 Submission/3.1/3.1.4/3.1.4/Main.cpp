/* Main.cpp (exercise 3.1.4)
Description:
	* Solutions to problems a-d for exercise 3.1.4.
*/


#include <iostream>
#include <thread>
#include <vector>
#include "ProducerConsumer.hpp"
#include "SynchronisedQueue.hpp"

int main()
{
	/* 3.1.4 */
	// d) Test queue using producer and consumer threads:
	// Test synchronised queue functionality with producer and consumer threads:
	std::thread producerThd(Producer(1));
	std::thread consumerThd(Consumer(2));

	producerThd.join();
	consumerThd.join();

	system("pause");

	return 0;
}