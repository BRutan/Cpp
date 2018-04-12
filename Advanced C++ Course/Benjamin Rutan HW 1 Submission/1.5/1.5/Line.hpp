/*	Line.hpp (exercise 1.5.5) 
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
	*void display(IODevice&) const: display line on passed input-output device object.
	*string ToString() const: Return string description of Length object's state ("Line((P1_X(), P1_Y()), (P2_X(), P2_Y()))").
*/

#ifndef LINE_HPP
#define LINE_HPP

#include <iostream>
#include <string>
#include "IODevice.hpp"
#include "Point.hpp"
#include "Shape.hpp"

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
	Line() noexcept;							/* Default Constructor. */
	Line(const Point&, const Point&) noexcept;	/* Overloaded Constructor. */
	Line(const Line&) noexcept;					/* Copy Constructor. */
	virtual ~Line() noexcept override;			/* Destructor. */
	//////////////////////////////////////
	// Accessors:
	//////////////////////////////////////
	Point P1() const noexcept;					/* Returns p1 Point object. */
	Point P2() const noexcept;					/* Returns p2 Point object. */
	//////////////////////////////////////
	// Mutators:
	//////////////////////////////////////
	void P1(const Point&) noexcept;				/* Change p1 Point object. */
	void P2(const Point&) noexcept;				/* Change p2 Point object. */
	//////////////////////////////////////
	// Misc. Methods:
	//////////////////////////////////////
	double Length() const noexcept;								/* Return the length of the line. */
	void Draw() const noexcept;								    /* Draw current Line object. */
	void display(const IODevice&) const noexcept;				/* Output to an input-output device object. */
	std::string ToString() const noexcept;						/* Return description of Line object's state ("Line((P1_X(), P1_Y()), (P2_X(), P2_Y()))") */
	//////////////////////////////////////
	// Overloaded Operators:
	//////////////////////////////////////
	// Member operators:
	Line& operator=(const Line&) noexcept;						/* Assignment operator. */
	// Global operators:
	friend std::ostream& operator<<(std::ostream&, const Line&) noexcept;	/* Overloaded ostream operator. */
};

#endif