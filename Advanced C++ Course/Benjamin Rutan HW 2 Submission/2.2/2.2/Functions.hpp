/* Functions.hpp (exercise 2.2.1)
Description:
	* 
*/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <type_traits>
#include "SizeExcept.hpp"

/* 2.2.1 */
// Vector/Container implementation:
template<typename T>
T Addition(const T& t1, const T& t2, std::true_type)
{
	if (t1.size() != t2.size())
	{
		throw Exceptions::SizeExcept("Vector dimensions do not match.");
	}
	T output(t1);
	std::size_t index = 0;
	for (auto &i : t2)
	{
		output[index++] += i;
	}
	return output;
}
// Scalar implementation:
template<typename T>
T Addition(const T& t1, const T& t2, std::false_type)
{
	return t1 + t2;
}

// a) Define the Addition function:
template <typename T>
T Addition(const T& t1, const T& t2)
{
	return Addition(t1, t2, std::is_compound<T>());
}

// Vector/Container implementation:
template<typename T>
void AdditiveInverse(T& val, std::true_type)
{
	for (auto &i : val)
	{
		i *= -1;
	}
}

// Scalar implementation:
template<typename T>
void AdditiveInverse(T& val, std::false_type)
{
	val *= -1;
}

// b) Define the AdditiveInverse function:
template <typename T>
void AdditiveInverse(T& val)
{
	AdditiveInverse(val, std::is_compound<T>());
}

// c) Define scalar multiplication function:
template<typename ContainerType, typename ScalarType>
ContainerType ScalarMult(const ContainerType &container, const ScalarType &scalar, std::true_type) // Implementation of below called bridger function:
{
	ContainerType output(container);
	for (std::size_t index = 0; index < output.size(); index++)
	{
		output[index] *= scalar;
	}
	return output;
}

template<typename ContainerType, typename ScalarType>
ContainerType ScalarMult(const ContainerType &container, const ScalarType &scalar, std::false_type) // Implementation of below called bridger function:
{
	throw Exceptions::SizeExcept("ScalarMult except: ContainerType must be an STL or Boost container.");
}

template<typename ContainerType, typename ScalarType>
ContainerType ScalarMult(const ContainerType &container, const ScalarType &scalar)
{
	return ScalarMult(container, scalar, std::is_compound<ContainerType>());
}

// Misc functions:
template<typename T>
void PrintContainer(const T& container)
{
	if (std::is_compound<T>())
	{
		std::size_t count = 1;
		std::cout << "{";
		for (auto &i : container)
		{
			if (count++ < container.size())
			{
				std::cout << i << ", ";
			}
			else
			{
				std::cout << i << " }";
			}
		}
	}
}



#endif