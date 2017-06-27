/* Point.hpp
Definition:
	*Declare Point class that represents a point in 2-D Euclidean space.
State Variables:
	*double m_x, m_y: Represents x-axis and y-axis coordinates respectively.
Member Functions:
	// Constructors/Destructor:
	*Point(): Default constructor, sets m_x and m_y to 0.0.
	*Point(double, double): Overloaded constructor, sets m_x and m_y to value of passed variables.
	*explicit Point(double): Conversion constructor.
	*Point(const Point&): Copy constructor, sets current object's state to passed object's state.
	*virtual ~Point(): Destructor, terminates Point object.
	// Accessors:
	*double X() const: returns value of m_x.
	*double Y() const: returns value of m_y.
	// Mutators:
	*void X(double): set value of m_x to passed variable.
	*void Y(double): set value of m_y to passed variable.
	// Misc. Methods:
	*double Distance() const: calculate and return euclidean distance between origin (0, 0) and Point object.
	*double Distance(const Point&) const: calculate and return euclidean distance between passed Point object (by reference) and calling Point object.
	*void Draw() const: Draw the calling Point object.  
	*string ToString() const: return string "Point(m_x, m_y)", description of current state of Point object.
*/

#ifndef POINT_HPP
#define POINT_HPP

#include<iostream>
#include<string>
#include"Shape.hpp"

namespace CAD
{
	class Point : public Shape
	{
	private:
		///////////////////////////
		// State Variables:
		///////////////////////////
		double m_x;								/* Value of x coordinate. */
		double m_y;								/* Value of y coordinate. */
	public:
		///////////////////////////
		// Constructors/Destructor: 
		///////////////////////////
		Point();								/* Default constructor. */
		Point(double, double);					/* Overloaded constructor. */
		explicit Point(double);					/* Conversion constructor. */
		Point(const Point&);					/* Copy constructor. */
		virtual ~Point();						/* Destructor. */
		///////////////////////////
		// Accessors:
		///////////////////////////
		double X() const;						/* Get value of x coordinate. */
		double Y() const;						/* Get value of y coordinate. */
		///////////////////////////
		// Mutators:
		///////////////////////////
		void X(double);							/* Set value of x coordinate. */
		void Y(double);							/* Set value of y coordinate. */
		///////////////////////////
		// Misc. Methods:
		///////////////////////////
		double Distance() const;				/* Calculate and return distance between Point and origin (0, 0). */
		double Distance(const Point&) const;	/* Calculate and return distance between passed Point object. */
		void Draw() const;						/* Draw current Point object. */
		std::string ToString() const;			/* Return "Point(m_x, m_y)". */
		///////////////////////////
		// Overloaded Operators:
		///////////////////////////
		// Member operators:
		Point operator-() const;				/* Negate the coordinates. */
		Point operator*(double) const;			/* Scale the coordinates by passed scaling factor. */
		Point operator+(const Point&) const;	/* Add the coordinates. */
		bool operator==(const Point&) const;	/* Compare passed point to current point object. */
		Point& operator=(const Point&);			/* Assignment operator. */
		Point& operator*=(double);				/* Scale the coordinates and assign to current point object. */
		// Global operators:
		friend std::ostream& operator<<(std::ostream&, const Point&);	/* Overloaded ostream operator. */
	};
}
#endif