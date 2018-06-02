/* Main.cpp (exercise 4.1.2) IN PROGRESS
Description:
	*

*/

#include <functional>
#include <iostream>
#include "Vector.hpp"


int main()
{
	// a)
	Vector<int, 5> fiveVec(5);

	std::cout << "fiveVec: " << fiveVec << std::endl;
	// fiveVec[4] = 6;
	// int test = fiveVec[4];
	std::function<int(int)> f([](int i) ->int { if (i > 4) return i * 4; });
	fiveVec.modify(f);
	std::cout << "fiveVec: " << fiveVec << std::endl;

	system("pause");
	return 0;
}