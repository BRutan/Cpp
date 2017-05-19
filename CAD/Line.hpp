/*	Line.hpp
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
	*void Draw() const: draw calling Line object.
	*string ToString() const: Return string description of Length object's state ("Line((P1_X(), P1_Y()), (P2_X(), P2_Y()))").
*/

#ifndef LINE_HPP
#define LINE_HPP

#include<iostream>
#include<string>
#include"Point.hpp"
#include"Shape.hpp"

namespace CAD
{
	class Line : public Shape
	{
	private:
		//////////////////////////////////////
		// State objects: 
		//////////////////////////////////////
		Point p1;						/* First point object. */
		Point p2;						/* Second point object. */
	public:
		//////////////////////////////////////
		// Constructors/Destructor: 
		//////////////////////////////////////
		Line();								/* Default Constructor. */
		Line(const Point&, const Point&);	/* Overloaded Constructor. */
		Line(const Line&);					/* Copy Constructor. */
		virtual ~Line();					/* Destructor. */
		//////////////////////////////////////
		// Accessors:
		//////////////////////////////////////
		Point P1() const;					/* Returns p1 Point object. */
		Point P2() const;					/* Returns p2 Point object. */
		//////////////////////////////////////
		// Mutators:
		//////////////////////////////////////
		void P1(const Point&);				/* Change p1 Point object. */
		void P2(const Point&);				/* Change p2 Point object. */
		//////////////////////////////////////
		// Misc. Methods:
		//////////////////////////////////////
		double Length() const;				/* Return the length of the line. */
		void Draw() const;					/* Draw current Line object. */
		std::string ToString() const;		/* Return description of Line object's state ("Line((P1_X(), P1_Y()), (P2_X(), P2_Y()))") */
		//////////////////////////////////////
		// Overloaded Operators:
		//////////////////////////////////////
		// Member operators:
		Line& operator=(const Line&);		/* Assignment operator. */
		// Global operators:
		friend std::ostream& operator<<(std::ostream&, const Line&);	/* Overloaded ostream operator. */
	};
}

#endif