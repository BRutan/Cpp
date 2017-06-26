/* BaseExcept.hpp
-Description:
	*Base class for all exception types in the Options namespace.
-State Variables/Objects:
	*string message: Stored message detailing exception.
-Member Functions:
	// Constructors/Destructor:
	*BaseExcept(const string&): Overloaded constructor. Set message. 
	*BaseExcept(const BaseExcept&): Copy constructor.
	*~BaseExcept():	Destructor.
	// Misc. Methods:
	*string Message() const: PVMF to make BaseExcept an abstract base class.
*/

#ifndef BASEEXCEPT_HPP
#define BASEEXCEPT_HPP
#include<string>


namespace Options
{
	namespace Exceptions
	{
		class BaseExcept
		{
		protected:
			////////////////////////////
			// State Variables/Objects:
			////////////////////////////
			std::string message;
		public:
			////////////////////////////
			// Constructors/Destructor:
			////////////////////////////
			BaseExcept(const std::string &in) : message(in)			/* Overloaded Constructor. Sets message. */
			{

			}
			BaseExcept(const BaseExcept &in) : message(in.message)  /* Copy Constructor. */
			{

			}
			virtual ~BaseExcept()									/* Destructor. */
			{

			}
			////////////////////////////
			// Misc. Methods:
			////////////////////////////
			virtual std::string Message() const = 0;				/* PVMF, makes class an abstract base class. */
			////////////////////////////
			// Overloaded Operators:
			////////////////////////////
			BaseExcept& operator=(const BaseExcept &in)				/* Assignment operator. */
			{
				if (this != &in)
				{
					message = in.message;
				}
				return *this;
			}
		};
	}
}


#endif
