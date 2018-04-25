/* Main.cpp (exercise 2.8.2)
Description:
	* Solutions to exercise 2.8.2.
*/

#include <bitset>
#include <boost\dynamic_bitset\dynamic_bitset.hpp>
#include <functional>
#include <iostream>
#include <stdexcept>

int main()
{
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
	bs1.reset();
	bs1.flip(1);
	bs2.reset();
	bs2.flip(6);
	std::cout << "Setting bs1 to " << bs1 << std::endl;
	std::cout << "Setting bs2 to " << bs2 << std::endl;
	bs1 <<= 1;
	bs2 >>= 2;
	std::cout << "Single left shifting on bs1: " << bs1 << std::endl;
	std::cout << "Two right shifting on bs2: " << bs2 << std::endl;

	// e) Use std::hash to created hashed values for bs1 and bs2:
	std::hash<std::bitset<10>> hash_func;
	std::cout << "Hash of " << bs1 << ": " << hash_func(bs1) << std::endl;
	std::cout << "Hash of " << bs2 << ": " << hash_func(bs2) << std::endl;

	system("pause");

	return 0;
}
