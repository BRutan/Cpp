/* ArrayException.hpp
Description:
	*Declare and define abstract ArrayException base class for use in derived classes (OutOfBoundsException).
Class Methods:
	// Constructors/Destructor:
	*ArrayException(): Default constructor. Does nothing since does not have state variables/objects.
	*ArrayException(const ArrayException&): Copy constructor. Does nothing since does not have state variables/objects.
	*~ArrayException(): Destructor.
	// Misc. Methods:
	*virtual string GetMessage() const: Pure virtual memory function to make ArrayException an abstract class.
*/

#ifndef ARRAYEXCEPTION_HPP
#define ARRAYEXCEPTION_HPP
#include<string>

namespace Containers
{
	class ArrayException
	{
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		ArrayException()								/* Default Constructor. */
		{

		}
		ArrayException(const ArrayException& except_in) /* Copy Constructor. */
		{

		}
		virtual ~ArrayException()
		{

		}
		//////////////////////////
		// Misc. Methods:
		//////////////////////////
		virtual std::string GetMessage() const = 0;		/* Pure virtual memory function, makes ArrayException an abstract class. */
		//////////////////////////
		// Overloaded Operators:
		//////////////////////////
		ArrayException& operator=(const ArrayException &array_in) /* Assignment operator. Does nothing since class has no data members. */
		{
			return *this;
		}
	};
}

#endif