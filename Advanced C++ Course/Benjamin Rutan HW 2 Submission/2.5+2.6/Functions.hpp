/* Functions.hpp (exercise 2.5.2)
Description:
	* 

*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cmath>

template <typename T> 
const char* Classify(T t) 
{ 
	switch (std::fpclassify(t))
	{ 
	case FP_INFINITE: return "Inf"; 
	case FP_NAN: return "NaN"; 
	case FP_NORMAL: return "normal"; 
	case FP_SUBNORMAL: return "subnormal"; 
	case FP_ZERO: return "zero"; 
	default: return "unknown"; 
	} 
}

/* 2.5.2 */
// a) Create machine epsilon (effective 0) finding function:
template<typename T>
T FindEpsilon()
{
	T epsilon = static_cast<T>(1.0);

	while ((1.0 + epsilon / static_cast<T>(2)) != 1.0)
	{
		epsilon /= static_cast<T>(2);
	}
	return epsilon;
}

　
#endif
