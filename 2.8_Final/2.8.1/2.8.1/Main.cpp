/* Main.cpp (exercise 2.8.1)
Description:
	* Solutions to exercise 2.8.1.
*/

#include <bitset>
#include <functional>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

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
	std::bitset<12> set5("01101010101011111111111", 12);
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

	system("pause");

	return 0;
}
