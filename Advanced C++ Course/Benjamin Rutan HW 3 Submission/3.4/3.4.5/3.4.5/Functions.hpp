/* Functions.hpp (exercise 3.4.5)
Description:
	* Functions that parallelize the std::accumulate function.
*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <atomic>
#include <chrono>
#include <future>
#include <numeric>
#include <thread>

namespace Parallel
{
	std::atomic<long double> output = 0;

	template<typename Iterator>
	void ParallelAccumulate_Thread(const Iterator &begin, const Iterator &end)
	{
		auto size = end - begin;
		// Recursive base case:
		if (size < 1000)
		{
			output.store(output.load() + std::accumulate(begin, end, 0));
		}
		else
		{
			// Recursively call this function to divide work among multiple threads:
			ParallelAccumulate_Thread<Iterator>(begin, begin + (size - 1) / 2);
			std::thread recursion(ParallelAccumulate_Thread<Iterator>, begin + (size - 1)/ 2, end);
			recursion.join();
		}
	}
	template<typename Iterator>
	long double ParallelAccumulate_Task(const Iterator &begin, const Iterator &end)
	{
		auto size = end - begin;
		// Recursive base case:
		if (size < 1000)
		{
			return std::accumulate(begin, end, 0);
		}
		else
		{
			// Recursively call this function to divide work among multiple threads:
			return ParallelAccumulate_Task<Iterator>(begin, begin + (size - 1) / 2) + std::async(std::launch::async, ParallelAccumulate_Task<Iterator>, begin + (size - 1) / 2, end).get();
		}
	}
	// Note: additional overhead of starting new threads and recursive calls causes code to take longer to execute.
	template<typename Iterator, typename BinFunc>
	long double ParallelAccumulate_Task_BinFunc(const Iterator &begin, const Iterator &end, BinFunc func)
	{
		auto size = end - begin;
		if (size < 1000)
		{
			return std::accumulate(begin, end, 1, func);
		}
		else
		{
			// Recursively call this function to divide work among multiple threads:
			return func(ParallelAccumulate_Task_BinFunc<Iterator, BinFunc>(begin, begin + (size - 1) / 2, func), std::async(std::launch::async, ParallelAccumulate_Task_BinFunc<Iterator, BinFunc>, begin + (size - 1) / 2, end, func).get());
		}
	}
}

#endif
