/* Main.cpp (exercise 2.3.4)
Description:
	* Solutions to exercise 2.3.4.
*/

#include <array>
#include <functional>
#include <iostream>
#include <vector>
#include "Functions.hpp"

int main()
{
	/* 2.3.4 */
	// Test the emulations of deprecated C++98 STL bind functions:
	std::function<double(const double&, const double&)> fxy = [](const double &in_1, const double &in_2) { return in_1 * in_2 * -9; };
	double yval = 10.0; 
	ScalarFunction fx = bind2nd<double>(fxy, yval); 
	std::cout << fx(3.0) << std::endl;
	// Test new bind code on STL algorithms 
	std::vector<double> vec(10, 2.0); 
	std::transform(vec.begin(), vec.end(), vec.begin(), fx); 
	for (auto i = 0; i < vec.size(); ++i) 
	{ 
		std::cout << vec[i] << ","; 
	}
	std::cout << std::endl;

	system("pause");

	return 0;
}