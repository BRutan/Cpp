/* NumericArray.hpp
Description:
	*Derived class from Array<T> template base class.
Member Functions:
	// Constructors/Destructor:
	*NumericArray(): Default constructor. Calls base Array<T>'s default constructor (set size to defaultSize).
	*NumericArray(unsigned int): Overloaded constructor. Set size to passed value.
	*NumericArray(const NumericArray<T>&): Copy constructor.
	// Misc. Methods:
	*T DotProduct(const NumericArray<T>&) const: Calculate and return the dot product of calling object and passed NumericArray<T> object. 
*/

#ifndef NUMERICARRAY_HPP
#define NUMERICARRAY_HPP

#include"Array.hpp"

namespace Containers
{
	template<typename T>
	class NumericArray : public Array<T>
	{
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		NumericArray();							/* Default Constructor. */
		NumericArray(unsigned int);				/* Overloaded Constructor. */
		NumericArray(const NumericArray<T>&);	/* Copy Constructor. */
		virtual ~NumericArray();				/* Destructor. */
		////////////////////////////
		// Misc Methods:
		////////////////////////////
		double DotProduct(const NumericArray<T>&) const; /* Calculate and return dot product with passed NumericArray<T>. */
		////////////////////////////
		// Overloaded Operators:
		////////////////////////////
		NumericArray<T>& operator=(const NumericArray<T>&);		 /* Assignment operator. */
		NumericArray<T> operator+(const NumericArray<T>&) const; /* Add current NumericArray<T> object to another NumericArray<T> object. */
		NumericArray<T> operator*(double) const;				 /* Multiply all elements in object by scaling factor. */
	};
}

#ifndef NUMERICARRAY_CPP
#include"NumericArray.cpp"
#endif

#endif