/* Circle.hpp (exercise 1.5.3)
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
	*~Circle():	Destructor (frees memory allocated for centerPoint during construction).
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
	*void Draw(): draw calling Circle object.
	*string ToString() const: return string description of Circle object's state ("Circle(X,Y) Radius m_radius"). 
*/

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>
#include <string>
#include "IODevice.hpp"
#include "Point.hpp"
#include "Shape.hpp"

class Circle : public Shape
{
private:
	//////////////////////////////////////
	// State objects/variables: 
	//////////////////////////////////////
	Point centerPoint;							/* Center of circle. */
	double m_radius;							/* Radius of circle. */
public:
	//////////////////////////////////////
	// Constructors/Destructor:
	//////////////////////////////////////
	Circle() noexcept;									/* Default constructor. */
	Circle(double, double) noexcept;					/* Overloaded constructor, sets x and y coordinate of centerPoint. */
	Circle(const Circle&) noexcept;						/* Copy constructor. */
	virtual ~Circle() noexcept override;				/* Destructor. */
	//////////////////////////////////////
	// Accessors:
	//////////////////////////////////////
	Point CenterPoint() const noexcept;					/* Return center point as Point object. */
	double Radius() const noexcept;	 					/* Return the radius of the circle. */
	//////////////////////////////////////
	// Mutators:
	//////////////////////////////////////
	void CenterPoint(const Point&) noexcept;			/* Set center point via copying coordinates of passed Point object. */
	void Radius(double) noexcept;						/* Set the radius of the Circle. */
	//////////////////////////////////////
	// Misc. methods:
	//////////////////////////////////////
	double Area() const noexcept;						/* Return the Area of the circle. */
	double Circumference() const noexcept;				/* Return the Circumference of the circle. */
	double Diameter() const noexcept;					/* Return the Diameter of the circle. */
	void Draw() const noexcept;							/* Draw current Circle object.*/
	void display(const IODevice&) const noexcept;
	std::string ToString() const noexcept;				/* Return description of Circle, i.e. "Circle(x,y)". */
	//////////////////////////////////////
	// Overloaded Operators:
	//////////////////////////////////////
	// Member operators:
	Circle& operator=(const Circle&) noexcept;			/* Assignment operator. */
	// Global operators:
	friend std::ostream& operator<<(std::ostream&, const Circle&) noexcept;
};	

#endif