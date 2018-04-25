/* Main.cpp (exercise 2.5 + 2.6 Problem 3)
Description:
	* Solution to problem 3.
*/

#include <boost/math/special_functions/next.hpp>
#include <iostream>
#include <limits>
#include <stdexcept>

int main()
{
	
	/* 2.5.3 */
	// Experiment with the Boost C++ math toolkit:
	// Test float_distance:
	double a = 0.1; double b =
		a + std::numeric_limits<double>::min();
	std::cout << "Distance between 0.1 and 0.1 + numeric_limits<double>::min(): " << boost::math::float_distance(a, b) << std::endl;
	a = 1.0; b = 0.0;
	std::cout << "Distance between 1.0 and 0.0: " << boost::math::float_distance(a, b) << std::endl;
	// Test float_next:
	std::cout << "float_next(): " << boost::math::float_next(b) << std::endl;
	try
	{
		boost::math::float_next(std::numeric_limits<double>::max());
	}
	catch (std::overflow_error &err)
	{
		std::cout << "Overflow exception caught:" << std::endl;
		std::cout << err.what() << std::endl;
	}
	// Test float_prior:
	std::cout << "float_prior(): " << boost::math::float_prior(b) << std::endl;
	try
	{
		boost::math::float_prior(std::numeric_limits<double>::min());
	}
	catch (std::overflow_error &err)
	{
		std::cout << "Underflow exception caught: " << std::endl;
		std::cout << err.what() << std::endl;
	}
	// Test nextafter:
	std::cout << "nextafter(): " << std::nextafter(a, b) << std::endl;
	
	// Test float_advance:
	std::cout << "float_advance(): " << boost::math::float_advance(a, 4) << std::endl;

	system("pause");

	return 0;
}