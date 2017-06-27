/* StackException.hpp
Description:
	*StackException base class for handling Stack object exceptions.
Methods:
	// Constructor/Destructor:
	*StackException(): Default constructor.
	*StackException(const StackException&): Copy constructor.
	*~StackException(): Destructor.
	// Misc. Methods:
	*virtual string GetMessage() const: Pure virtual memory function, makes class abstract. 
*/

#ifndef STACKEXCEPTION_HPP
#define STACKEXCEPTION_HPP

#include<string>

namespace Containers
{
	class StackException
	{
	public:	
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		StackException()								/* Default Constructor. */
		{

		}
		StackException(const StackException& except_in) /* Copy Constructor. */
		{

		}
		virtual ~StackException()						/* Destructor. */
		{

		}
		////////////////////////////
		// Misc. Methods:
		////////////////////////////
		virtual std::string GetMessage() const = 0;		/* Pure virtual memory function. Makes StackException an abstract base class. */
		////////////////////////////
		// Overloaded Operators:
		////////////////////////////
		StackException& operator=(const StackException &except_in)	/* Assignment operator. */
		{
			return *this;
		}
	};
}

#endif