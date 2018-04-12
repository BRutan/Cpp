/* Circle.cpp (exercise 5.1.3) 
Description:
	*Declare Circle class that represents circle in 2-D Euclidean space.
State Variables/Objects:
	*Point centerPoint: the center of the circle.
	*double m_radius: the radius of the circle.
Member Functions:
	// Constructors/Destructor:
	*Circle(): Default constructor (sets centerPoint's state to (0,0)).
	*Circle(double,double): Overloaded constructor (sets centerPoint's state to passed parameter's values).
	*Circle(const Circle&): Copy constructor (sets calling Circle object's state to passed Circle object's state).
	*~Circle():	Destructor.
	// Accessors:
	*Point CenterPoint() const: Return the centerPoint Point object.
	*double Radius() const: Return the radius of the Circle object.
	// Mutators:
	*void CenterPoint(const Point&): Set the centerPoint object's state to the passed Point object's state.
	*void Radius(double):	Set the radius of the circle. 
	// Misc. methods:
	*double Area() const: calculates and returns area of Circle object.
	*double Circumference() const: calculates and returns circumference of Circle object.
	*double Diameter() const: calculates and returns diameter of Circle object.
	*void Draw() const: draw calling Circle object.
	*string ToString() const: return string description of Circle object's state ("Circle(X,Y) Radius m_radius").
*/

#define _USE_MATH_DEFINES							/* Allow use of M_PI constant defined in cmath header. */
#include<cmath>
#include<iostream>
#include<string>
#include<sstream>
#include"Circle.hpp"
#include"Shape.hpp"

////////////////////////////
// Constructors/Destructor:
////////////////////////////
Circle::Circle() noexcept: centerPoint(), m_radius(0), Shape()										/* Default constructor. Call centerPoint's default constructor and set radius to 0. */
{
			
}
Circle::Circle(double x_in, double y_in) noexcept : centerPoint(x_in, y_in), m_radius(0), Shape()	/* Overloaded constructor. Set radius to 0 since only information known is the center point's coordinates. */
{
			
}
Circle::Circle(const Circle &circle_in) noexcept : centerPoint(circle_in.centerPoint), m_radius(circle_in.m_radius), Shape(circle_in)			/* Copy constructor. */
{
			
}
Circle::~Circle() noexcept							/* Destructor. */
{
			
}
////////////////////////////
// Accessors:
////////////////////////////
Point Circle::CenterPoint() const noexcept					/* Return the center point object. */
{
	return centerPoint;
}
double Circle::Radius() const noexcept						/* Return the value of the circle's radius. */
{
	return m_radius;
}
////////////////////////////
// Mutators:			  
////////////////////////////
void Circle::CenterPoint(const Point &point_in) noexcept	/* Set the state of the center point to passed point's state. */
{
	centerPoint = point_in;
}
void Circle::Radius(const double radius_in) noexcept		/* Return m_radius. */
{
	m_radius = radius_in;
}
////////////////////////////
// Misc Methods:
////////////////////////////
double Circle::Area() const noexcept						/* Return the value of the circle's area. */
{
	return M_PI * m_radius * m_radius;
}
double Circle::Circumference() const noexcept				/* Return the value of the circle's circumference. */
{
	return 2 * M_PI * m_radius;
}
double Circle::Diameter() const noexcept					/* Return the value of the circle's diameter. */
{
	return m_radius * 2;
}
void Circle::Draw() const noexcept							/* Draw the Circle object. */
{
	std::cout << "Circle has been drawn. " << std::endl;
}
void Circle::display(const IODevice& in) const noexcept		/* Display Circle object on passed input-output device. */
{
	in << *this;
}
std::string Circle::ToString() const noexcept				/* Return the string description of the circle ("Circle(X(), Y()) Radius m_radius") */
{
	std::stringstream ss;
	// Append the base Shape object description to Circle object description:
	std::string s = Shape::ToString();
	ss << "Circle(" << centerPoint.X() << ", " << centerPoint.Y() << ") Radius " << m_radius << " " << s;

	return ss.str();
}
/////////////////////////////////////////////////////////////////////
// Overloaded Operators: 
/////////////////////////////////////////////////////////////////////
// Member operators:
Circle& Circle::operator=(const Circle& circle_in) noexcept		/* Assignment operator. */
{
	// Preclude self-assignment:
	if (this != &circle_in)
	{
		centerPoint = circle_in.centerPoint;
		m_radius = circle_in.m_radius;
		// Copy passed base Shape object's base state:
		Shape::operator=(circle_in);
	}
	return *this;
}
// Global operators:
std::ostream& operator<<(std::ostream &os, const Circle &circle_in)	noexcept							/* Overloaded ostream operator. */
{
	os << "Circle(" << circle_in.CenterPoint().X() << ", " << circle_in.CenterPoint().Y() << ") Radius " << circle_in.Radius();
	return os;
}
