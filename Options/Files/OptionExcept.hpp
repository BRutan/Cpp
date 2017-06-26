/* OptionExcept.hpp
-Description:
	*Derived exception class derived from BaseExcept specifically for Option base and derived classes (EuropeanOption, AmericanOption).
-Member Functions:
	// Constructors/Destructor:
	*OptionExcept(const string&): Overloaded constructor. Assign message to "message" string in base class.
	*OptionExcept(const OptionExcept&): Copy constructor. Copy state of passed OptionExcept object.
	*~OptionExcept(): Destructor. 
	// Misc. Methods
	*string Message() const: Return message embedded in base BaseExcept object.
*/

#ifndef OPTIONEXCEPT_HPP
#define OPTIONEXCEPT_HPP

#include<string>
#include"BaseExcept.hpp"

namespace Options
{
	namespace Exceptions
	{
		class OptionExcept : public BaseExcept
		{
		public:
			////////////////////////////
			// Constructors/Destructor:
			////////////////////////////
			OptionExcept(const std::string &in) : BaseExcept(in)	/* Overloaded Constructor. */
			{

			}
			OptionExcept(const OptionExcept &in) : BaseExcept(in)	/* Copy Constructor. */
			{

			}
			virtual ~OptionExcept()									/* Destructor. */
			{

			}
			////////////////////////////
			// Misc. Methods:
			////////////////////////////
			std::string Message() const							/* Return message detailingg exception.*/
			{
				return message;
			}
			////////////////////////////
			// Overloaded Operators:
			////////////////////////////
			OptionExcept& operator=(const OptionExcept &in)			/* Assignment Operator. */
			{
				if (this != &in)
				{
					BaseExcept::operator=(in);
				}
				return *this;
			}
		};
	}
}

#endif