/* Functions.hpp (exercises 1.4.1 and 1.4.2)
Description:
	* Functions that provide solutions to exercise 1.4.1 and 1.4.2.
Functions:
	*void print(const FunctionType<T>& f, T t): print the output of template function object f using value t.
	*double test(const double &i): print statement to stdout and return a copy of the passed value.
	*double freeFunction3(double, double, double): function of 3-arity. Return sum of passed values.
	*double freeFunction2(double, double): binary function. Return sum of passed values.
	*double freeFunction1(double): unary function. Return copy of passed value.
	*double freeFunction0(): nullary function. Return constant value.
Function Objects/Stored Lambdas:
	*FunctionObject: overloads operator() to return copy of passed double and print statement signifying has been called.
	*auto storedLambda: prints statement signifying has been called and returns copy of each passed double.
*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <functional>

template <typename T>
using FunctionType = std::function<T(const T& t)>;

// Problem 1: 
// a)
template <typename T>
void print(const FunctionType<T>& f, T t)
{
	std::cout << f(t) << '\n';
}
// b) Create free function, function object and stored lambda;
// Free function:
double test(const double &i)
{
	std::cout << "test called. ";
	return i;
}
// Function object:
class FunctionObject
{
public:
	double operator()(const double &i)
	{
		std::cout << "FunctionObject called. ";
		return i;
	}
};
// Lambda:
auto storedLambda = [](const double &i) ->double { std::cout << "storedLambda called. ";  return i; };

/* 1.4.2: */
// a) Define functions of arity 3, 2, 1 and 0 based on above function:
// freeFunction 3 is a 3-arity (ternary) function. 
double freeFunction3(double x, double y, double z)
{
	return x + y + z;
}
double freeFunction2(double x, double y) // Binary function (2-arity).
{
	return x + y;
}
double freeFunction1(double x)		// Unary function (1-arity)
{
	return x;
}
double freeFunction0()				// Nullary function (0-arity)
{
	return 3.0;
}

#endif
