/* Functions.hpp (exercise 2.1.1)
Description:
	* Functions handle type traits implementation for problems in exercise 2.1.1.
*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <type_traits>

// a) Write functions to determine if passed argument is a pointer, a null pointer, an lvalue reference and an rvalue reference.
template <typename T>
void IsPointer(const T& t)
{ // First example of type_traits;check if t is a pointer
  // Return type is std::true_type or std::false_type 
	if (std::is_pointer<T>::value)
	{
		std::cout << "This IS a pointer type argument\n";
	}
	else
	{
		std::cout << "This IS NOT a pointer type argument\n";
	}
}
template<typename T>
void IsNullPointer(const T& t)
{ // First example of type_traits;check if t is a pointer
  // Return type is std::true_type or std::false_type 
	if (std::is_null_pointer<T>::value)
	{
		std::cout << "This IS a null pointer\n";
	}
	else
	{
		std::cout << "This IS NOT a null pointer\n";
	}
}

template<typename T>
void IsLValueReference(T& t)
{
	if (std::is_lvalue_reference<T&>::value)
	{
		std::cout << "This IS an lvalue reference\n" << std::endl;
	}
	else
	{
		std::cout << "This IS NOT an lvalue reference\n" << std::endl;
	}
}

template<typename T>
void IsRValueReference(T&& t)
{
	if (std::is_rvalue_reference<T&&>::value)
	{
		std::cout << "This IS an rvalue reference\n" << std::endl;
	}
	else
	{
		std::cout << "This IS NOT an rvalue reference\n" << std::endl;
	}
}

// b) Write functions to determine if type is a member function pointer or a pointer to a non-static member object.
template<typename T>
void IsMemberFunctionPointer(T t)
{
	if (std::is_member_function_pointer<T>::value)
	{
		std::cout << "This IS a member function pointer\n" << std::endl;
	}
	else
	{
		std::cout << "This IS NOT a member function pointer\n" << std::endl;
	}
}

template<typename T>
void IsNonStaticMemberObject(T t)
{
	if (std::is_member_object_pointer<T>::value)
	{
		std::cout << "This IS a non-static member object\n" << std::endl;
	}
	else
	{
		std::cout << "This IS NOT a non-static member object\n" << std::endl;
	}
}

/* 2.1.2 */
// Create template function to support pointers and reference types, bridging functionality:

template<typename T>
void Print(T *value, std::true_type)
{
	// Dereference and print:
	std::cout << *value << std::endl;
}
template<typename T>
void Print(T &value, std::false_type)
{
	// Print directly:
	std::cout << value << std::endl;
}

template<typename T>
void Print(T value)
{
	Print(value, typename std::is_pointer<T>::type());
}

#endif
