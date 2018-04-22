/*

　
　
　
*/

#include <boost/math/special_functions/next.hpp>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "Functions.hpp"

int main()
{
	/* 2.5.1 */
	// a) Test the classify function with following values:
	double val = std::numeric_limits<double>::max();
	std::cout << "For val = numeric_limits<double>::max(): " << std::endl;
	std::cout << "val classification: " << Classify(val) << std::endl;
	std::cout << "2.0 * val classification: " << Classify(2.0 * val) << std::endl;
	std::cout << "3.1415 + val classification: " << Classify(3.1415 + val) << std::endl;
	double val2 = std::numeric_limits<double>::min() - 3.1415;
	std::cout << "For val2 = numeric_limits<double>::min(): " << std::endl;
	std::cout << "val2 classification: " << Classify(val2) << std::endl;
	std::cout << "val2 / 2.0 classification: " << Classify(val2 / 2.0) << std::endl;
	std::cout << "DBL_MIN / 2.0 classification: " << Classify(DBL_MIN / 2.0) << std::endl;
	// b) Test std::isfinite, std::isinf, std::isnan, std::isnormal on values:
	double factor = 2.0; 
	val = factor*std::numeric_limits<double>::max();
	std::cout << "For val = 2.0 * numeric_limits<double>::max()" << std::endl;

	std::cout << "val classifications: " << std::endl;
	std::cout << "\t isfinite(val): " << std::isfinite(val) << std::endl;
	std::cout << "\t isfinite(val): " << std::isinf(val) << std::endl;
	std::cout << "\t isfinite(val): " << std::isnan(val) << std::endl;
	std::cout << "\t isfinite(val): " << std::isnormal(val) << std::endl;

	std::cout << "val - val classification: " << std::endl;
	std::cout << "\t isfinite(val - val): " << std::isfinite(val - val) << std::endl;
	std::cout << "\t isfinite(val - val): " << std::isinf(val - val) << std::endl;
	std::cout << "\t isfinite(val - val): " << std::isnan(val - val) << std::endl;
	std::cout << "\t isfinite(val - val): " << std::isnormal(val - val) << std::endl;

	std::cout << "sqrt(-1.0) classification: " << std::endl;
	std::cout << "\t isfinite(sqrt(-1.0)): " << std::isfinite(std::sqrt(-1.0)) << std::endl;
	std::cout << "\t isfinite(sqrt(-1.0)): " << std::isinf(std::sqrt(-1.0)) << std::endl;
	std::cout << "\t isfinite(sqrt(-1.0)): " << std::isnan(std::sqrt(-1.0)) << std::endl;
	std::cout << "\t isfinite(sqrt(-1.0)): " << std::isnormal(std::sqrt(-1.0)) << std::endl;

	std::cout << "log(0.0) classification: " << std::endl;
	std::cout << "\t isfinite(log(0.0)): " << std::isfinite(std::log(0.0)) << std::endl;
	std::cout << "\t isfinite(log(0.0)): " << std::isinf(std::log(0.0)) << std::endl;
	std::cout << "\t isfinite(log(0.0)): " << std::isnan(std::log(0.0)) << std::endl;
	std::cout << "\t isfinite(log(0.0)): " << std::isnormal(std::log(0.0)) << std::endl;

	std::cout << "exp(val) classification: " << std::endl;
	std::cout << "\t isfinite(exp(val)): " << std::isfinite(std::exp(val)) << std::endl;
	std::cout << "\t isfinite(exp(val)): " << std::isinf(std::exp(val)) << std::endl;
	std::cout << "\t isfinite(exp(val)): " << std::isnan(std::exp(val)) << std::endl;
	std::cout << "\t isfinite(exp(val)): " << std::isnormal(std::exp(val)) << std::endl;

	/* 2.5.2 */
	// b) Compare FindEpsilon outputs to std::numeric_limits<>::epsilon() outputs:
	double epsilon1 = FindEpsilon<double>();
	std::cout << "FindEpsilon<double>() == numeric_limits<double>::epsilon(): " << ((epsilon1 == std::numeric_limits<double>::epsilon())? "True": "False") << std::endl;
	int epsilon2 = FindEpsilon<int>();
	std::cout << "FindEpsilon<int>() == numeric_limits<int>::epsilon(): " << ((epsilon2 == std::numeric_limits<int>::epsilon()) ? "True" : "False") << std::endl;
	float epsilon3 = FindEpsilon<float>();
	std::cout << "FindEpsilon<float>() == numeric_limits<float>::epsilon(): " << ((epsilon3 == std::numeric_limits<float>::epsilon()) ? "True" : "False") << std::endl;

	/* 2.5.3 */
	// Experiment with the Boost C++ math toolkit:
	// Test float_distance:
	double a = 0.1; double b =
		a + std::numeric_limits<double>::min();
	std::cout << "Distance between 0.1 and 0.1 + numeric_limits<double>::min(): " << boost::math::float_distance(a, b) << std::endl;
	a = 1.0; b = 0.0;
	std::cout << "Distance between 1.0 and 0.0: " << boost::math::float_distance(a, b) << std::endl;
	// Test float_next:
	unsigned long long steps = 0;
	try
	{
		// Will throw exception in float_next if std::numeric_limits<double>::max() minus any number is used as an input, thus need to use literal:
		b = 1.797693134862315805e+308 - std::numeric_limits<double>::min();
		while(true)
		{
			b = boost::math::float_next(b);
			steps++;
		}
	}
	catch (std::overflow_error& err)
	{
		std::cout << "Overflow exception caught:" << std::endl;
		std::cout << err.what() << std::endl;
		std::cout << "Steps between numeric_limits<double>::max() - 10 and numeric_limits<double>::max(): " << steps << std::endl;
	}
	// Test float_prior:
	steps = 0;
	try
	{
		b = std::numeric_limits<double>::min() + 1.0;
		while (true)
		{
			b = boost::math::float_prior(b);
			steps++;
		}
	}
	catch (std::underflow_error& err)
	{
		std::cout << "Underflow exception caught: " << std::endl;
		std::cout << err.what() << std::endl;
		std::cout << "Steps between ... " << steps << std::endl;
	}
	// Test boost::nextafter():
	std::cout << "nextafter(): " << std::nextafter(a, b) << std::endl;
	system("pause");

	return 0;
}
