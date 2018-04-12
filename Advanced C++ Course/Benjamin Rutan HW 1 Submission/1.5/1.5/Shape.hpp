/* Shape.hpp (exercise 1.5.5)
Description:
	*Header file for Shape class, declares member variables/objects and functions.
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
	*virtual void Draw() const: Output statement to stdout with calling object's information.
	*virtual void display(IODevice&) const: 
	*virtual string ToString() const: return string description of calling Shape object. 
*/

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "IODevice.hpp"

class Shape
{
private:
	////////////////////////////
	// State variables: 
	////////////////////////////
	int m_id;											 /* ID of current Shape object. */
public:
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	Shape() noexcept;									 /* Default Constructor. */
	Shape(const Shape&) noexcept;						 /* Copy Constructor. */
	virtual ~Shape() noexcept;							 /* Destructor. */
	////////////////////////////
	// Accessors:
	////////////////////////////
	int ID() const noexcept;							 /* Returns m_id. */
	////////////////////////////
	// Misc Methods:
	////////////////////////////
	virtual void Draw() const noexcept = 0;					   /* Pure Virtual Memory Function. Makes the class abstract. */
	virtual void display(const IODevice&) const noexcept = 0;  /* Pure Virtual Memory Function. Makes the class abstract. */
	void Print() const noexcept;						 /* Prints ToString(). */
	virtual std::string ToString() const noexcept;		 /* Returns "ID: <m_id>". */
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	Shape& operator=(const Shape&) noexcept;			 /* Assignment operator (with Shape). */
};


#endif