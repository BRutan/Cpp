/*



*/



#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cmath>
#include <functional>

template<typename R, typename D>
	using FunctionType = std::function<R(const D x)>;

using ScalarFunction = FunctionType<double, double>;

template<typename R, typename D>
FunctionType<R, D> operator+(const FunctionType<R, D> &f, const FunctionType<R, D> &g)
{
	// Addition of functions:
	return [=](const D& x)
	{
		return f(x) + g(x);
	};
}

template<typename R, typename D>
FunctionType<R, D> operator*(const FunctionType<R, D> &f, const FunctionType<R, D> &g)
{
	// Multiplication of functions:
	return [=](const D& x)
	{
		return f(x) * g(x);
	};
}

template<typename R, typename D>
FunctionType<R, D> operator-(const FunctionType<R, D> &f, const FunctionType<R, D> &g)
{
	// Subtraction of functions:
	return [=](const D& x)
	{
		return f(x) - g(x);
	};
}
template<typename R, typename D>
FunctionType<R, D> operator-(const FunctionType<R, D> &g)
{
	// Additive inverse:
	return [=](const D& x)
	{
		return -g(x);
	};
}
template<typename R, typename D>
FunctionType<R, D> operator*(const R &scalar, const FunctionType<R, D> &g)
{
	// Scalar multiplication:
	return [=](const D& x)
	{
		return g(x) * scalar;
	};
}
template<typename R, typename D>
FunctionType<R, D> operator/(const FunctionType<R,D> &f, const FunctionType<R, D> &g)
{
	// Division:
	return [=](const D& x)
	{
		return f(x) / g(x);
	};
}
template<typename R, typename D>
FunctionType<R, D> operator<<(const FunctionType<R, D> &f, const FunctionType<R, D> &g)
{
	// Composition:
	return [=](const D& x)
	{
		return f(g(x));
	};
}

template<typename R, typename D>
FunctionType<R, D> exp(const FunctionType<R, D> &f)
{
	// The exponential function:
	return [=](const D& x)
	{
		return std::exp(f(x));
	};
}
template<typename R, typename D>
FunctionType<R, D> cos(const FunctionType<R, D> &f)
{
	// The cosine  function:
	return [=](const D& x)
	{
		return std::cos(f(x));
	};
}
template<typename R, typename D>
FunctionType<R, D> sin(const FunctionType<R, D> &f)
{
	// The sine function:
	return [=](const D& x)
	{
		return std::sin(f(x));
	};
}
template<typename R, typename D>
FunctionType<R, D> tan(const FunctionType<R, D> &f)
{
	// The tan function:
	return [=](const D& x)
	{
		return std::tan(f(x));
	};
}
template<typename R, typename D>
FunctionType<R, D> log(const FunctionType<R, D> &f)
{
	// The natural logarithm function:
	return [=](const D& x)
	{
		return std::log(f(x));
	};
}
template<typename R, typename D>
FunctionType<R, D> abs(const FunctionType<R, D> &f)
{
	// The absolute value function:
	return [=](const D& x)
	{
		return std::abs(f(x));
	};
}
template<typename R, typename D>
FunctionType<R, D> sqrt(const FunctionType<R, D> &f)
{
	// The square root function:
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
#endif
