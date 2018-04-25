/* Main.cpp (exercise 2.8.4)
Description:
	* Solutions to exercise 2.8.4.
*/

#include <bitset>
#include <functional>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>
#include "Functions.hpp"

int main()
{
	/* 2.8.4 */
	// a) Compare vector<bool> bit related functionality to bitset's and dynamic_bitset<>'s:
	std::vector<bool> vectorBitset(10, false), vectorBitset2(10, false);
	std::bitset<10> bitset1(343), bitset2(654);
	// Forced to use function to convert unsigned long longs to vector bitsets, since no constructor available:
	ConvertULLToVectorBitset(vectorBitset, 343);
	ConvertULLToVectorBitset(vectorBitset2, 654);
	
	std::cout << "Comparing vector bitsets vs bitsets: " << std::endl;
	std::cout << "For " << VectorBitsetToString(vectorBitset) << " and " << VectorBitsetToString(vectorBitset2) << std::endl;
	// Test AND:
	std::cout << "AND bitsets: " << (bitset1 & bitset2) << std::endl;
	std::cout << "AND vectors: " << VectorBitsetToString(AND(vectorBitset, vectorBitset2)) << std::endl;
	// Test OR:
	bitset1 = 343;
	bitset2 = 654;
	std::cout << "OR bitsets: " << (bitset1 | bitset2) << std::endl;
	std::cout << "OR vectors: " << VectorBitsetToString(OR(vectorBitset, vectorBitset2)) << std::endl;
	// Test XOR:
	bitset1 = 343;
	bitset2 = 654;
	std::cout << "XOR bitsets: " << (bitset1 ^ bitset2) << std::endl;
	std::cout << "XOR vectors: " << VectorBitsetToString(XOR(vectorBitset, vectorBitset2)) << std::endl;
	// b) Test the Intersection function:
	std::cout << "Intersection of vector bitsets " << VectorBitsetToString(vectorBitset) << " and " << VectorBitsetToString(vectorBitset2) << std::endl;
	std::cout << VectorBitsetToString(Intersection(vectorBitset, vectorBitset2)) << std::endl;
	// Note: results are as expected, but forced to define own functions to accomodate lack of built-in functionality.
	
	system("pause");

	return 0;
}
