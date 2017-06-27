/* OutOfBoundsException.hpp
Description:
	*Declare and define OutOfBoundsException class, exception that describes an Out of Bounds error.
State Variables/Objects:
	*int m_index: contains Array object index where exception occurred.
Class Methods:
	// Constructors/Destructor: 
	*OutOfBoundsException(int): Overloaded constructor, sets m_index state variable to passed integer.
	*OutOfBoundsException(const OutOfBoundsException&): Copy constructor, sets m_index to passed exception's m_index copy.
	*~OutOfBoundsException(): Destructor.
	// Misc. Methods:
	*string GetMessage() const: Output statement regarding out of bounds exception to stdout.
*/

#ifndef OUTOFBOUNDSEXCEPTION_HPP
#define OUTOFBOUNDSEXCEPTION_HPP

#include<sstream>
#include<string>
#include"ArrayException.hpp"

namespace Containers
{
	class OutOfBoundsException : public ArrayException
	{
	private:
		int m_index;
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		OutOfBoundsException(int index_in) : ArrayException(), m_index(index_in) /* Overloaded Constructor. */
		{

		}
		OutOfBoundsException(const OutOfBoundsException &except_in) : ArrayException(except_in), m_index(except_in.m_index) /* Copy Constructor. */
		{

		}
		~OutOfBoundsException()						/* Destructor. */
		{

		}
		//////////////////////////
		// Misc. Methods:
		//////////////////////////
		std::string GetMessage() const				/* Return message detailing which index is out of bounds. */
		{
			std::stringstream ss;
			ss << "Index " << m_index << " is out of bounds. ";

			return ss.str();
		}
		//////////////////////////
		// Overloaded Operators:
		//////////////////////////
		OutOfBoundsException& operator=(const OutOfBoundsException &except_in) /* Assignment operator. */
		{
			// Preclude self-assignment:
			if (this != &except_in)
			{
				m_index = except_in.m_index;
				ArrayException::operator=(except_in);
			}
			return *this;
		}
	};
}


#endif
