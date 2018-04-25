/* Main.cpp (exercise 2.4.3)
Description:
	* Solutions to exercise 2.4.3.
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
	/* 2.4.3 */
	// a-b) Implement provided code using unique_ptr<>. Code gave run-time error originally due to
	// a run-time access violation since auto_ptr d has been deleted when ownership is transferred. 
	{
		std::unique_ptr<double> d(new double(1.0));
		// Dereference
		*d = 2.0;
		// Change ownership of unique_ptr
		// (after assignment, d is undefined)
		std::unique_ptr<double> d2(d.release());
		*d2 = 3.0;
		d.reset();
	}
	// std::cout << "Unique values: " << *d.get() << ", " << *d2.get();
	//////////// TODO: read unique ptr slides.

	system("pause");
	
	
	return 0;
}
