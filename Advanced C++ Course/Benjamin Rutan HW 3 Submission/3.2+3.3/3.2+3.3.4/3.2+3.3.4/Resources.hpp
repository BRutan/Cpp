/* Resources.hpp (exercise 3.2+3.3.4)
Description:
	* Define worker thread and global variables to use in Master-Worker multithreading pattern.
*/

#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>

// Types and data needed:
std::string data; // Shared data between master and worker.
std::mutex m;	  // Ensures no race condition.

// Synchronisation between master and worker:
std::condition_variable cv;

// Initial state of worker and master:
// d) replace atomic<bool> with atomic_flag class:
std::atomic<bool> workerReady = false;
std::atomic<bool> masterReady = false;
std::atomic_flag flag = ATOMIC_FLAG_INIT;

// b) Create worker thread:
// d) Use atomic_flag instead of atomic<bool>:
void WorkerThread()
{
	std::cout << "Worker is called." << std::endl;
	std::unique_lock<std::mutex> mLock(m);
	cv.wait(mLock, [] {return workerReady.load(); });
	/*
	while (!flag.test_and_set(std::memory_order_acquire))
	{
		// Do nothing while waiting...
	}*/
	std::cout << "Worker is processing data. " << std::endl;
	data += "Worker has added data.";
	// Signify that worker has added data:
	// flag.clear(std::memory_order_release);
	masterReady.store(true);
	mLock.unlock();
	cv.notify_one();
	std::cout << "Worker is exited." << std::endl;
}

#endif