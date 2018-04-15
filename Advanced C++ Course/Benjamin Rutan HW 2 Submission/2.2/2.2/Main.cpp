/* Main.cpp
Description:
	*


*/
#include <array>
#include <complex>
#include <deque>
#include <queue>
#include <vector>


#include "Exception.hpp"
#include "Functions.hpp"
#include "SizeExcept.hpp"

int main()
{
	/* 2.2.1: */
	// a) Test the Addition function:
	double numeric1 = 20, numeric2 = 30;
	std::vector<double> vec1, vec2, vecSum;
	std::vector<std::complex<double>> complexVec1, complexVec2, complexSum;
	std::array<double, 20> arr1, arr2, arrSum;
	for (double i = 0; i < 20; i++)
	{
		vec1.push_back(i);
		vec2.push_back(-i);
		if (i < 5)
		{
			complexVec1.push_back(std::complex<double>(i));
			complexVec2.push_back(std::complex<double>(-i));
		}
		arr1[i] = i;
		arr2[i] = -i;
	}

	vecSum = Addition(vec1, vec2);
	arrSum = Addition(arr1, arr2);
	complexSum = Addition(complexVec1, complexVec2);
	std::cout << "Addition Test: " << std::endl;
	std::cout << "vec1: "; PrintContainer(vec1); std::cout << std::endl;
	std::cout << "vec2: "; PrintContainer(vec2); std::cout << std::endl;
	std::cout << "vecSum: "; PrintContainer(vecSum); std::cout << std::endl;
	std::cout << "arr1: "; PrintContainer(arr1); std::cout << std::endl;
	std::cout << "arr2: "; PrintContainer(arr2); std::cout << std::endl;
	std::cout << "arrSum: "; PrintContainer(arrSum); std::cout << std::endl;
	std::cout << "complexVec1: "; PrintContainer(complexVec1); std::cout << std::endl;
	std::cout << "complexVec2: "; PrintContainer(complexVec2); std::cout << std::endl;
	std::cout << "complexSum: "; PrintContainer(complexSum); std::cout << std::endl;
	std::cout << "20 + 30 = " << Addition(numeric1, numeric2) << std::endl;

	// b) Test the additive inverse of a vector:
	AdditiveInverse(vec1);
	AdditiveInverse(arr1);
	AdditiveInverse(complexVec1);
	AdditiveInverse(numeric1);
	std::cout << "Additive Inverse Test: " << std::endl;
	std::cout << "vec1: "; PrintContainer(vec1); std::cout << std::endl;
	std::cout << "arr1: "; PrintContainer(arr1); std::cout << std::endl;
	std::cout << "complexVec1: "; PrintContainer(complexVec1); std::cout << std::endl;
	std::cout << "numeric1: " << numeric1 << std::endl;
	// c) Test scalar multiplication function:
	vec1 = ScalarMult(vec1, 3.0);
	arr1 = ScalarMult(arr1, 3.0);
	complexVec1 = ScalarMult(complexVec1, 3.0);
	try 
	{
		ScalarMult(numeric1, 3.0);
	}
	catch (Exceptions::Exception&)
	{

	}
	std::cout << "Scalar Multiplication Test: " << std::endl;
	std::cout << "vec1: "; PrintContainer(vec1); std::cout << std::endl;
	std::cout << "arr1: "; PrintContainer(arr1); std::cout << std::endl;
	std::cout << "complexVec1: "; PrintContainer(complexVec1); std::cout << std::endl;
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

	/* 2.2.3 */
	// a) Test defined alises that serve as type converters:
	

	system("pause");

	return 0;
}