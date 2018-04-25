/* Main.cpp (exercise 2.4.6)
Description:
	* Solutions to exercise 2.4.6.
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
	/* 2.4.6 */
	// a) Create shared_ptr and weak_ptr, print use counts:
	std::shared_ptr<double> sp4(new double(4.0));
	std::cout << "shared_ptr use count: " << sp4.use_count() << std::endl;
	std::weak_ptr<double> wp1 = sp4;
	std::cout << "shared_ptr use count following sharing: " << sp4.use_count() << std::endl;
	// Note that use_count remains same.
	// b) Determine if weak pointer is empty:
	std::cout << "weak pointer is empty: " << ((!wp1.expired())? "False" : "True") << std::endl;
	 // c) Assign a weak pointer to another weak pointer, then to a shared_ptr. Determine use_count:
	std::weak_ptr<double> wp2(wp1);
	std::cout << "use count following additional weak pointer assignment: " << wp2.use_count() << std::endl;
	wp2 = sp4;
	std::cout << "use count following shared_pointer assignment: " << wp2.use_count() << std::endl;
	// Note: use count remains unchanged.

	system("pause");
	
	
	return 0;
}
