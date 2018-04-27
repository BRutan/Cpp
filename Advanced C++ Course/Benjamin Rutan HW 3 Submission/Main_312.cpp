/* Main.cpp (exercise 2.3.2)
Description:
	*


*/

#include <iostream>
#include <mutex>
#include <thread>


int main()
{
	/* 2.3.2 */
	// a) Use std::mutex synchronisation to control access to a shared resource:
	std::mutex coutMutex;
	std::unique_lock<std::mutex> uniqueLock(coutMutex);

	


	system("pause");

	return 0;
}