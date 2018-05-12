/* Barber.hpp (exercise 3.2+3.3.5)
Description:
	* Consumer class for Producer-Consumer schema.


*/



#ifndef BARBER_HPP
#define BARBER_HPP

#define MAXFREECHAIRS 20

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>

class Barber
{
private:
	std::shared_ptr<std::mutex> mut;
	std::shared_ptr<std::atomic<unsigned>> freeChairs;
	std::shared_ptr<std::atomic<bool>> finishedService;
	std::shared_ptr<std::atomic<bool>> shopClosed;
	std::condition_variable cond;
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Barber(std::mutex *mut_in, std::atomic<bool> *custArr_in, std::atomic<unsigned> *freeChairs_in, std::atomic<bool> *finishedService_in, std::atomic<bool> *closeShop_in) : mut(mut_in), freeChairs(freeChairs_in), finishedService(finishedService_in), shopClosed(closeShop_in), cond()
	{

	}
	virtual ~Barber()
	{

	}
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	void operator()()
	{
		std::unique_lock<std::mutex> mLock(*mut);
		unsigned serviceCount = 0; // Close shop after servicing 100 customers.
		while (serviceCount < 100)
		{
			// Wait for customer to arrive:
			std::cout << "Barber is waiting for customer..." << std::endl;
			if (freeChairs->load() == MAXFREECHAIRS)
				cond.wait(mLock, [this] { return freeChairs->load(); });
			// Service customers until no more free chairs:
			while (freeChairs->load() != MAXFREECHAIRS)
			{
				finishedService->store(false);
				std::cout << "Barber is cutting hair..." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(5));
				std::cout << "Done cutting hair. Customer has departed." << std::endl;
				finishedService->store(true);
				freeChairs->store(*freeChairs + 1);
				serviceCount++;
				cond.notify_all();
			}
		}
		// Close the shop:
		shopClosed->store(true);
	}
};


#endif
