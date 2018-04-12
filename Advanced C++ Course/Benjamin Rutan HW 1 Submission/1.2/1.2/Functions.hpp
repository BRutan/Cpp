/* Functions.hpp (exercise 1.2.2):
Description:
	* Solution to problems 1-3.
Functions:
	*void SwapCopyStyle(T& a, T&b): swap elements a and b using classical method.
	*void SwapCopyStyle_MoveSemantics(T&& a, T&&b): swap elements a and b using move semantics.
*/


#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

template <typename T>
void SwapCopyStyle(T& a, T& b)										/* Swap objects using classic method, requiring more steps than move operator. */
{ // Swap a and b in copying way; temporary object needed
	T tmp(a);		// Copy constructor
	a = b;			// Copy all elements from b to a
	b = tmp;		// Copy all elements from tmp to b
}

template <typename T>
void SwapCopyStyle_MoveSemantics(T &&a, T &&b)						/* Swap objects using move semantics, requiring fewer steps than classical swap. */
{
	T &&tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}


#endif