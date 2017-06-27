/* Shape.hpp
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
	*virtual void Draw() const: Pure Virtual Memory Function to be overriden in derived classes.
	*virtual string ToString() const: return string description of calling Shape object. 
*/

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include<string>

namespace CAD
{
	class Shape
	{
	private:
		// State variables: 
		int m_id;								/* ID of current Shape object. */
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		Shape();								/* Default Constructor. */
		Shape(const Shape&);					/* Copy Constructor. */
		virtual ~Shape();						/* Destructor. */
		////////////////////////////
		// Accessors:
		////////////////////////////
		int ID() const;							/* Returns m_id. */
		////////////////////////////
		// Misc Methods:
		////////////////////////////
		virtual void Draw() const = 0;			/* Pure Virtual Memory Function. Makes the class abstract. */
		void Print() const;						/* Prints ToString(). */
		virtual std::string ToString() const;	/* Returns "ID: <m_id>". */
		////////////////////////////
		// Overloaded Operators:
		////////////////////////////
		Shape& operator=(const Shape&);			/* Assignment operator (with Shape). */
	};
}

#endif