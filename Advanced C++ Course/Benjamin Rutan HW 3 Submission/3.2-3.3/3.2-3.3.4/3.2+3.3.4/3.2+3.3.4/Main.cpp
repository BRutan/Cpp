/* Main.cpp (exercise 3.2+3.3.4)
Description:
	* Solutions to problems a-d in exercise 3.2+3.3.4.
*/

#include <thread>
#include "Resources.hpp"

int main()
{
	// b) Create thread function, updates resources by acquiring the lock, waiting on
	// worker ready flag to be set, updating resource then notifying master:
	// d) Replace atomic<bool> with atomic_flag.
	std::cout << "Master is called." << std::endl;
	std::thread worker(WorkerThread);
	{
		// std::lock_guard<std::mutex> mLock(m);
		// workerReady.store(true);
		flag.test_and_set(std::memory_order_acquire);
	}
	std::cout << "Master has notified worker. Wait for response." << std::endl;
	// cv.notify_one();
	{
		// std::unique_lock<std::mutex> mLock(m);
		while (flag.test_and_set(std::memory_order_release))
		{
			// Do nothing while waiting for signal from atomic_flag:
		}
		// cv.wait(mLock, [] { return masterReady.atomic<bool>load(); });
	}
	std::cout << "Master back. " << std::endl;
	std::cout << "Data: " << data << std::endl;
	worker.join();
	// Note: if using atomic_flag, can omit using lock guards, mutexes and condition variables. 

	system("pause");

	return 0;
}