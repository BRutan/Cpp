/* Main.cpp (exercise 2.8.5)
Description:
	* Solutions to exercise 2.8.5.
*/

#include <bitset>
#include <functional>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>
#include "BitMatrix.hpp"

int main()
{
	/* 2.8.5 */
	// Test full functionality of BitMatrix:
	BitMatrix<8, 8> bm1(345);
	BitMatrix<2, 2> bm2(220);
	BitMatrix<2, 2> bm3(121);

	std::cout << "For 8 x 8 BitMatrix: " << bm1 << std::endl;
	std::cout << "trueCount(): " << bm1.trueCount() << std::endl;
	std::cout << "flip(): " << bm1.flip() << std::endl;
	std::cout << "reset(): " << bm1.reset() << std::endl;
	std::cout << "all(): " << bm1.all() << std::endl;
	std::cout << "none(): " << bm1.none() << std::endl;
	std::cout << "any(): " << bm1.any() << std::endl;
	std::cout << "At(0, 0): " << bm1.At(0, 0) << std::endl;
	try
	{
		std::cout << "At(9, 9): " << bm1.At(9, 9) << std::endl;
	}
	catch (std::out_of_range &err)
	{
		std::cout << "Out of range exception caught: " << err.what() << std::endl;
	}
	// Test boolean operators:
	std::cout << "For BitMatrices: " << bm2 << "\n and " << bm3 << ":" << std::endl;
	std::cout << "AND: " << (bm2 & bm3) << std::endl;
	std::cout << "OR: " << (bm2 | bm3) << std::endl;
	std::cout << "XOR: " << (bm2 ^ bm3) << std::endl;

	system("pause");

	return 0;
}
