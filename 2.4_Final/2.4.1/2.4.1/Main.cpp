/* Main.cpp (exercise 2.4.1)
Description:
	* Solutions to exercise 2.4.1.
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
	/* 2.4.1 */
	// b) Replace provided code with code that uses smart pointer classes:
	try
	{ // Block with raw pointer lifecycle
		std::unique_ptr<double> d(new double(1.0));
		std::unique_ptr<Point> pt(new Point(1.0, 2.0)); // Two-d Point class
		throw 1;
		// Dereference and call member functions 
		*d = 2.0; (*pt).X(3.0);		// Modify x coordinate 
		(*pt).Y(3.0);				// Modify y coordinate 
		// Can use operators for pointer operations 
		pt->X(3.0); // Modify x coordinate 
		pt->Y(3.0); // Modify y coordinate
		// Pointers will now be implicitly deleted once removed from scope.
	}
	catch (...)
	{
		std::cout << "Exception caught." << std::endl;
	}
	// c) Experiment with unique_ptr class:
	// double *p = new double(3.0);
	// Ptr<double> up_1(p), up_2(p), up_3;
	// Initializing two different unique_ptrs to same pointer will trigger a breakpoint in code.
	// Assign a unique ptr to another unique ptr:
	// up_3 = up_2;
	// Transfer ownership:
	// up_3 = std::move(up_1);

	system("pause");
	
	return 0;
}
