/* PointArray.hpp
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

#ifndef POINTARRAY_HPP
#define POINTARRAY_HPP

#include"Array.hpp"
#include"Point.hpp"
#include"Shape.hpp"

namespace Containers
{
	class PointArray : public Array<CAD::Point>
	{
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		PointArray();						/* Default constructor. */
		PointArray(unsigned int);			/* Overloaded constructor. */
		PointArray(const PointArray&);		/* Copy constructor. */
		virtual ~PointArray();				/* Destructor. */
		////////////////////////////
		// Misc Methods:
		////////////////////////////
		double Length() const;						/* Get total length between the points in the array. */
		////////////////////////////
		// Overloaded Operators:
		////////////////////////////
		PointArray& operator=(const PointArray&); /* Assignment operator. */
	};
}


#endif