/* Resources.hpp (exercise 3.2+3.3.4)
Description:
	*



*/


#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <string>

// Types and data needed:
std::string data; // Shared data between master and worker.
std::mutex m;	  // Ensures no race condition.
std::unique_lock<std::mutex> lock(m);

// Synchronisation between master and worker:
std::condition_variable cv;

// Initial state of worker and master:
std::atomic<bool> workerReady = false;
std::atomic<bool> masterReady = false;

// b) Create thread function for master-worker pattern:
void ThreadFunction()
{
	// Wait for update from the mutex:
	cv.wait(lock, []() { return workerReady.load(); });
	// Update resource once worker is ready:
	data = "Updated.";
	cv.notify_one();
	// Worker performs...


	
}




void Master()
{

}
#endif