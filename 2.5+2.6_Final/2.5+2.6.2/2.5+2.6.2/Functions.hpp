/* Functions.hpp (Problem 1 & 2)
Description:
	* Functions to provide solutions to problems 1 and 2.
*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cmath>

/* Problem 1 */
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

/* Problem 2 */
// a) Create machine epsilon finding function:
template<typename T>
T FindEpsilon()
{
	T epsilon = static_cast<T>(1.0);
	
	while (static_cast<T>(1.0) + epsilon * .5f != static_cast<T>(1.0))
	{
		epsilon *= static_cast<T>(.5);
	}
	return epsilon;
}


#endif
