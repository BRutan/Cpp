/* Main.cpp (exercise 2.8.3)
Description:
	* Solutions to exercise 2.8.3.
*/

#include <bitset>
#include <boost\dynamic_bitset\dynamic_bitset.hpp>
#include <functional>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

int main()
{
	/* 2.8.3 */
	// a) Port questions 1 and 2 to use boost::dynamic_bitset<T>:
	// Note that cannot convert an unsigned long long into a bitset (maximum size is unsigned long):
	// boost::dynamic_bitset<> boost_set1 { sizeof(ull), ull };
	unsigned long ul = 232;
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
	boost::dynamic_bitset<>  boost_bs1(10,0), boost_bs2(10, 0);
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
	boost_bs1.reset();
	boost_bs1.flip(1);
	boost_bs2.reset();
	boost_bs2.flip(8);
	std::cout << "For bs1 " << boost_bs1 << " and bs2 " << boost_bs2 << ": " << std::endl;
	boost_bs1 <<= 1;
	boost_bs2 >>= 2;
	std::cout << "Single left shifting on bs1: " << boost_bs1 << std::endl;
	std::cout << "Two right shifting on bs2: " << boost_bs2 << std::endl;

	// e) Use std::hash to created hashed values for boost_bs1 and boost_bs2:
	// Note: std::hash<> does not support dynamic_bitset<>:
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

	system("pause");

	return 0;
}
