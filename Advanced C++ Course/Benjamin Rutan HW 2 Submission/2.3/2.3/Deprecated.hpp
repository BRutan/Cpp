/* Deprecated.hpp (exercise 2.3.1)
Description:
	* Declare and define deprecated enums, classes, variables and global functions.
*/

#ifndef DEPRECATED_HPP
#define DEPRECATED_HPP

#include <iostream>
// a) Define a deprecated free function:

[[deprecated("old stuff")]] void func()
{
	std::cout << "Deprecated function call" << std::endl;
}
// b) Define a deprecated class:
class [[deprecated("old stuff")]] Depr
{
public:
	/////////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////////
	Depr()
	{

	}
	virtual ~Depr()
	{

	}
	/////////////////////////////////
	// Misc Functions:
	/////////////////////////////////
	void f()
	{
		std::cout << "Deprecated class function call." << std::endl;
	}
};

// Define a class with a deprecated function:
template<typename T>
class NotDepr
{
public:
	/////////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////////
	NotDepr()
	{

	}
	virtual ~NotDepr()
	{

	}
	/////////////////////////////////
	// Misc Functions:
	/////////////////////////////////
	[[deprecated("old stuff")]] void f()
	{
		std::cout << "Deprecated class function call." << std::endl;
	}
};

// c) Implement a deprecated global variable:
[[deprecated("old stuff")]] const unsigned num = 0;

// d) Implement a deprecated enum and enum class:

enum class[[deprecated("old stuff")]] Color { Red, Green, Blue };
enum [[deprecated("old stuff")]] Numbers { One, Two, Three };

// e) Define a deprecated template class specialization:
template<>
[[deprecated("old stuff")]] class NotDepr<int>
{
public:
	/////////////////////////////////
	// Constructors/Destructor:
	/////////////////////////////////
	NotDepr()
	{

	}
	virtual ~NotDepr()
	{

	}
	/////////////////////////////////
	// Misc Functions:
	/////////////////////////////////
	[[deprecated("old stuff")]] void f()
	{
		std::cout << "Deprecated class function call." << std::endl;
	}
};

// f) Define a deprecated lambda function:
[[deprecated("old stuff")]] auto f = [](auto elem) { std::cout << elem << std::endl; };



#endif
