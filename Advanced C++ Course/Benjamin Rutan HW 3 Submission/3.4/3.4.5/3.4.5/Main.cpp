/* Main.cpp (exercise 3.4.5)
Description:
	* Solutions to problems a-f in exercise 3.4.5.
*/

#include <chrono>
#include <iostream>
#include <omp.h>
#include <numeric>
#include <vector>
#include "Functions.hpp"

int main()
{
	/* 3.4.5 */
	// a) Create large numeric array, sum using accumulate and output processing time:
	constexpr unsigned long long numElements = 100000;
	std::vector<long double> items(numElements, 1);
	// Sum using std::accumulate:
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	long double sum = std::accumulate(items.begin(), items.end(), 0);
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();
	std::cout << "Accumulate direct version:" << std::endl;
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Time: " << duration << " microsecs" << std::endl;

	// b) Execute parallel version of above: 
	start = std::chrono::high_resolution_clock::now();
	sum = Parallel::ParallelAccumulate_Task(items.begin(), items.end());
	auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();
	std::cout << "Parallel task version: " << std::endl;
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Time: " << duration2 << " microsecs" << std::endl;

	// c) Measure speedup of parallel version:
	std::cout << "Speedup vs accumulate direct version: " << static_cast<double>(duration) / static_cast<double>(duration2) << std::endl;
	
	// d) Measure speedup of OpenMP version:
	omp_set_num_threads(2);
	sum = 0;
	start = std::chrono::high_resolution_clock::now();
#pragma omp parallel for reduction (+:sum)
	for (long i = 0; i < items.size(); i++)
	{
		sum += items[i];
	}
	auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();
	std::cout << "OpenMP version: " << std::endl;
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Time: " << duration3 << " microsecs" << std::endl;
	std::cout << "Speedup vs parallel version: " << static_cast<double>(duration2) / static_cast<double>(duration3) << std::endl;
	std::cout << "Speedup vs accumulate direct version: " << static_cast<double>(duration) / static_cast<double>(duration3) << std::endl;

	// e) Use thread version and compare speedup:
	start = std::chrono::high_resolution_clock::now();
	Parallel::ParallelAccumulate_Thread(items.begin(), items.end());
	auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();
	sum = Parallel::output.load();
	std::cout << "Thread version: " << std::endl;
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Time: " << duration4 << " microsecs" << std::endl;
	std::cout << "Speedup vs parallel task version: " << static_cast<double>(duration2) / static_cast<double>(duration4) << std::endl;
	std::cout << "Speedup vs OpenMP version: " << static_cast<double>(duration3) / static_cast<double>(duration4) << std::endl;
	std::cout << "Speedup vs accumulate direct version: " << static_cast<double>(duration) / static_cast<double>(duration4) << std::endl;
	
	// f) Test binary function version of parallel:
	start = std::chrono::high_resolution_clock::now();
	sum = Parallel::ParallelAccumulate_Task_BinFunc(items.begin(), items.end(), [](long double x, long double y) { return x * y; });
	auto duration5 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();
	std::cout << "Binary function version (using tasks): " << std::endl;
	std::cout << "Product: " << sum << std::endl;
	std::cout << "Time: " << duration5 << " microsecs" << std::endl;

	system("pause");

	return 0;
}
