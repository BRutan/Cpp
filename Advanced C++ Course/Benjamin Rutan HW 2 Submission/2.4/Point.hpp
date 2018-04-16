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

#include <iostream>
#include <string>
#include "Shape.hpp"

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
	Point() noexcept;						/* Default constructor. */
	Point(double, double) noexcept;			/* Overloaded constructor. */
	explicit Point(double) noexcept;		/* Conversion constructor. */
	Point(const Point&) noexcept;			/* Copy constructor. */
	virtual ~Point() noexcept;				/* Destructor. */
	///////////////////////////
	// Accessors:
	///////////////////////////
	double X() const noexcept;						/* Get value of x coordinate. */
	double Y() const noexcept;						/* Get value of y coordinate. */
	///////////////////////////
	// Mutators:
	///////////////////////////
	void X(double) noexcept;							/* Set value of x coordinate. */
	void Y(double) noexcept;							/* Set value of y coordinate. */
	///////////////////////////
	// Misc. Methods:
	///////////////////////////
	double Distance() const noexcept;							/* Calculate and return distance between Point and origin (0, 0). */
	double Distance(const Point&) const noexcept;				/* Calculate and return distance between passed Point object. */
	virtual void Draw() const noexcept override;				/* Draw the point. */
	virtual std::string ToString() const noexcept override;
	///////////////////////////
	// Overloaded Operators:
	///////////////////////////
	// Member operators:
	Point operator-() const noexcept;				/* Negate the coordinates. */
	Point operator*(double) const noexcept;			/* Scale the coordinates by passed scaling factor. */
	Point operator+(const Point&) const noexcept;	/* Add the coordinates. */
	bool operator==(const Point&) const noexcept;	/* Compare passed point to current point object. */
	Point& operator=(const Point&) noexcept;		/* Assignment operator. */
	Point& operator*=(double) noexcept;				/* Scale the coordinates and assign to current point object. */
	// Global operators:
	friend std::ostream& operator<<(std::ostream&, const Point&) noexcept;	/* Overloaded ostream operator. */
};

#endif
