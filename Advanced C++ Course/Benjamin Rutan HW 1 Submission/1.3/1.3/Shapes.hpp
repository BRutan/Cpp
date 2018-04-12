/* Shapes.hpp (exercise 1.3.2)
Description:
	* Define base Shape class and derived Circle, Line classes to test variadic 
Classes:
	* Shape: base class for Circle and Line.
	// Misc Functions:
	-void rotate(double d): PVMF to be overwritten in Circle and Line.
	* Circle: derived class from Shape base class.
	// Misc Functions:
	-void rotate(double d): print "c" to signify that Circle's rotate has been called.
	* Line: derived class from Shape base.
	// Misc Functions:
	-void rotate(Double d): print "l" to signify Line's rotate has been called
Global Functions: Variadic rotate template functions to repeatedly call multiple passed Shape's rotate function.
	*void rotate(double factor, T &arg, Types...&Arg): top-level variadic to call all passed Shape's rotate function.
	*void rotate(double factor, T &arg): "tail" function to call final element in variadic function.
*/

#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <iostream>

class Shape 
{ 
public: 
	virtual void rotate(double d) = 0; 
};
class Circle : public Shape 
{ 
public: 
	void rotate(double d) override 
	{ 
		std::cout << "c\n"; 
	} 
};
class Line : public Shape 
{ 
public:
	void rotate(double d) override 
	{ 
		std::cout << "l\n"; 
	} 
};

class Valve 
{ 
public: 
	void rotate(double d) 
	{ 
		std::cout << "v\n"; 
	} 
};

// a) Create free function to handle polymorphic behavior of varying number of specialized Shape classes:
template<typename T, typename... Types>
	void rotate(double factor, T &arg, Types&... args)
	{
		arg.rotate(factor);
		rotate(factor, args...);
	}
template<typename T>
	void rotate(double factor, T &arg)
	{
		arg.rotate(factor);
	}

#endif