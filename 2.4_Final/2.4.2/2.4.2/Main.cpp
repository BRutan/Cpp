/* Main.cpp (exercise 2.4.2)
Description:
	* Solutions to exercise 2.4.2.
*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC 
#include <iostream>
#include <list>
#include <memory>
#include "Base.hpp"
#include "Classes.hpp"
#include "Functions.hpp"
#include "Point.hpp"

template<typename T>
using Ptr = std::unique_ptr<T>;

int main()
{
	/* 2.4.2 */
	// a, b, c) Test the C1 and C2 classes that both use the same shared_ptr as a member:
	Point *test = new Point();
	{
		std::shared_ptr<Point> input(test);
		C1 class1(input);
		C2 class2(input);
		class1.print(); std::cout << std::endl;
		class2.print(); std::cout << std::endl;
		std::cout << "Number of entities using input shared ptr (in scope): " << input.use_count() << std::endl;
	}
	// d) Test shared ptr:
	{
		double *test2 = new double(5);
		std::shared_ptr<double> sp1(test2), sp2;
		// Transfer ownership:
		sp2 = std::move(sp1);
		std::cout << "Transferred pointer ownership from sp1 to sp2." << std::endl;
		// Determine if shared pointer is only owner:
		std::cout << "sp2 is unique: " << sp2.unique() << std::endl;
		sp2.swap(sp1);
		std::cout << "Swapped pointer from sp2 to sp1." << std::endl;
		std::cout << "sp2 was previous owner: " << sp1.owner_before(sp2) << std::endl;
		// Give up ownership:
	}

	system("pause");
	
	
	return 0;
}
