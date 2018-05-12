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


class Customer
{
private:
	std::shared_ptr<std::mutex> mut;
	std::shared_ptr<std::atomic<unsigned>> freeChairs;
	std::shared_ptr<std::atomic<bool>> finishedService;
	std::shared_ptr<std::atomic<bool>> shopClosed;
	std::condition_variable cond;
public:
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	Customer(std::mutex *mut_in, std::atomic<bool> *closeShop_in, std::atomic<unsigned> *freeChairs_in, std::atomic<bool> *finishedService_in) : mut(mut_in), shopClosed(closeShop_in), cond(), freeChairs(freeChairs_in), finishedService(finishedService_in)
	{

	}
	Customer(const Customer&) = delete;
	virtual ~Customer()
	{

	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	void operator()()
	{
		std::unique_lock<std::mutex> mLock(*mut);
		std::this_thread::sleep_for(std::chrono::seconds(10));
		if (freeChairs->load() && !shopClosed->load())
		{
			std::cout << "Customer has entered shop." << std::endl;
			freeChairs->store(*freeChairs - 1);
			// Wait for Barber to finish.
			cond.wait(mLock, [this] {return finishedService->load(); });
			std::cout << "Customer has left." << std::endl;
		}
		else if(!freeChairs->load())
		{
			std::cout << "Customer has balked since shop is full." << std::endl;
		}
		else if (shopClosed->load())
		{
			std::cout << "Customer has balked since shop is closed." << std::endl;
		}
	}
	Customer& operator=(const Customer&) = delete;
};



#endif
