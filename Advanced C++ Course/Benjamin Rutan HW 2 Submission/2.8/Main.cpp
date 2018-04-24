/* Main.cpp (exercise 2.8)
Description:
	* Solutions to exercise 2.8 problems 1-5.

　
　
*/

#include <bitset>
#include <boost\dynamic_bitset\dynamic_bitset.hpp>
#include <functional>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>
#include "BitMatrix.hpp"
#include "Functions.hpp"

int main()
{
	/* 2.8.1 */
	// a) Create bitsets from unsigned long and unsigned long long:
	unsigned long long ull = std::numeric_limits<unsigned long long>::max(); // 8 bytes
	unsigned long ul = std::numeric_limits<unsigned long>::max();		  // 4 bytes

	std::bitset<sizeof(ull)> set1(ull);
	std::bitset<sizeof(ul)> set2(ul);
	std::cout << "ULL maximum in binary: " << set1 << std::endl;
	std::cout << "UL maximum in binary: " << set2 << std::endl;
	// b) Create bitsets from full strings:
	std::bitset<sizeof(ull)> set3("01100010101");
	std::bitset<sizeof(ul)> set4("111111101");
	std::bitset<12> set5("0110101010101", 5, 0, 5);
	std::bitset<12> set6(435);
	// Print results:
	std::cout << "Bitsets generated from strings: " << std::endl;
	std::cout << set3 << std::endl;
	std::cout << set4 << std::endl;
	std::cout << set5 << std::endl;
	// c) Use exception handling to check for out-of-range values and invalid arguments:
	std::cout << "Testing bitset exceptions: " << std::endl;
	// Test out of range exception:
	try
	{
		std::bitset<5> set7("1111111111111111");
		// Note: below causes fatal run-time error, therefore cannot customize exception handling for out_of_range:
		//set6[12]; 
	}
	catch (std::out_of_range &err)
	{
		std::cout << "Out of range exception caught: " << std::endl;
		std::cout << err.what() << std::endl;
	}
	// Test invalid argument exception:
	try
	{
		std::bitset<12> set8("222111");
	}
	catch (std::invalid_argument &err)
	{
		std::cout << "Invalid bitset argument caught: " << std::endl;
		std::cout << err.what() << std::endl;
	}
	// d) Set bits in bitset in different ways:
	// Test reset():
	std::cout << "For " << set5 << std::endl;
	std::cout << "reset(): " << set5.reset() << std::endl;
	// Test flip():
	std::cout << "flip(): " << set5.flip() << std::endl;
	// Test none():
	std::cout << "none(): " << set5.none() << std::endl;
	// Test any():
	std::cout << "any(): " << set5.any() << std::endl;
	// Test operator[]:
	std::cout << "bit at index 3: " << set5[3] << std::endl;
	// Count number of set bits:
	std::cout << "number of bits in set: " << set5.size() << std::endl;
	// e) Convert bitset to a string, unsigned long and unsigned long long:
	std::cout << "as a string: " << set5.to_string() << std::endl;
	std::cout << "as unsigned long: " << set5.to_ulong() << std::endl;
	std::cout << "as unsigned long long: " << set5.to_ullong() << std::endl;
	// f) Test bitset equality:
	std::cout << set5 << " == " << set6 << ": " << (set5 == set6) << std::endl;
	// Note that bitsets must be same size for boolean comparison operators to work.

	/* 2.8.2 */
	// a) Create two same sized bitsets: 
	std::bitset<10> bs1, bs2;
	// b) Toggle all bits of bs1 and bs2:
	bs1.flip(); bs2.flip();
	// c) Test bitwise XOR, OR, AND:
	std::cout << "Testing XOR, OR and AND: " << std::endl;
	std::cout << bs1 << std::endl;
	std::cout << bs2 << std::endl;

	std::cout << "XOR: " << (bs1 ^ bs2) << std::endl;;
	std::cout << "OR: " << (bs1 | bs2) << std::endl;;
	std::cout << "AND: " << (bs1 & bs2) << std::endl;
	// d) Perform right and left shift operations:
	bs1 << 1;
	bs2 >> 2;
	std::cout << "Single left shifting on bs1: " << bs1 << std::endl;
	std::cout << "Two right shifting on bs2: " << bs2 << std::endl;
	////// TODO: fix:

	// e) Use std::hash to created hashed values for bs1 and bs2:
	std::hash<std::bitset<10>> hash_func;
	std::cout << "Hash of " << bs1 << ": " << hash_func(bs1) << std::endl;
	std::cout << "Hash of " << bs2 << ": " << hash_func(bs2) << std::endl;

	/* 2.8.3 */
	// a) Port questions 1 and 2 to use boost::dynamic_bitset<T>:
	// Note that cannot convert an unsigned long long into a bitset (maximum size is unsigned long):
	// boost::dynamic_bitset<> boost_set1 { sizeof(ull), ull };
	boost::dynamic_bitset<> boost_set2{ sizeof(ul), ul };

	std::cout << "Testing boost::dynamic_bitset<bool>: " << std::endl;
	// std::cout << "ULL maximum in binary: " << boost_set1 << std::endl;
	std::cout << "UL maximum in binary: " << boost_set2 << std::endl;
	// b) Create boost::dynamic_bitsets from full strings:
	boost::dynamic_bitset<> boost_set3{ std::string("01100010101") };
	boost::dynamic_bitset<> boost_set4{ std::string("111111101") };
	// Create dynamic bitset by passing string and specifying starting index:
	boost::dynamic_bitset<> boost_set5{ std::string("0110101010101"), 1 };
	// Create dynamic bitset from passed integral literal:
	boost::dynamic_bitset<> boost_set6{ 435 };
	// Print results:
	std::cout << "Boost Bitsets generated from strings: " << std::endl;
	std::cout << boost_set3 << std::endl;
	std::cout << boost_set4 << std::endl;
	std::cout << boost_set5 << std::endl;
	// c) Use exception handling to check for out-of-range values and invalid arguments:
	std::cout << "Testing boost::dynamic_bitset exceptions: " << std::endl;
	// Test out of range exception:
	try
	{
		boost::dynamic_bitset<> boost_set7{ 12, 300 };
		// Note: below causes fatal run-time error, therefore cannot customize exception handling for out_of_range:
		//boost_set7[2000];
	}
	catch (std::out_of_range &err)
	{
		std::cout << "Out of range exception caught: " << std::endl;
		std::cout << err.what() << std::endl;
	}
	// Test invalid argument exception:
	try
	{
		std::bitset<12> set8("222111");
	}
	catch (std::invalid_argument &err)
	{
		std::cout << "Invalid bitset argument caught: " << std::endl;
		std::cout << err.what() << std::endl;
	}
	// d) Set bits in bitset in different ways:
	// Test reset():
	std::cout << "For " << boost_set5 << std::endl;
	std::cout << "reset(): " << boost_set5.reset() << std::endl;
	// Test flip():
	std::cout << "flip(): " << boost_set5.flip() << std::endl;
	// Test none():
	std::cout << "none(): " << boost_set5.none() << std::endl;
	// Test any():
	std::cout << "any(): " << boost_set5.any() << std::endl;
	// Test operator[]:
	std::cout << "bit at index 3: " << boost_set5[3] << std::endl;
	// Count number of set bits:
	std::cout << "number of bits in set: " << boost_set5.size() << std::endl;
	// e) Convert bitset to a string, unsigned long and unsigned long long:
	// Note that to_string() and to_ullong() not supported by dynamic bitset.
	std::cout << "as unsigned long: " << boost_set5.to_ulong() << std::endl;
	// f) Test boost::dynamic_bitset equality:
	std::cout << boost_set5 << " == " << boost_set6 << ": " << (boost_set5 == boost_set6) << std::endl;
	// Note that bitsets must be same size for boolean comparison operators to work.

	/* 2.8.2 (Boost Version) */
	// Note: dynamic_bitset<> prints all bits, while bitset prints only up until the most significant bit.
	// a) Create two same sized bitsets: 
	boost::dynamic_bitset<>  boost_bs1, boost_bs2;
	// b) Toggle all bits of bs1 and bs2:
	boost_bs1.flip(); boost_bs2.flip();
	// c) Test bitwise XOR, OR, AND:
	std::cout << "Testing XOR, OR and AND: " << std::endl;
	std::cout << boost_bs2 << std::endl;
	std::cout << boost_bs2 << std::endl;

	std::cout << "XOR: " << (boost_bs1 ^ boost_bs2) << std::endl;;
	std::cout << "OR: " << (boost_bs1 | boost_bs2) << std::endl;;
	std::cout << "AND: " << (boost_bs1 & boost_bs2) << std::endl;
	// d) Perform right and left shift operations:
	boost_bs1 << 1;
	boost_bs2 >> 2;
	std::cout << "Single left shifting on bs1: " << bs1 << std::endl;
	std::cout << "Two right shifting on bs2: " << bs2 << std::endl;

	// e) Use std::hash to created hashed values for boost_bs1 and boost_bs2:
	/*std::hash<boost::dynamic_bitset<>> boost_hash_func;
	std::cout << "Hash of " << boost_bs1 << ": " << boost_hash_func(bs1) << std::endl;
	std::cout << "Hash of " << boost_bs2 << ": " << boost_hash_func(bs2) << std::endl;

	/* 2.8.3 continued: */
	// b) Test dynamic functionality of boost::dynamic_bitset:
	boost::dynamic_bitset<> dynamic{ 12, 2323 };

	// Test resize():
	std::cout << "For " << dynamic << std::endl;
	dynamic.resize(13, true); // Prepends a 1 to front if true, 0 if false.
	std::cout << "resize(13, true): " << dynamic << std::endl;
	// Test clear():
	dynamic.clear();
	std::cout << "clear(): " << dynamic << std::endl;
	// Test push_back():
	dynamic.push_back(true);
	std::cout << "push_back(true): " << dynamic << std::endl;
	// Test pop_back():
	dynamic.pop_back();
	std::cout << "pop_back(): " << dynamic << std::endl;
	// Test append():
	dynamic.append(1); // Appends an unsigned long's worth of bits (32). 
	std::cout << "append(1): " << dynamic << std::endl;
	// c) Test if bitset is subset/proper subset of another bitset (note that is_subset_of() requires that passed dynamic_bitset<> have same number of bits loaded, or else run-time exception thrown):
	boost::dynamic_bitset<> dynamic2{ 32, 1 };
	std::cout << dynamic2 << " is a subset of " << dynamic << ": " << dynamic2.is_subset_of(dynamic) << std::endl;
	std::cout << dynamic2 << " is a proper subset of " << dynamic << ": " << dynamic2.is_proper_subset_of(dynamic) << std::endl;
	// d) Test find_first() and find_next():
	boost::dynamic_bitset<> dynamic3{ 12, 2002 };
	std::cout << "For " << dynamic3 << std::endl;
	std::cout << "find_first(): " << dynamic3.find_first() << std::endl;
	std::cout << "find_next(): " << dynamic3.find_next(1) << std::endl;

	/* 2.8.4 */
	// a) Compare vector<bool> bit related functionality to bitset's and dynamic_bitset<>'s:
	std::vector<bool> vectorBitset(8, false), vectorBitset2(8, false);
	std::bitset<8> bitset1(343), bitset2(654);
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
