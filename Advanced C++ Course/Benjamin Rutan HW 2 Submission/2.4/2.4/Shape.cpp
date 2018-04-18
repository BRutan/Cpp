/* Shape.cpp
Description:
	*Source file for Shape class.
State Variables/Objects:
	*int m_id: ID of current Shape object.
Member Functions:
	// Constructors/Destructor:
	*Shape(): Default constructor. Sets m_id to random value(in between 0 and RAND_MAX).
	*Shape(const Shape&): Copy constructor. Sets m_id to passed Shape object's m_id.
	*virtual ~Shape(): Destructor.
	// Accessors:
	*int ID() const: returns the m_id of the calling Shape object.
	// Misc. Methods:
	*virtual void Draw() const: Pure Virtual Memory Function to be overriden in derived classes.
	*virtual string ToString() const: return string description of calling Shape object.
*/
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Shape.hpp"
////////////////////////////
// Constructors/Destructor:
////////////////////////////
Shape::Shape() noexcept : m_id(std::rand())		/* Default constructor. Sets m_id to a random integer in between 0 and RAND_MAX. */
{
}
Shape::Shape(const Shape &shape_in) noexcept : m_id(shape_in.m_id) /* Copy constructor. Sets m_id to passed Shape object's m_id. */
{
}
Shape::~Shape() noexcept										  /* Destructor. */
{
}
////////////////////////////
// Accessors:
////////////////////////////
int Shape::ID() const noexcept									 /* Returns m_id. */
{
	return m_id;
}
////////////////////////////
// Misc Methods:
////////////////////////////
void Shape::Print() const noexcept										 /* Display ToString() to stdout. */
{
	std::cout << ToString() << std::endl;
}
std::string Shape::ToString() const noexcept
{
	std::istringstream output(this->m_id);
	return output.str();
}
////////////////////////////
// Overloaded Operators:
////////////////////////////
Shape& Shape::operator=(const Shape &shape_in) noexcept					 /* Assignment operator. */
{
	// Preclude self-assignment:
	if (this != &shape_in)
	{
		m_id = shape_in.m_id;
	}
	return *this;
}
