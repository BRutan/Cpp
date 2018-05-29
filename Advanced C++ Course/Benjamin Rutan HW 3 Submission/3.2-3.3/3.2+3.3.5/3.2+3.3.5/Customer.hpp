/* Customer.hpp (exercise 3.2+3.3.5)
Description:
	* Producer class in the Barbershop problem.




*/

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include "SynchronisedQueue.hpp"

std::condition_variable cv;
std::mutex mut;

class Customer
{
private:
	static unsigned id;
	std::shared_ptr<std::atomic<bool>> finishedService;
	std::shared_ptr<std::atomic<bool>> shopClosed;
public:
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	Customer(std::atomic<bool> *finishedService_in, std::atomic<bool> *closeShop_in, SynchronisedQueue<unsigned> *syncQueue_in) noexcept : finishedService(finishedService_in), shopClosed(closeShop_in), syncQueue(syncQueue_in)
	{
		
	}
	virtual ~Customer()
	{
		finishedService.reset();
		shopClosed.reset();
		syncQueue.reset();
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	void operator()() noexcept
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
		if (syncQueue-> && !shopClosed->load())
		{
			std::cout << "Customer " << id << ": Has entered shop." << std::endl;
			freeChairs->store(freeChairs->load() - 1);
			cv.notify_all();
			cv.wait(mLock, [this] { return finishedService->load(); });
			std::cout << "Customer " << id << ": Has left." << std::endl;
		}
		else if(!freeChairs->load())
		{
			std::cout << "Customer: Left since shop is full." << std::endl;
		}
		else if (shopClosed->load())
		{
			std::cout << "Customer: Left since shop has closed." << std::endl;
		}
	}
};


#endif
