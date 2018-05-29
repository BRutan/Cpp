/* ProducerConsumer.hpp (exercise 3.2+3.3.5)
Description:
	* Producer stores values in shared synchronised queue, consumer prints values to stdout.
*/


#ifndef PRODUCERCONSUMER_HPP
#define PRODUCERCONSUMER_HPP

#include <atomic>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include "SynchronisedQueue.hpp"

SynchronisedQueue<unsigned> syncQueue; /* Queue contains customer ids. */
std::atomic<bool> shopClosed;
std::atomic<unsigned> dequeued;
std::mutex coutMutex;

class Producer /* Customer class */
{
private:
	int m_id;
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Producer(int id) noexcept : m_id(id)
	{

	}
	virtual ~Producer()
	{

	}
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	void operator()() noexcept					
	{
		// std::this_thread::sleep_for(std::chrono::seconds(3));
		std::unique_lock<std::mutex> guard(coutMutex, std::defer_lock);
		if (!syncQueue.Full() && !shopClosed.load())
		{
			guard.lock();
			std::cout << "Customer " << m_id << ": Has entered shop." << std::endl;
			guard.unlock();
			syncQueue.Enqueue(m_id);
			// Wait for barber to finish:
			while (dequeued.load() != m_id && !shopClosed.load())
			{

			}
			if (shopClosed.load())
			{
				guard.lock();
				std::cout << "Customer " << m_id << ": Left since shop has closed." << std::endl;
				guard.unlock();
			}
			else
			{
				guard.lock();
				std::cout << "Customer " << m_id << ": Has left." << std::endl;
				guard.unlock();
			}
		}
		else if (syncQueue.Full())
		{
			guard.lock();
			std::cout << "Customer " << m_id << ": Left since shop is full." << std::endl;
			guard.unlock();
		}
		else if (shopClosed.load())
		{
			guard.lock();
			std::cout << "Customer" << m_id << ": Left since shop has closed." << std::endl;
			guard.unlock();
		}
	}
};

class Consumer				/* Barber class */
{
public:
	/////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////
	Consumer() noexcept
	{
		
	}
	virtual ~Consumer()
	{

	}
	/////////////////////////////
	// Overloaded Operators:
	/////////////////////////////
	void operator()() noexcept					/* Read data from the synchronised queue. */
	{
		shopClosed.store(false);
		unsigned serviceCount = 0;
		std::unique_lock<std::mutex> guard(coutMutex);
		while (serviceCount < 20)
		{
			// Wait for customers to arrive:
			std::cout << "Barber: Waiting for customers to arrive..." << std::endl;
			guard.unlock();
			while (syncQueue.Size() == 0)
			{
				// wait until customer has arrived.
			}
			while (syncQueue.Size() && serviceCount < 20)
			{
				guard.lock();
				std::cout << "Barber: Cutting hair..." << std::endl;
				guard.unlock();
				std::this_thread::sleep_for(std::chrono::seconds(5));
				guard.lock();
				std::cout << "Barber: Finished cutting hair." << std::endl;
				guard.unlock();
				dequeued.store(syncQueue.Dequeue());
				serviceCount++;
			}
		}
		guard.lock();
		std::cout << "Barber: Closed shop. " << std::endl;
		guard.unlock();
		shopClosed.store(true);
	}
};

#endif