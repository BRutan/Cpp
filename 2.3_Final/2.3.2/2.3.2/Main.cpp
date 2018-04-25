/* Main.cpp (problem 2.3.2)
Description:
	* Solutions to exercise 2.3.2.
*/

#include <array>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
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

	system("pause");

	return 0;
}