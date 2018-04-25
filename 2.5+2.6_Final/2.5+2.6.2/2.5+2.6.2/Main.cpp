/* Main.cpp (exercise 2.5 + 2.6 Problem 2)
Description:
	* Solution to problem 2. 
*/

#include <iostream>
#include <limits>
#include <stdexcept>
#include "Functions.hpp"

int main()
{
	
	/* 2.5.2 */
	// b) Compare FindEpsilon outputs to std::numeric_limits<>::epsilon() outputs:
	double epsilon1 = FindEpsilon<double>();
	std::cout << "FindEpsilon<double>() == numeric_limits<double>::epsilon(): " << ((epsilon1 == std::numeric_limits<double>::epsilon())? "True": "False") << std::endl;
	int epsilon2 = FindEpsilon<int>();
	std::cout << "FindEpsilon<int>() == numeric_limits<int>::epsilon(): " << ((epsilon2 == std::numeric_limits<int>::epsilon()) ? "True" : "False") << std::endl;
	float epsilon3 = FindEpsilon<float>();
	std::cout << "FindEpsilon<float>() == numeric_limits<float>::epsilon(): " << ((epsilon3 == std::numeric_limits<float>::epsilon()) ? "True" : "False") << std::endl;
	
	system("pause");

	return 0;
}