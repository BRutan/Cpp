/* Main.cpp (exercise 3.2+3.3.1)
Description:
	* Solutions to problems a-f in exercise 3.2+3.3.1.
*/

#include <atomic>
#include <iostream>
#include <memory>
#include "X.hpp"

int main()
{
	/* 3.2+3.3.1 */
	// a) Create instance of X of class PointerType, give value:
	PointerType x(new X);
	x->val = 3.3;
	std::cout << "Pointer x use count: " << x.use_count() << std::endl;
	// b) Create second instance x2 and atomically store the value in x:
	PointerType x2(x);
	std::cout << "Pointer x use count: " << x.use_count() << std::endl;

	// c) Create instance x3 and exchange with both x and x2:
	PointerType x3(x);
	std::cout << "Pointer x use count: " << x.use_count() << std::endl;
	x3 = x2;
	std::cout << "Pointer x use count: " << x.use_count() << std::endl;

	// e) atomic<shared_ptr> is not possible because shared_ptr class is not trivially copyable.
	std::cout << "shared_ptr is trivially copyable: " << std::is_trivially_copyable<PointerType>::value << std::endl;
	// f) Shared pointers can be implemented with mutex objects, implying that they need not be lock-free. On their own, however, they are. 

	system("pause");

	return 0;
}