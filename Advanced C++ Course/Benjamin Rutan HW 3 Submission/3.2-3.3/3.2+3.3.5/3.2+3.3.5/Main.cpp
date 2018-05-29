/* Main.cpp (exercise 3.2+3.3.5)
Description:
	* Solutions to problems a-c for exercise 3.2+3.3.5. 
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
	Consumer barber;
	std::thread barberThd(barber);
	std::vector<Producer> customers;
	// Start customer threads:
	std::vector<std::thread> custThds;
	for (std::size_t cust_id = 0; cust_id < 102; cust_id++)
	{
		customers.push_back(Producer(cust_id));
		custThds.push_back(std::thread(customers[cust_id]));
	}
	for (std::size_t cust_id = 0; cust_id < 102; cust_id++)
	{
		custThds[cust_id].join();
	}

	barberThd.join();

	system("pause");
	
	return 0;
}