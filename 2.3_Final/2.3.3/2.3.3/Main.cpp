/* Main.cpp (exercise 2.3.3)
Description:
	* Solutions to exercise 2.3.3.
*/

#include <array>
#include <functional>
#include <iostream>
#include <vector>
#include "Functions.hpp"

int main()
{
	/* 2.3.3 */
	// a) Test defined function operators:
	ScalarFunction f = [](double x) {return x * x; };
	ScalarFunction g = [=](double x) {return x; };
	std::cout << g(2) << ", " << g(8) << "*";
	
	// Set I: Arithmetic functions
	double scale = 2.0;
	auto fA = 2.0 *(f + g);
	auto fM = f - g;
	auto fD = f / g;
	auto fMul = f * g;
	auto fC = g << g << 4.0 * g;
	auto fMinus = -(f + g);

	double y = 5.0;
	std::cout << fA(y) << ", " << fM(y) << ", " << fD(y) << ", "
		<< fMul(y) << ", compose: " << fC(y) << ", " << fMinus(y) << std::endl;
	// b) Test defined trigonometric functions:
	auto ftmp = log(g); 
	auto ftmp2 = cos(f); 
	auto f2 = (abs(exp(g))*log(g) + sqrt(ftmp)) / ftmp2; 
	std::cout << f2(y) << std::endl;

	// c) Test the min and max functions:
	auto h1 = min(f, g);
	auto h2 = max(f, g);
	std::cout << "min(f,g)(2.0): " << h1(2.0) << std::endl;
	std::cout << "max(f,g)(2.0): " << h2(2.0) << std::endl;

	auto h3 = min(h1, max(2 * f, 3 * g));
	auto h4 = max(h2, max(-2 * f, 3 * g));
	std::cout << "min(h2, max(-2f,3g))(2.0): " << h3(2.0) << std::endl;
	std::cout << "min(h1, max(2f,3g))(2.0): " << h3(2.0) << std::endl;

	system("pause");

	return 0;
}