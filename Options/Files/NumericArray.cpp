/* NumericArray.cpp
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

#ifndef NUMERICARRAY_CPP
#define NUMERICARRAY_CPP

#include"Array.hpp"
#include"NumericArray.hpp"
#include"ArrayException.hpp"
#include"SizeMismatch.hpp"

namespace Containers
{
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	template<typename T>
	NumericArray<T>::NumericArray() : Array<T>()														// Default Constructor.
	{

	}
	template<typename T>
	NumericArray<T>::NumericArray(unsigned int size_in)	: Array<T>(size_in)								// Overloaded Constructor.
	{

	}
	template<typename T>
	NumericArray<T>::NumericArray(const NumericArray<T>& array_in) : Array<T>(array_in)					// Copy Constructor.
	{

	}
	template<typename T>
	NumericArray<T>::~NumericArray()																	// Destructor.
	{

	}
	////////////////////////////
	// Misc Methods:
	////////////////////////////
	template<typename T>
	double NumericArray<T>::DotProduct(const NumericArray<T>& array_in) const // Calculate and return dot product with passed NumericArray<T>.
	{
		// If calling array's size does not match passed array's size, then throw SizeMismatch exception:
		if (Size() != array_in.Size())
		{
			throw SizeMismatch(Size(), array_in.Size(), "DotProduct");
		}
		else
		{
			double dotProduct = 0;
			// Compute the dot product:
			for (int i = 0; i < Size(); i++)
			{
				dotProduct += (*this)[i] * array_in[i];
			}
			return dotProduct;
		}
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	template<typename T>
	NumericArray<T>& NumericArray<T>::operator=(const NumericArray<T>& array_in) // Assignment operator.
	{
		// Preclude self-assignment:
		if (this != &array_in)
		{
			Array<T>::operator=(array_in);
		}
		return *this;
	}
	template<typename T>
	NumericArray<T> NumericArray<T>::operator+(const NumericArray<T>& array_in) const // Add current NumericArray<T> object to another NumericArray<T> object.
	{
		// Throw exception if sizes do not match:
		if (Size() != array_in.Size())
		{
			throw SizeMismatch(Size(), array_in.Size(), "Operator+");
		}
		else
		{
			NumericArray<T> tempArray(Size());
			for (int i = 0; i < Size(); i++)
			{
				tempArray[i] = (*this)[i] + array_in[i];
			}
			return tempArray;
		}
	}
	template<typename T>
	NumericArray<T> NumericArray<T>::operator*(double factor) const					// Multiply all elements in object by scaling factor.
	{
		NumericArray<T> tempArray(Size());
		for (int i = 0; i < Size(); i++)
		{
			tempArray[i] = (*this)[i] * factor;
		}
		return tempArray;
	}
}

#endif