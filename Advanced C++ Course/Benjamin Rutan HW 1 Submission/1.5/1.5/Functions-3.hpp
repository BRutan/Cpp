/* Functions-3.hpp (exercise 1.5.3)
Description:
	* Functions for exercise 1.5.3.
Functions:
	*tuple<double,double,double,double,double> GetStatisticalPRoperties(const Container&): calculate the mean, mean deviation, range, variance and standard deviation of passed dataset stored in STL container. 
	*Type median(const Container<Type, Alloc>&): calculate median of dataset stored in passed sorted STL container.
	*Type mode(const Container<Type, Alloc>&): calculate the mode of dataset stored in passed STL container. If multimodal, then return the smallest mode.
*/


#ifndef FUNCTIONS3_HPP
#define FUNCTIONS3_HPP

#ifndef _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
	#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#endif


#include <boost/numeric/ublas/vector.hpp>
#include <boost/range/numeric.hpp>
#include <memory>
#include <numeric>
#include <set>
#include <tuple>
#include "Exception.hpp"
#include "SizeExcept.hpp"

/* 1.5.3: */
// a) Create a function that returns statistical properties of dataset implemented in a boost::vector:
template<typename Container>
std::tuple<double, double, double, double, double> GetStatisticalProperties(const Container &values)
{
	std::size_t numElements = values.size();
	double mean, meanDev = 0, range, var, stdDev;
	if (numElements > 0)
	{
		// Calculate mean:
		mean = std::accumulate(values.begin(), values.end(), 0.0L, [&](double first, double second) { return first + second; }) / (double)numElements;
		// Calculate mean deviation:
		std::for_each(values.begin(), values.end(), [&](double element) { meanDev += std::abs(element - mean) / (double)numElements; });
		// meanDev = std::accumulate(values.begin(), values.end(), 0.0L, [&](double first, double second) { return std::abs(first - mean) + second; }) / (double)numElements;
		// Calculate range:
		range = (double) *std::max_element(values.begin(), values.end()) - (double) *std::min_element(values.begin(), values.end());
		// Calculate the variance (E[(x - mu)^2] = E(x^2) - E(x)^2).
		var = boost::inner_product(values, values, 0.0L) / (double)numElements - mean * mean;
		// Calculate the standard deviation:
		stdDev = std::sqrt(var);
	}
	else
	{
		throw Exceptions::SizeExcept("There must be at least one element in the passed vector.");
	}
	return std::make_tuple<double, double, double, double, double>(std::move(mean), std::move(meanDev), std::move(range), std::move(var), std::move(stdDev));
}
// b) Create a function that returns median and mode of dataset stored in boost::vector:
template<template<typename T, typename> class Container, class Type, class Alloc = std::allocator<Type>>
Type median(const Container<Type, Alloc> &values)											/* Get median of elements in passed sorted container. */
{
	if (values.size() % 2 == 0)
	{
		return values[values.size() / 2]  / 2.0 + values[values.size() / 2 + 1] / 2.0;
	}
	else
	{
		return values[values.size() / 2];
	}
}

template<template<typename, typename> class Container, class Type, class Alloc = std::allocator<Type>>
Type mode(const Container<Type, Alloc> &values)												/* Get mode of elements in passed container. */
{
	std::map<Type, std::size_t> uniqueCounts;
	std::set<Type> modeSet;
	std::size_t modeIndex = 0, maxFreq = 0;
	for (auto elem = values.begin(); elem != values.end(); elem++)
	{
		// Add element to unique list if not present or increment frequency by 1:
		if (uniqueCounts.find(*elem) != uniqueCounts.end())
		{
			uniqueCounts[*elem]++;
		}
		else
		{
			uniqueCounts.insert(std::pair<Type, std::size_t>(*elem, 1));
		}
	}
	if (uniqueCounts.size())
	{
		// Find the maximum frequency:
		std::for_each(uniqueCounts.begin(), uniqueCounts.end(),
		[&](auto elem)
		{
			std::size_t currFreq = std::get<1>(elem);
			if (maxFreq < currFreq)
			{
				maxFreq = currFreq;
			}
		});
		// Put all uniques that share the maximum frequency into the mode-set:
		std::for_each(uniqueCounts.begin(), uniqueCounts.end(),
		[&](auto elem)
		{
			if (std::get<1>(elem) == maxFreq)
			{
				modeSet.emplace(std::get<0>(elem));
			}
		});
		// Return the first element in the set (std::set is in ascending order by default so first element is the smallest mode):
		return *modeSet.begin();
	}
	else
	{
		throw Exceptions::SizeExcept("There must be at least one element in container to calculate the mode. ");
	}
}

#endif