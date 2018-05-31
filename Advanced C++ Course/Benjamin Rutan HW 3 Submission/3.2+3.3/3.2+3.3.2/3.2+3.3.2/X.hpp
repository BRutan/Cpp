/* X.hpp (exercise 3.2+3.3.2)
Description:
	* Class to test with shared_ptr objects in 3.2+3.2.2.
*/

#ifndef X_HPP
#define X_HPP

#include <iostream>
#include <memory>

struct X 
{
	double val;
	X() : val(0.0) 
	{

	} 
	void operator ()() 
	{ 
		std::cout << "An X " << val << std::endl; 
	}
};

// C++11 
template <typename T> 
	using GenericPointerType = std::shared_ptr<T>; 
using PointerType = GenericPointerType<X>;

#endif
