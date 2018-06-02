/* Functions.hpp (exercise 4.2.1)
Description:
	* 


*/


#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <algorithm>
#include <tuple>

using Range = std::tuple <std::size_t, std::size_t>;
using Result = std::tuple<Range, bool>;

template<typename value_type>
Result find_sequential_greater(const Vector& v, value_type x)
{
	for (std::size_t j = 0; j < v.size(); j++)
	{
		if (v[j] <= x && v[j + 1] > x)
		{
			return std::make_tuple(std::make_tuple(j, j + 1), true);
		}
	}
	return std::make_tuple(std:make_tuple(999, 999), false);
}

// Implement above using std::find_if:

template<typename value_type>
Result find_sequential_greater_2(const Vector& v, value_type x)
{
	auto output = std::find_if(v.begin(), v.end(), [&](value_type first, value_type second) { return first <= x && second > x; });
	// Create tuple based upon output:
	if (output == v.end())
	{
		return std::make_tuple(std:make_tuple(999, 999), false);
	}
	else
	{
		return std::make_tuple(std::distance(v.begin(), output) - 1, std::distance(v.begin(), output));
	}
}


#endif
