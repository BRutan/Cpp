/*	Line.cpp
Description:
	* Declare Line class that represents a line in 2-D Euclidean space.
State Variables/Objects:
	*Point p1, p2: Points in 2-D Euclidean space.
Member Functions:
	*Line(): Default constructor (allocates memory for both state Point objects, sets their states to (0,0)).
	*Line(const Point&, const Point&): Overloaded constructor (allocates memory for both state Point objects, sets their states to (0,0)).
	*Line(const Line&): Copy constructor (allocates memory for both state Point objects, sets their states to passed Line's point's states).
	*~Line(): Destructor (frees memory previously allocated by constructor).
	// Accessors:
	*Point P1() const: Return copy of P1 Point Object.
	*Point P2() const: Return copy of P2 Point Object.
	// Mutators:
	*void P1(const Point&): Change P1's state to state of passed Point object.
	*void P2(const Point&): Change P2's state to state of passed Point object.
	// Misc. Methods:
	*double Length() const: Return length of line.
	*void Draw() const: Draw calling Line object. 
	*string ToString() const: Return string description of Length object's state ("Line((P1_X(), P1_Y()), (P2_X(), P2_Y()))").
*/

#include<iostream>
#include<string>
#include<sstream>
#include"Line.hpp"
#include"Shape.hpp"

namespace CAD
{
	////////////////////////////////
	// Constructors/Destructor:
	////////////////////////////////
	Line::Line() : p1(), p2(), Shape()						/* Default constructor. */
	{
		
	}
	Line::Line(const Point &p1_in, const Point &p2_in) : p1(p1_in), p2(p2_in), Shape()		/* Overloaded constructor (parameters reference existing point objects). */
	{
		
	}
	Line::Line(const Line &line_in) : p1(line_in.p1), p2(line_in.p2), Shape(line_in)		/* Copy constructor. */
	{
		
	}
	Line::~Line()											/* Destructor. */
	{
		
	}
	////////////////////////////////
	// Accessors:
	////////////////////////////////
	Point BenRutan::CAD::Line::P1() const					/* Return copy of P1. */
	{
		return p1;
	}
	Point BenRutan::CAD::Line::P2() const					/* Return copy of P2. */
	{
		return p2;
	}
	////////////////////////////////
	// Mutators:
	////////////////////////////////
	void Line::P1(const Point &point_in)					/* Set state of P1 by using assignment operator with point_in. */
	{
		p1 = point_in;
	}
	void Line::P2(const Point &point_in)					/* Set state of P2 by using assignment operator with point_in. */
	{
		p2 = point_in;
	}
	////////////////////////////////
	// Misc. methods:
	////////////////////////////////
	double Line::Length() const								/* Return euclidean distance between P1 and P2. */
	{
		return (p1.Distance(p2));
	}
	void Line::Draw() const									/* Draw current Line object. */
	{
		std::cout << "Line has been drawn. " << std::endl;
	}
	std::string Line::ToString() const						/* Return description of Line object's state ("Line((P1_X(), P1_Y()), (P2_X(), P2_Y()))") */
	{
		std::stringstream ss;
		// Append the base Shape object description to Line object description:
		std::string s = Shape::ToString();
		ss << "Line({" << p1.X() << ", " << p1.Y() << "},{" << p2.X() << ", " << p2.Y() << "}) " << s;

		return ss.str();
	}
	//////////////////////////////////////
	// Overloaded Operators:
	//////////////////////////////////////
	// Member operators:
	Line& Line::operator=(const Line& line_in)				/* Assignment operator. */
	{
		// Preclude self-assignment (check if passed line has the same memory address):
		if (this != &line_in)
		{
			p1 = line_in.p1;
			p2 = line_in.p2;
			// Copy passed Line object's base state:
			Shape::operator=(line_in);
		}

		return *this;
	}
	// Global operators:
	std::ostream& operator<<(std::ostream& os, const Line& line_in)		/* Overloaded ostream operator. */
	{
		os << "Line((" << line_in.p1.X() << ", " << line_in.p1.Y() << "),(" << line_in.p2.X() << ", " << line_in.p2.Y() << "))";
		return os;
	}
}