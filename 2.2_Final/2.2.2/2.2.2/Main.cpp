/* Main.cpp (exercise 2.2.2)
Description:
	* Solutions to exercise 2.2.2.
*/
#include <array>
#include <complex>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>

#include "Exception.hpp"
#include "SizeExcept.hpp"

int main()
{
	/* 2.2.2: */
	// a) Test the std::is_array<> function:
	std::cout << "is_array<> Test:" << std::endl;
	std::cout << "double: " << std::is_array<double>() << std::endl;
	std::cout << "double[]: " << std::is_array<double[]>() << std::endl;
	std::cout << "vector<double>: " << std::is_array<std::vector<double>>() << std::endl;
	std::cout << "queue<double>: " << std::is_array<std::queue<double>>() << std::endl;
	std::cout << "deque<double>: " << std::is_array<std::deque<double>>() << std::endl;
	std::cout << "array<double, 20>: " << std::is_array<std::array<double, 20>>() << std::endl;
	std::cout << "Exception: " << std::is_array<Exceptions::Exception>() << std::endl;
	std::cout << "string: " << std::is_array<std::string>() << std::endl;
	std::cout << "is_array<int>: " << std::is_array<std::is_array<int>>() << std::endl;
	
	// b) Find rank and extent of multidimensional type:
	std::cout << "int[12][3][4][5] properties: " << std::endl;
	std::cout << "rank: " << std::rank<int[12][3][4][5]>() << std::endl;
	std::cout << "extent of 1st dimension: " << std::extent<int[12][3][4][5], 0>() << std::endl;
	std::cout << "extent of 2nd dimension: " << std::extent<int[12][3][4][5], 1>() << std::endl;
	std::cout << "extent of 3rd dimension: " << std::extent<int[12][3][4][5], 2>() << std::endl;
	std::cout << "extent of 4th dimension: " << std::extent<int[12][3][4][5], 3>() << std::endl;
	std::cout << "extent of 5th dimension: " << std::extent<int[12][3][4][5], 4>() << std::endl;
	// c) Call std::remove_extent and std::remove_all_extent on array and test impact:
	typedef std::remove_extent<int[12][3]>::type A;
	typedef std::remove_extent<int[3]>::type B;
	typedef std::remove_all_extents<int[12][3][4][5]>::type C;
	std::cout << "Testing remove_extent() and remove_all_extent() on int[12][3][4][5]: " << std::endl;
	std::cout << std::is_same<int, A>() << std::endl;
	std::cout << std::is_same<int, B>() << std::endl;
	std::cout << std::is_same<int, C>() << std::endl;

	// Conclusion: remove_extent removes first dimension of array type, while remove_all_extents removes all dimensions.

	system("pause");

	return 0;
}