/* Point.cpp
Definition:
	*Define Point class member functions declared in 'Point.hpp'.
State Variables:
	*double m_x, m_y: Represents x-axis and y-axis coordinates respectively.
Member Functions:
	// Constructors/Destructor:
	*Point(): Default constructor, sets m_x and m_y to 0.0.
	*Point(double, double): Overloaded constructor, sets m_x and m_y to value of passed variables.
	*explicit Point(double): Conversion constructor.
	*Point(const Point&): Copy constructor, sets current object's state to passed object's state.
	*~Point(): Destructor, terminates Point object.
	// Accessors:
	*double X() const: returns value of m_x.
	*double Y() const: returns value of m_y.
	// Mutators:
	*void X(double): set value of m_x to passed variable.
	*void Y(double): set value of m_y to passed variable.
	// Misc. Methods:
	*double Distance() const: calculate and return euclidean distance between origin (0, 0) and Point object.
	*double Distance(const Point&) const: calculate and return euclidean distance between passed Point object (by reference) and calling Point object.
	*void Draw() const: draw the calling Point object.
	*void display(IODevice&) const: Display the point on a passed input-output device.
	*string ToString() const: return string "Point(m_x, m_y)", description of current state of Point object.
*/
#include <cmath>
#include <string>
#include <sstream>
#include "Point.hpp"
#include "Shape.hpp"
/////////////////////////////////
// Constructors and Destructor:
/////////////////////////////////
Point::Point() noexcept : m_x(), m_y(), Shape()									/* Default Constructor. */
{
}
Point::Point(double x_in, double y_in) noexcept : m_x(x_in), m_y(y_in), Shape()	/* Overloaded Constructor (set m_x and m_y). */
{
}
Point::Point(double xy_in) noexcept : m_x(xy_in), m_y(xy_in), Shape()			/* Conversion Constructor. */
{
}
Point::Point(const Point &point_in) noexcept : m_x(point_in.X()), m_y(point_in.Y()), Shape(point_in)			/* Copy Constructor. */
{
}
Point::~Point() noexcept  									/* Destructor. */
{
}
/////////////////////////////////
// Accessors: 
/////////////////////////////////
double Point::X() const	noexcept						/* Return m_x . */
{
	return m_x;
}
double Point::Y() const noexcept							/* Return m_y. */
{
	return m_y;
}
///////////////////////////////
// Mutators:
///////////////////////////////
void Point::X(double x_in) noexcept						/* Set value of x coordinate. */
{
	m_x = x_in;
}
void Point::Y(double y_in) noexcept						/* Set value of y coordinate. */
{
	m_y = y_in;
}
/////////////////////////////////
// Misc. methods:
/////////////////////////////////
void Point::Draw() const noexcept									/* Draw the point. */
{
}
double Point::Distance() const noexcept								/* Calculate and return Point's euclidean distance from passed point. */
{
	return sqrt(pow(m_x, 2.0) + pow(m_y, 2.0));
}
double Point::Distance(const Point &point_in) const	noexcept		 /* Calculate and return Point's euclidean distance from passed point. */
{
	return sqrt(pow(m_x - point_in.m_x, 2.0) + pow(m_y - point_in.m_y, 2.0));
}
std::string Point::ToString() const	noexcept 				 /* Return string containing current state of Point object ("Point(m_x, m_y)"). */
{
	std::stringstream ss;
	// Append the base Shape object description to Point object description:
	std::string s = Shape::ToString();
	ss << "Point(" << m_x << ", " << m_y << ") " << s;
	return ss.str();
}
///////////////////////////////
// Overloaded Operators:
///////////////////////////////
// Member operators:
Point Point::operator-() const noexcept					/* Negate the coordinates. */
{
	Point point_out(-this->m_x, -this->m_y);
	return point_out;
}
Point Point::operator*(double factor) const	noexcept	/* Scale the coordinates by passed scaling factor. */
{
	Point point_out(factor*this->m_x, factor*this->m_y);
	return point_out;
}
Point Point::operator+(const Point& point_in) const	noexcept	/* Add the coordinates. */
{
	Point point_out(point_in.m_x + m_x, point_in.m_y + m_y);
	return point_out;
}
bool Point::operator==(const Point& point_in) const	noexcept	/* Compare passed point to current point object. */
{
	return (point_in.m_x == m_x && point_in.m_y == m_y);
}
Point& Point::operator=(const Point& point_in) noexcept			/* Assignment operator. */
{
	// Preclude self-assignment (check to see if passed point has same memory address):
	if (this != &point_in)
	{
		m_x = point_in.m_x;
		m_y = point_in.m_y;
		// Copy passed Line object's base state:
		Shape::operator=(point_in);
	}
	return *this;
}
Point& Point::operator*=(double factor)	noexcept				/* Scale the coordinates and assign to current point object. */
{
	m_x *= factor;
	m_y *= factor;
	return *this;
}
// Global operators:
std::ostream& operator<<(std::ostream& os, const Point& point_out) noexcept		/* Overloaded ostream operator. */
{
	os << "Point(" << point_out.m_x << ", " << point_out.m_y << ")";
	return os;
}
