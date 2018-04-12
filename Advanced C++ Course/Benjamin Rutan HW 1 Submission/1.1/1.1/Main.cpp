/* Main.cpp (exercise 1.1)
Description: 
	* Completed exercises 1-3. 
*/
#include <algorithm>
#include <complex>
#include <iostream>
#include <numeric>
#include <vector>
#include "Functions-1.hpp"

int main()
{
	std::vector<double> values;
	for (unsigned i = 0; i < 20; i++)
		values.push_back(i);
	/* Exercise 1: */
	// a) Alter array using lambda, test by-value vs. by-reference capture: 
	double scalar = 2, sum = 0;
	// By reference case:
	auto multByScalar_ByRef = [scalar](auto &vec)
	{
		for (auto iter = vec.begin(); iter != vec.end(); iter++)
			*iter *= scalar;
	};
	auto multByScalar_ByVal = [scalar](auto vec)
	{
		for (auto iter = vec.begin(); iter != vec.end(); iter++)
			*iter *= scalar;
	};
	// Test by value case:
	multByScalar_ByVal(values);
	sum = std::accumulate(values.begin(), values.end(), 0.0);
	std::cout << "By-value Lambda sum: " << sum << std::endl;
	// Test by reference case:
	multByScalar_ByRef(values);
	sum = std::accumulate(values.begin(), values.end(), 0.0);
	std::cout << "By-reference Lambda sum: " << sum << std::endl;

	/* b) Print values of modified array using auto keyword */
	std::cout << "Modified Vector contents: { ";
	for (auto iter = values.begin(); iter != values.end(); iter++)
		std::cout << *iter << ((iter + 1 != values.end()) ? ", " : "");
	std::cout << "}" << std::endl;

	/* c) Create lambda to return both minimum and maximum value of vector */
	std::pair<double, double> minMax; // [ min, max ]
	auto findMinMax = [&](auto vec)
	{
		for (auto iter = vec.begin(); iter != vec.end(); iter++)
		{
			if (*iter < minMax.first)
			{
				minMax.first = *iter;
			}
			if (*iter > minMax.second)
			{
				minMax.second = *iter;
			}
		}
	};
	findMinMax(values);
	std::cout << "Min: " << std::get<0>(minMax) << ", Max: " << std::get<1>(minMax) << std::endl;

	/* d) Compare c with std::minmax_element */
	std::pair<std::vector<double>::iterator, std::vector<double>::iterator> minMaxIters;
	minMaxIters = std::minmax_element(values.begin(), values.end());
	std::cout << "Min: " << *std::get<0>(minMaxIters) << ", Max: " << *std::get<1>(minMaxIters) << std::endl;
	/* Conclusion: though answers are the same, std::minmax_element requires uses a vector iterator pair, reducing readability and overcomplicating matters. */
	
	/* Exercise 2: */
	std::vector<int> vec{ 1,2,3,4,5 };
	int acc2 = std::accumulate(vec.begin(), vec.end(), 1,
		std::multiplies<int>());
	int accA = accumulate(vec.begin(), vec.end(), 1,
		FOMultiply());
	// a): Implement and test stored lambda 
	auto MyMultiply = [](auto x, auto y) { return x * y; };
	int accB = accumulate(vec.begin(), vec.end(), 1, MyMultiply);
	std::cout << "Testing std::accumulate<>: " << std::endl;
	std::cout << "\tUsing std::multiplies<>: " << acc2 << std::endl;
	std::cout << "\tUsing Function Object: " << accA << std::endl;
	std::cout << "\tUsing Stored Lambda: " << accB << std::endl;
	// Testing complex numbers:
	using Complex = std::complex<double>;
	std::vector<Complex> complexArray{ Complex(1.0, 1.0), Complex(2.0, 2.0) };
	Complex initCVal(1.0, 1.0);
	Complex acc6C = accumulate(complexArray.begin(), complexArray.end(), initCVal, MyMultiply2<Complex>);
	std::cout << "Sum 6, complex numbers: " << acc6C << std::endl;
	/* b): Implement std::accumulate() using std::for_each() and embedded lambda */
	double product = 1;
	std::for_each(vec.begin(), vec.end(), [&](auto val) { product *= val; });
	std::cout << "std::accumulate using lambda result: " << sum << std::endl;
	/* c) Give an example of a stored lambda to be called using an STL algorithm: */
	auto f = [](auto elem) { std::cout << elem << " "; };
	std::cout << "Printing all elements of vec using stored lambda: ";
	std::for_each(vec.begin(), vec.end(), f);
	std::cout << std::endl;

	system("pause");

	return 0;
}