/* Functions.hpp (exercise 3.4.4)
Description:
	* Function to test packaged task class.
*/


#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <chrono>
#include <random>
#include <thread>

// Function sleeps for random integer between 0 and 1000, then returns cos(x) * exp(y):
double compute(double x, double y)
{
	std::default_random_engine dre(42);
	std::uniform_int_distribution<int> delay(0, 1000);
	std::this_thread::sleep_for(std::chrono::milliseconds(delay(dre)));

	return std::cos(x) * std::exp(y);
}



#endif
