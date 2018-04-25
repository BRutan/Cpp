/* Main.cpp (exercise 2.5 + 2.6, problem 1)
Description:
	* Solutions to problem 1 in exercise 2.5+2.6.
*/

#include <iostream>
#include <limits>
#include <stdexcept>
#include "Functions.hpp"

int main()
{
	/* Problem 1 */
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

	system("pause");

	return 0;
}