/* Main.cpp (exercise 2.2.1)
Description:
	* Solutions to exercise 2.2.1.
*/
#include <array>
#include <complex>
#include <deque>
#include <queue>
#include <vector>
#include "Functions.hpp"

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
	
	system("pause");

	return 0;
}