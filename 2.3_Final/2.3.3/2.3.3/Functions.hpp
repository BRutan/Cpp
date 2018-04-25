/* Functions.hpp (exercise 2.3.3-2.3.4)
Description:
	* Aliases, global overloaded operators and functions to handle function template operations.
*/



#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cmath>
#include <functional>

/* 2.3.3 */
template<typename R, typename D>
	using FunctionType = std::function<R(const D x)>;

using ScalarFunction = FunctionType<double, double>;

// a) Overload operators to add, multiply and subtract two functions. Create unary additive inverse of a function and function
// handling scalar multiplication.
// Addition of functions:
template<typename R, typename D>
FunctionType<R, D> operator+(const FunctionType<R, D> &f, const FunctionType<R, D> &g)
{
	
	return [=](const D& x)
	{
		return f(x) + g(x);
	};
}
// Multiplication of functions:
template<typename R, typename D>
FunctionType<R, D> operator*(const FunctionType<R, D> &f, const FunctionType<R, D> &g)
{
	return [=](const D& x)
	{
		return f(x) * g(x);
	};
}

// Function subtraction:
template<typename R, typename D>
FunctionType<R, D> operator-(const FunctionType<R, D> &f, const FunctionType<R, D> &g)
{
	return [=](const D& x)
	{
		return f(x) - g(x);
	};
}

// Additive inverse:
template<typename R, typename D>
FunctionType<R, D> operator-(const FunctionType<R, D> &g)
{
	return [=](const D& x)
	{
		return -g(x);
	};
}

// Scalar multiplication:
template<typename R, typename D>
FunctionType<R, D> operator*(const R &scalar, const FunctionType<R, D> &g)
{
	return [=](const D& x)
	{
		return g(x) * scalar;
	};
}

// Scalar multiplication (version 2):
template<typename T, typename R, typename D>
FunctionType<R, D> operator*(const T &scalar, const FunctionType<R, D> &g)
{
	return [=](const D& x)
	{
		return g(x) * scalar;
	};
}

// Division:
template<typename R, typename D>
FunctionType<R, D> operator/(const FunctionType<R,D> &f, const FunctionType<R, D> &g)
{
	return [=](const D& x)
	{
		return f(x) / g(x);
	};
}

// Composition:
template<typename R, typename D>
FunctionType<R, D> operator<<(const FunctionType<R, D> &f, const FunctionType<R, D> &g)
{
	return [=](const D& x)
	{
		return f(g(x));
	};
}

// b) Define trigonometric and various cmath functions:
// The exponential function:
template<typename R, typename D>
FunctionType<R, D> exp(const FunctionType<R, D> &f)
{
	return [=](const D& x)
	{
		return std::exp(f(x));
	};
}

// The cosine function:
template<typename R, typename D>
FunctionType<R, D> cos(const FunctionType<R, D> &f)
{
	return [=](const D& x)
	{
		return std::cos(f(x));
	};
}

// The sine function:
template<typename R, typename D>
FunctionType<R, D> sin(const FunctionType<R, D> &f)
{
	return [=](const D& x)
	{
		return std::sin(f(x));
	};
}

// The tan function:
template<typename R, typename D>
FunctionType<R, D> tan(const FunctionType<R, D> &f)
{
	return [=](const D& x)
	{
		return std::tan(f(x));
	};
}

// The natural logarithm function:
template<typename R, typename D>
FunctionType<R, D> log(const FunctionType<R, D> &f)
{
	return [=](const D& x)
	{
		return std::log(f(x));
	};
}

// The absolute value function:
template<typename R, typename D>
FunctionType<R, D> abs(const FunctionType<R, D> &f)
{
	return [=](const D& x)
	{
		return std::abs(f(x));
	};
}

// The square root function:
template<typename R, typename D>
FunctionType<R, D> sqrt(const FunctionType<R, D> &f)
{
	return [=](const D& x)
	{
		return std::sqrt(f(x));
	};
}

// c) Produce code for min, max high level functions:
template<typename R, typename D>
FunctionType<R, D> min(const FunctionType<R, D> &f, const FunctionType<R, D> &g)
{
	// The min function:
	return [=](const D& x)
	{
		return std::min(f(x), g(x));
	};
}
template<typename R, typename D>
FunctionType<R, D> max(const FunctionType<R, D> &f, const FunctionType<R, D> &g)
{
	// The max function:
	return [=](const D& x)
	{
		return std::max(f(x), g(x));
	};
}

/* 2.3.4 */
template <typename T> 
std::function<T(const T&)> bind1st(const std::function<T(const T& x, const T& y)>& f, const T& x_) 
{ 
	return [=](const T& y_in) 
	{
		return f(y_in, x_);
	};
}

template <typename T> 
std::function<T(const T&)> bind2nd(const std::function<T(const T& x, const T& y)>& f, const T& y_) 
{ 
	return [=](const T& x_in) 
	{
		return f(y_, x_in);
	};
}

#endif
