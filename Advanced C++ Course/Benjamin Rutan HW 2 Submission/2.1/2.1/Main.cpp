/* Main.cpp (exercise 2.1.1)
Description:
	* Provides solutions to exercise 2.1.1-2.1.4.
*/

#include "Class.hpp"
#include "Functions.hpp"
#include "List.hpp"

int main()
{
	/* 2.1.1: */
	// a) Test the Is functions to determine if passed type is a pointer, non-pointer, lvalue reference or rvalue reference.
	std::nullptr_t nullPtr = nullptr;
	int *pointer = new int(4);
	int lvalue = 12;
	IsNullPointer(nullPtr); //
	IsPointer(pointer); //
	IsLValueReference(lvalue); //
	IsRValueReference(std::move(lvalue));
	// b) Test the IsMemberFunctionPointer and IsNonStaticMemberObject functions:
	List test;
	IsMemberFunctionPointer(&List::f);
	IsNonStaticMemberObject(&List::head);
	/* 2.1.2: */
	// Test the Print() bridger function:
	Print(pointer);
	Print(lvalue);
	/* 2.1.3: */
	// a) Determine which classes are empty, polymorphic and abstract:
	std::cout << "Class properties:" << std::endl;
	std::cout << "\t\tShape\t\t" << "Base\t\t" << "Point\t\t" << std::endl;
	std::cout << "Is Empty: "; 
	std::cout << "\t" << ((std::is_empty<Shape>::value) ? "1" : "0");
	std::cout << "\t\t" << ((std::is_empty<Base>::value) ? "1" : "0"); 
	std::cout << "\t\t" << ((std::is_empty<Point>::value) ? "1" : "0") << std::endl;
	std::cout << "Is Polymorphic: ";
	std::cout << "" << ((std::is_polymorphic<Shape>::value) ? "1" : "0");
	std::cout << "\t\t" << ((std::is_polymorphic<Base>::value) ? "1" : "0");
	std::cout << "\t\t" << ((std::is_polymorphic<Point>::value) ? "1" : "0") << std::endl;
	std::cout << "Is Abstract: ";
	std::cout << "\t" << ((std::is_abstract<Shape>::value) ? "1" : "0");
	std::cout << "\t\t" << ((std::is_abstract<Base>::value) ? "1" : "0");
	std::cout << "\t\t" << ((std::is_abstract<Point>::value) ? "1" : "0") << std::endl;

	// b) Determine which classes are the same:
	std::cout << "Shape is the same as Base: " << ((std::is_same<Shape, Base>::value) ? "True" : "False") << std::endl;
	std::cout << "Shape is the same as Point: " << ((std::is_same<Shape, Point>::value) ? "True" : "False") << std::endl;
	std::cout << "Base is the same as Point: " << ((std::is_same<Base, Point>::value) ? "True" : "False") << std::endl;
	// c) Determine which classes have gen/spec relationship:
	std::cout << "Shape is the base of Base: " << ((std::is_base_of<Shape, Base>::value) ? "True" : "False") << std::endl;
	std::cout << "Base is the base of Shape: " << ((std::is_base_of<Base, Shape>::value) ? "True" : "False") << std::endl;
	std::cout << "Shape is the base of Point: " << ((std::is_base_of<Shape, Point>::value) ? "True" : "False") << std::endl;
	std::cout << "Point is the base of Shape: " << ((std::is_base_of<Point, Shape>::value) ? "True" : "False") << std::endl;
	std::cout << "Base is the base of Point: " << ((std::is_base_of<Base, Point>::value) ? "True" : "False") << std::endl;
	std::cout << "Point is the base of Base: " << ((std::is_base_of<Point, Base>::value) ? "True" : "False") << std::endl;
	// d) Determine which classes can be converted into one another:
	std::cout << "Shape is convertible to Base: " << ((std::is_convertible<Shape, Base>::value) ? "True" : "False") << std::endl;
	std::cout << "Base is convertible to Shape: " << ((std::is_convertible<Base, Shape>::value) ? "True" : "False") << std::endl;
	std::cout << "Shape is convertible to Point: " << ((std::is_convertible<Shape, Point>::value) ? "True" : "False") << std::endl;
	std::cout << "Point is convertible to Shape: " << ((std::is_convertible<Point, Shape>::value) ? "True" : "False") << std::endl;
	std::cout << "Base is convertible to Point: " << ((std::is_convertible<Base, Point>::value) ? "True" : "False") << std::endl;
	std::cout << "Point is convertible to Base: " << ((std::is_convertible<Point, Base>::value) ? "True" : "False") << std::endl;
	/* 2.1.4 */
	// a) Determine if Point has a virtual destructor:
	std::cout << "Point has a virtual destructor: " << ((std::has_virtual_destructor<Point>::value) ? "True" : "False") << std::endl;
	// b) Determine if Point has a default, copy or move constructor:
	std::cout << "Point has a default constructor: " << ((std::is_default_constructible<Point>::value) ? "True" : "False") << std::endl;
	std::cout << "Point has a copy constructor: " << ((std::is_copy_constructible<Point>::value) ? "True" : "False") << std::endl;
	std::cout << "Point has a move constructor: " << ((std::is_move_constructible<Point>::value) ? "True" : "False") << std::endl;	
	// c) Determine if Point is copy or move assignable:
	std::cout << "Point is copy assignable: " << ((std::is_copy_assignable<Point>::value) ? "True" : "False") << std::endl;
	std::cout << "Point is move assignable: " << ((std::is_move_assignable<Point>::value) ? "True" : "False") << std::endl;
	// d) After putting copy/move assignment operators/constructors as deleted, the above checks return false.

	system("pause");

	return 0;
}
