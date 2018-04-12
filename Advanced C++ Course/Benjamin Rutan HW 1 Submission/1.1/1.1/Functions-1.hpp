/* Functions-1.hpp (exercise 1.1.2)
Description:
	*Declare Circle class that represents circle in 2-D Euclidean space.
Function Objects:
	*struct FOMultiple: function object that multiples each element in an STL container.
	* T MyMultiply(const T &x, const T &y): template function that multiplies each element in an STL container.
*/



#ifndef FUNCTIONS1_HPP
#define FUNCTIONS1_HPP

struct FOMultiply					/* Function object that multiplies each element in an STL container. */	
{
	template <typename T>
	T operator () (const T& x, const T& y)
	{
		return x * y;
	}
};

template <typename T>
T MyMultiply2(const T& x, const T& y) { return x * y; }

#endif
