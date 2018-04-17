/* Main.cpp (problem 2.3)
Description:
	* Solutions to exercise 2.3.1-2.3.4.
*/

#include <array>
#include <functional>
#include <iostream>
#include <vector>
#include "Deprecated.hpp"
#include "Functions.hpp"

int main()
{
	/* 2.3.1 */
	// a-f) Test the deprecated classes, enums and functions:
	func();
	Depr deprecated;
	NotDepr<double> notDeprecated;
	notDeprecated.f();
	NotDepr<int> deprecated2;
	num;
	Color::Blue;
	One;

	/* 2.3.2 */
	// a) Modify lambda to use move semantics:
	int size = 4; double val = 2.71;
	std::vector<double> data(size, val);
	// Updated capture mode:
	auto fun = [data = std::move(data)]() mutable
	{
		for (std::size_t i = 0; i < data.size(); ++i)
		{
			data[i] = 3.14; std::cout << data[i] << ",";
		}
		std::cout << '\n';
	};

	fun();

	std::cout << "Number of elements in data: " << data.size() << std::endl;
	// b) Create the code snippet:
	int x = 1'000'000;
	auto fun4 = [&r = x]() { r *= 2; std::cout << "\nr: " << r; };
	// c) Migrate C++11 code, using bind to emulate C++14 code that uses init capture:
	int size2 = 3; double val2 = 1.41;
	std::vector<double> data2(size2, val2);
	std::array<double, 3> data3 = { 1.2, 2.4, 4.7 };
	auto fun3 = [data2 = std::move(data2), data3 = std::move(data3)] ()
	{
		for (std::size_t i = 0; i < data2.size(); ++i)
		{
			std::cout << data2[i] << "/";
		}
		std::cout << '\n';
		for (std::size_t i = 0; i < data3.size(); ++i)
		{
			std::cout << data3[i] << '/';
		}
	};
	fun3();

	if (data2.size() == 0 || data3.size() == 0)
	{
		std::cout << "\nDouble arrays have no elements, OK\n";
	}
	else
	{
		std::cout << "\n Ouch!\n";
		for (std::size_t i = 0; i < data2.size(); ++i)
			std::cout << data2[i] << "^";
		for (std::size_t i = 0; i < data3.size(); ++i)
			std::cout << data3[i] << "^";
	}

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
	std::cout << f2(x) << std::endl;

	// c) Test the min and max functions:
	auto h1 = min(f, g);
	auto h2 = max(f, g);
	std::cout << "min(f,g): " << h1(2.0) << std::endl;
	std::cout << "max(f,g): " << h2(2.0) << std::endl;

	auto h3 = min(h1, max(2 * f, 3 * g));
	auto h4 = max(h2, max(-2 * f, 3 * g));

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