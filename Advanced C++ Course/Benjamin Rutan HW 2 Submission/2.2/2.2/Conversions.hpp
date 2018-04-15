/* Conversions.hpp (exercise 2.2.3)
Description:
	* Define conversion aliases that provide various conversions upon passed types.
Aliases:
	* removeConst<T>: converts type to a non const version.
	* removeVolatile<T>: converts volatile type to a non-volatile version.
	* removePointer<T>: converts pointer to a non-pointer version.
	
*/

#ifndef CONVERSIONS_HPP
#define CONVERSIONS_HPP

#include <type_traits>

// a) Define the required functions:

template<typename T>
using removeConst = typename std::remove_const<T>::type;

template<typename T>
using removeVolatile = typename std::remove_volatile<T>::type;

template<typename T>
using removePointer = typename std::remove_pointer<T>::type;

template<typename T>
using makeUnsigned = typename std::make_unsigned<T>::type;


#endif
