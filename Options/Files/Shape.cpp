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

#include<iostream>
#include<cstdlib>
#include<sstream>
#include"Shape.hpp"

namespace CAD
{
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	Shape::Shape() : m_id(std::rand())		/* Default constructor. Sets m_id to a random integer in between 0 and RAND_MAX. */
	{
		
	}
	Shape::Shape(const Shape &shape_in): m_id(shape_in.m_id) /* Copy constructor. Sets m_id to passed Shape object's m_id. */
	{
			
	}
	Shape::~Shape()							/* Destructor. */
	{
		
	}
	////////////////////////////
	// Accessors:
	////////////////////////////
	int Shape::ID() const					/* Returns m_id. */
	{
		return m_id;
	}
	////////////////////////////
	// Misc Methods:
	////////////////////////////
	std::string Shape::ToString() const		/* Return string description of calling object. */
	{
		std::stringstream ss;
		ss << "ID: " << m_id;
		return ss.str();
	}
	void Shape::Print() const				/* Display ToString() to stdout. */
	{
		std::cout << ToString() << std::endl;
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	Shape& Shape::operator=(const Shape &shape_in) /* Assignment operator. */
	{
		// Preclude self-assignment:
		if (this != &shape_in)
		{
			m_id = shape_in.m_id;
		}
		return *this;
	}
}