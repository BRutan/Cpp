/* GetVariant.hpp
Description:
	*Define function ShapeVariant GetVariant(unsigned) that returns a ShapeVariant
	object containing a Circle (0), Line (1) or Point(2) depending upon unsigned integer entered.
	Throws exception -1 if any other value is entered.
*/
#ifndef GETVARIANT_HPP
#define GETVARIANT_HPP

#include<boost/variant.hpp>
#include"Circle.hpp"
#include"Line.hpp"
#include"Point.hpp"
#include"Shape.hpp"

typedef boost::variant<CAD::Point, CAD::Line, CAD::Circle> ShapeVariant;

namespace Containers
{
	ShapeVariant GetVariant(unsigned i)
	{
		// Return derived Shape object depending on input:
		switch (i)
		{
		case 0:
		{
			return ShapeVariant(CAD::Circle(1, 1));
		}
		case 1:
		{
			return ShapeVariant(CAD::Line(CAD::Point(1, 1), CAD::Point(1, 1)));
		}
		case 2:
		{
			return ShapeVariant(CAD::Point(1, 1));
		}
		default:	// Throw exception if any other value is passed.
			throw -1;
		}
	}
}

#endif