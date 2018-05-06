/* Main.cpp (exercise 3.2+3.3.3)
Description:
	* Solutions to problems a-d in exercise 3.2+3.3.
*/

#include <chrono>
#include <thread>
#include "ActiveObject.hpp"
#include "Functions.hpp"

int main()
{
	/* 3.2+3.3.3 */
	// a) Create thread and function that will be its thread function:
	std::thread thread1(ThreadFunction);
	// b) Create an active object based upon a thread with no associated thread function:
	ActiveObject test1(new std::thread());
	// c) Implement thread functions using function objects, stored lambdas and lambdas:
	ActiveObject test2(new std::thread(storedLambda));
	ActiveObject test3(new std::thread([]() { std::cout << "Lambda()" << std::endl; }));
	ActiveObject test4(new std::thread(ThreadFunctionObject()));
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Done waiting for threads to finish." << std::endl;
	// d) Test ActiveObject functions:
	std::cout << "ActiveObject::HasThread() test: " << std::endl;
	std::cout << "ActiveObject with no thread: " << test1.HasThread() << std::endl;
	std::cout << "ActiveObject with storedLambda thread: " << test2.HasThread() << std::endl;
	std::cout << "ActiveObject with Lambda thread: " << test3.HasThread() << std::endl;
	std::cout << "ActiveObject with ThreadFunctionObject thread: "<< test4.HasThread() << std::endl;
	// Join the thread1 function if joinable.
	if (thread1.joinable())
		thread1.join();

	system("pause");

	return 0;
}