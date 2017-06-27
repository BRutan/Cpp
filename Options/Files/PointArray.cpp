/* PointArray.cpp
Description:
	*Dynamic array for Point objects, using concrete inheritance with Array class.
Member Functions:
	// Constructors/Destructor:
	*PointArray(): Default destructor.
	*PointArray(unsigned int): Overloaded constructor.
	*PointArray(const &PointArray): Copy constructor.
	*~PointArray(): Destructor.
	// Misc Methods:
	long Length() const: Get total length between points in the array.
*/
#include"PointArray.hpp"
#include"Array.hpp"
#include"Point.hpp"
#include"Shape.hpp"

namespace Containers
{		
 /////////////////////////////
 // Constructors/Destructor:
 /////////////////////////////
	PointArray::PointArray(): Array()		/* Default constructor. */
	{

	}
	PointArray::PointArray(const PointArray& array_in): Array(array_in)		/* Copy constructor. */
	{

	}
	PointArray::PointArray(unsigned int size_in): Array(size_in)			/* Overloaded constructor. */
	{

	}
	PointArray::~PointArray()				/* Destructor. */
	{

	}
	////////////////////////////
	// Misc Methods:
	////////////////////////////
	double PointArray::Length() const /* Get length between two Point at passed indices in the Array. */
	{
		double distanceAccum = 0;
		for (int i = 0; i < Size() - 1; i++)
		{
			distanceAccum += (*this)[i].Distance((*this)[i + 1]);
		}
		return distanceAccum;
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	PointArray& PointArray::operator=(const PointArray &array_in) /* Assignment operator. */
	{
		if (this != &array_in)
		{
			(*this).Array::operator=(array_in);
		}
		return *this;
	}
}
