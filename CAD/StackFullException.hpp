/* StackFullException.hpp
Description:
	*StackFullException derived class for handling issues related to Push() function.
Methods:
	// Constructor/Destructor:
	*StackFullException(): Default constructor.
	*StackFullException(const StackException&): Copy constructor.
	*~StackFullException(): Destructor.
	// Misc. Methods:
	*string GetMessage() const: Return string detailing that Stack object is full, and thus 
	user can no longer push objects onto Stack object.
*/

#ifndef STACKFULLEXCEPTION_HPP
#define STACKFULLEXCEPTION_HPP

#include<string>
#include"StackException.hpp"

namespace Containers
{
	class StackFullException : public StackException
	{
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		StackFullException()									/* Default Constructor. */
		{

		}
		StackFullException(const StackFullException& except_in)	/* Copy Constructor. */
		{

		}
		virtual ~StackFullException()							/* Destructor. */
		{

		}
		////////////////////////////
		// Misc. Methods:
		////////////////////////////
		std::string GetMessage() const							/* Return string detailing exception (Stack is full). */
		{
			return "Error: Stack is full.";
		}
		////////////////////////////
		// Overloaded Operators:
		////////////////////////////
		StackFullException& operator=(const StackFullException &except_in)	/* Assignment operator. */
		{
			if (this != &except_in)
			{
				StackException::operator=(except_in);
			}
			return *this;
		}
	};
}

#endif