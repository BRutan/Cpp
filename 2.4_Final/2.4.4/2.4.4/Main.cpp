/* Main.cpp (exercise 2.4.4)
Description:
	* Solutions to exercise 2.4.4.
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
	/* 2.4.4 */
	//a) Create list of smart pointers to Base:
	// Cannot create list of unique_ptrs list class is doubly-linked, implying that a pointer needs to be shared between adjacent nodes, 
	// violating the uniqueness ot the unique_ptr.
	{
		std::list<std::shared_ptr<Base>> sharedPtrBaseList;
		// b) Implement factory function to create instances of Derived and then add them to list:
		for (std::size_t i = 0; i < 30; i++)
		{
			sharedPtrBaseList.push_back(DerivedFactory());
		}
	}
	// No memory leaks detected:
	_CrtDumpMemoryLeaks();

	system("pause");
	
	
	return 0;
}
