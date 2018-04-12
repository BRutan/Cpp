/* Calculator.hpp (exercise 1.5.2)
-Description: 
 * Header file for Calculator<T, Tuple, N> template class that is only meant to house static calculating functions (maximium(), sum() and average()).
   T is the data type stored in the passed numeric tuple. N is the number of entries in the tuple.
-Class Methods:
// Constructors/Destructor (all deleted to prevent Calculator class from being initialized).
	* Calculator(): deleted default constructor
	* Calculator(const Calculator&): deleted copy constructor.
	* ~Calculator(): deleted destructor.
// Misc. Methods:
	* T maximum(const Tuple&): return the largest entry in the tuple.
	* T sum(const Tuple&): return the sum of all the entries in the tuple.
	* T average(const Tuple&): return the uniformly weighted average of all the entries in the tuple.
*/

#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>

// a) Create a template Calculator struct that implements static functions to perform calculations (min, max, avg) on a tuple:
template <typename T, typename Tuple, std::size_t N>
struct Calculator
{
public:
	//////////////////////////
	// Constructors/Destructor:
	//////////////////////////
	Calculator() = delete;
	Calculator(const Calculator&) = delete;
	~Calculator() = delete;
	//////////////////////////
	// Misc. Methods:
	//////////////////////////
	static T maximum(const Tuple &tuple_in) noexcept
	{
		return std::max(std::get<N - 1>(tuple_in), Calculator<T, Tuple, N - 1>::maximum(tuple_in));
	}
	static T average(const Tuple &tuple_in) noexcept
	{
		return Calculator<T, Tuple, N>::sum(tuple_in) / (T) N;
	}
	static T sum(const Tuple &tuple_in) noexcept
	{
		return std::get<N - 1>(tuple_in) + Calculator<T, Tuple, N - 1>::sum(tuple_in);
	}
	//////////////////////////
	// Overloaded Operators:
	//////////////////////////
	void operator=(const Calculator&) = delete;
};
// Partially specialized Calculator with size_T N = 0 to serve as base case to implement recursion above:
template<typename T, typename Tuple>
struct Calculator<T, Tuple, 1>
{
public:
	//////////////////////////
	// Misc. Methods:
	//////////////////////////
	static T maximum(const Tuple &tuple_in) noexcept
	{
		return std::get<0>(tuple_in);
	}
	static T sum(const Tuple &tuple_in) noexcept
	{
		return std::get<0>(tuple_in);
	}
};

#endif