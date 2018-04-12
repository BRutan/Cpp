/* Functions-4.hpp (exercise 1.5.4)
Description:
	* Create STL adapter functions to accomplish specific goals.
Functions:
	* std::size_t findIndex(const Container<Type, std::allocator<Type>>&, Type x): find the first index i in the passed sorted STL container v such that v[i] <= x < v[i + 1], else return the size of the container if condition not met.
	* std::pair<Type, std::size_t> maxError(const Container<Type, Alloc>&, const Container<Type, Alloc>&, const std::pair<std::size_t, std::size_t>&, bool): find the maximum relative or absolute error between two datasets stored in STL containers.
*/
#ifndef FUNCTIONS4_HPP
#define FUNCTIONS4_HPP

#ifndef _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
	#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#endif

#include <iterator>
#include <memory>
#include "Exception.hpp"
#include "OutOfBounds.hpp"
#include "RangeExcept.hpp"
#include "SizeExcept.hpp"

/* 1.5.4 */
// a) Create an STL adapter for sorted numeric vector V and target value X to find first index i s.t. v[i] <= x < v[i + 1]

// Assumes that vector is sorted:
template<template<class, class> class Container, typename Type>
std::size_t findIndex(const Container<Type, std::allocator<Type>> &container_in, Type x) noexcept
{
	// Since array is sorted, the minimum value will be the first element and the maximum value will be the last element:
	Type originalX = x, min = *container_in.begin(), max = *(container_in.end() - 1);
	// If x is greater than the maximum value then return the size of the container since condition cannot be true:
	if (x > max)
	{
		return container_in.size();
	}
	auto iter = container_in.begin();
	std::size_t dist;
	// Search through vector until criteria is met:
	while (true)
	{
		iter = std::find(iter, container_in.end(), x);
		dist = std::distance(iter, container_in.end());
		if (iter != container_in.end() && iter != (container_in.end() - 1))
		{
			// Case 1: x is present in the vector and not at end - simply check if condition is present
			if (originalX < *(iter + 1))
			{
				return std::distance(container_in.begin(), iter);
			}
			else
			{
				// If condition not met, continue to the next iterator in vector (in case there are duplicate xs present):
				iter++;
			}	
		}
		else if (dist == 1)
		{
			// Case 2: x is the last element of the vector - return the size of the vector:
			return container_in.size();
		}
		else 
		{
			// Case 3: x is not present in vector - reduce x and check again until condition is met:
			if (x > min)
			{
				x--;
				iter = container_in.begin();
			}
			else
			{
				// x cannot be reduced any further, return the size of the vector since the condition is not present for passed x: 
				return container_in.size();
			}
		}
	}
}

template<template<typename T, typename> class Container, class Type, class Alloc = std::allocator<Type>>
std::pair<Type, std::size_t> maxError(const Container<Type, Alloc> &left, const Container<Type, Alloc> &right, const std::pair<std::size_t, std::size_t> &range, bool relativeError)
{
	if (left.size() != right.size())
	{
		throw Exceptions::SizeExcept("maxError() Exception: vector dimensions do not match.");
	}
	std::size_t start = std::get<0>(range), end = std::get<1>(range); 
	if (start > end)
	{
		throw Exceptions::RangeExcept("maxError() Exception: minimum value of passed range is greater than maximum value of passed range."); // Create exception 
	}
	else if (end >= left.size())
	{
		throw Exceptions::RangeExcept("maxError() Exception: search range is out of bounds. ");
	}
	std::vector<Type> errors; // Determine proper usage:
	for (std::size_t index = start; index <= end; index++)
	{
		(!relativeError) ? errors.push_back(left[index] - right[index]) : errors.push_back((left[index] - right[index]) / left[index]);
	}
	auto maxErr = std::max_element(errors.begin(), errors.end());
	// Return the maximum error and corresponding index where occurs:
	return (std::make_pair<Type, std::size_t>(std::move(*maxErr), start + std::distance(errors.begin(), maxErr)));
}
	

#endif
