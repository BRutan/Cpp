/* Main.cpp (exercise 4.1.4) TODO: fix row.
Description:
	*

*/

#include <array>
#include <bitset>
#include <functional>
#include "Functions.hpp"
#include "Matrix.hpp"
#include "Proposition.hpp"


int main()
{
	/* 4.1.4 */
	// a) Create instances of BitMap and BitMap2 and corresponding print functions:
	BitMap<10, 4> bm1(false), bm2(true);
	std::cout << "Bitmap 1: " << bm1 << std::endl;
	std::cout << "Bitmap 2: " << bm2 << std::endl;

	// b) Test the 
	BitMap<5, 5> bm3(true); 
	bm3(4, 3) = false;
	BitMap<5, 5> bm4(true); 
	bm4(4, 3) = true;
	auto COND = [](const Proposition& p1, const Proposition& p2) { return p1 % p2; }; 
	// auto bmA = mask(bm3, bm4, [](const value_type &A, const value_type &B) { return value_type(A ^ B); });

	// c) Test the initialise function:
	BitMap<4, 4> bm5;
	BitMap2<4, 4> bm6;

	initialise(bm6, 1, std::string("0010"));
	std::cout << "First row of bm6: { " << bm6[1, 0] << ", " << bm6[1, 1] << ", " << bm6[1, 2] << ", " << bm6[1, 3] << " }" << std::endl;

	system("pause");


	return 0;
}
