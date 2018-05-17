/* Main.cpp (exercise 3.4.4)
Description:
	* Solutions to problems a-c for exercise 3.4.4.
*/


#include <future>
#include <iostream>
#include <queue>
#include "Functions.hpp"

int main()
{
	// a) Task code:
	double x = 0.0; double y = 2.71;

	// A. "Direct" tasks
	std::future<double> fut = std::async(compute, x, y);
	
	// Get the shared data:
	double result = fut.get();
	std::cout << "Result: " << result << '\n';

	// b) Rewrite/port the coee to use a packaged task and delayed execution:
	std::packaged_task<double(double, double)> task(compute);
	fut = task.get_future();
	// Execute task:
	task(x, y);
	
	std::cout << "Packaged Task Result: " << fut.get() << std::endl;
	// c) Create a queue of packaged tasks, dequeue each and execute:
	std::queue<std::packaged_task<double(double, double)>> tasks;
	std::queue<std::future<double>> futures;
	for (unsigned i = 0; i < 20; i++)
	{
		tasks.emplace(std::packaged_task<double(double, double)>(compute));
		futures.emplace(tasks.back().get_future());
	}
	// Dequeue and execute each:
	for (unsigned i = 0; i < tasks.size(); i++)
	{
		tasks.front()(i, i + 2);
		tasks.pop();
	}
	// Display results:
	std::cout << "i\tj\tcos(i) * exp(j)" << std::endl;
	for (unsigned i = 0; i < futures.size(); i++)
	{
		// Note: future will not display until the task has completed:
		std::cout << i << '\t' << i + 2 << '\t' << futures.front().get() << std::endl;
		futures.pop();
	}

	system("pause");

	return 0;
}