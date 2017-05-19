/* StackEmptyException.hpp 
Description:
	*StackEmptyException derived class for handling issues related to Pop() function.
Methods:
	// Constructor/Destructor:
	*StackEmptyException(): Default constructor.
	*StackEmptyException(const StackException&): Copy constructor.
	*~StackEmptyException(): Destructor.
	// Misc. Methods:
	*string GetMessage() const: Return string detailing that Stack object is empty, and thus 
	user can no longer pop objects off of Stack object.
*/

#ifndef STACKEMPTYEXCEPTION_HPP
#define STACKEMPTYEXCEPTION_HPP

#include<string>
#include"StackException.hpp"

namespace Containers
{
	class StackEmptyException : public StackException
	{
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		StackEmptyException()										/* Default Constructor. */
		{

		}
		StackEmptyException(const StackEmptyException& except_in)	/* Copy Constructor. */
		{

		}
		virtual ~StackEmptyException()								/* Destructor. */
		{

		}
		////////////////////////////
		// Misc. Methods:
		////////////////////////////
		std::string GetMessage() const								/* Return string detailing exception (Stack is empty). */
		{
			return "Error: Stack is empty.";
		}
		////////////////////////////
		// Overloaded Operators:
		////////////////////////////
		StackEmptyException& operator=(const StackEmptyException &except_in)	/* Assignment operator. */
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

