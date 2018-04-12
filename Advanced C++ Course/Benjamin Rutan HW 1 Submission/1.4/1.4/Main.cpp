/* Main.cpp (exercise 1.4)
Description:
	* Solutions to exercise 1.4 problems 1-5.
*/
#include <iostream>
#include <vector>
#include "C.hpp"
#include "Functions.hpp"
#include "Shape_Classic.hpp"
#include "Shape_NextGen.hpp"

int main()
{
	/* 1.4.1: */
	// b) Assign the free function, function object and stored lambda to FunctionType<double> (std::function<double(const &double)>) objects 
	double i = 20;
	FunctionType<double> test_Wrapper = test;
	FunctionType<double> functionObject_Wrapper = FunctionObject(); // Note that function objects require () to assign to function wrapper.
	FunctionType<double> storedLambda_Wrapper = storedLambda;
	// Test code:
	print(test_Wrapper, i);
	print(functionObject_Wrapper, i);
	print(storedLambda_Wrapper, i);
	/* 1.4.2: */
	// b) Test above ternary, binary, unary and nullary functions by binding appropriate variables:
	auto ternary = std::bind(freeFunction3, 3.0, 4.0, 5.0);
	auto binary = std::bind(freeFunction2, 3.0, 4.0);
	auto unary = std::bind(freeFunction1, 3.0);
	auto nullary = std::bind(freeFunction0);
	std::cout << "ternary(3.0, 4.0, 5.0) output: " << ternary() << std::endl;
	std::cout << "binary(3.0, 4.0) output: " << binary() << std::endl;
	std::cout << "unary(3.0) output: " << unary() << std::endl;
	std::cout << "nullary() output: " << nullary() << std::endl;

	/* 1.4.3: */
	// a) Bind the function wrapper to class C's static member function:
	FunctionType<double> staticMemberFunc = C::Square;
	// b) Bind the function wrapper to C's member functions using std::bind and placeholders:
	// (note that we are required to pass a reference to the class member function and an instance of the class to bind in order to assign to a function wrapper)
	FunctionType<double> translate = std::bind(&C::translate, C(3.0), std::placeholders::_1);
	// Note that require std::placeholders_1 to assign to function wrapper with signature std::function<double(const &double)> (i.e. 
	FunctionType<double> translate2 = std::bind(&C::translate2, C(3.0), std::placeholders::_1, 4.0);
	// Test the function wrapper objects with print():
	print(staticMemberFunc, 4.0);		// returns 16. 
	print(translate, 4.0);				// returns 3.0 + 4.0.
	print(translate2, 4.0);				// returns 3.0 + 4.0 + 4.0.
	
	/* 1.4.4: */
	// Test the derived Classic::Shape classes with pvmf emulation:
	VoidFunctionType f1 = [](double d) { std::cout << " f1(" << d << ")" << std::endl;  };
	VoidFunctionType f2 = [](double d) { std::cout << " f2(" << d << ")" << std::endl;  };
	Classic::Circle c(f1), d(f2);
	c.rotate(4.0);
	d.rotate(12.0);
	/* 1.4.5: */
	// b) Test next-gen polymorphism using the NextGen::Shape class:
	auto square = [](double d) {return d * d; }; 
	auto expo = [](double d) {return std::exp(d); };
	NextGen::Shape<double, double> polyMorphicShape(square);
	std::cout << "Square: " << polyMorphicShape.Execute(4.0) << std::endl;
	polyMorphicShape.SetFunction(expo);
	std::cout << "Exponential: " << polyMorphicShape.Execute(12.0) << std::endl;

	system("pause");
	
	return 0;
}