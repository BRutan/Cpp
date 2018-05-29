/* Barber.hpp (exercise 3.2+3.3.5)
Description:
	* Consumer class for Producer-Consumer schema.


*/



#ifndef BARBER_HPP
#define BARBER_HPP



#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>

#include "Customer.hpp"
#include "SynchronisedQueue.hpp"

class Barber
{
private:
	std::shared_ptr<std::atomic<bool>> finishedService;
	std::shared_ptr<std::atomic<bool>> shopClosed;
	std::shared_ptr<SynchronisedQueue<unsigned>> syncQueue;
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Barber(std::atomic<bool> *finishedService_in, std::atomic<bool> *closeShop_in, SynchronisedQueue<unsigned> *syncQueue_in) noexcept : finishedService(finishedService_in), shopClosed(closeShop_in), syncQueue(syncQueue_in)
	{

	}
	virtual ~Barber()
	{
		finishedService.reset();
		shopClosed.reset();
		syncQueue.reset();
	}
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	void operator()() noexcept
	{
		freeChairs->store(MAXFREECHAIRS);
		finishedService->store(false);
		shopClosed->store(false);
		unsigned serviceCount = 0;
		std::unique_lock<std::mutex> mLock(mut);
		cv.notify_all();
		while (serviceCount < 20)
		{
			// Wait for customer to arrive:
			std::cout << "Barber: Waiting for customers..." << std::endl;
			// Wait for customers to arrive:
			cv.wait(mLock, [this] { return freeChairs->load() < MAXFREECHAIRS; });
			// Service customers until all chairs are free:
			while (freeChairs->load() < MAXFREECHAIRS && serviceCount < 20)
			{
				finishedService->store(false);
				std::cout << "Barber: Cutting hair..." << std::endl;
				std::cout << "# of occupied chairs: " << MAXFREECHAIRS - freeChairs->load() << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(5));
				std::cout << "Barber: Done cutting hair." << std::endl;
				finishedService->store(true);
				freeChairs->store(*freeChairs + 1);
				cv.notify_all();
				serviceCount++;
			}
		}
		// Close the shop:
		std::cout << "Barber: Shop has closed." << std::endl;
		shopClosed->store(true); 
	}
};


#endif
