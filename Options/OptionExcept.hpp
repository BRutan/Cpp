/* OptionExcept.hpp
-Description:
	*
-State Variables:
	*
-Class Methods:
	// Constructors/Destructor:
	*
	*
	// Misc. Methods
	*
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
			std::string GetMessage() const							/* Return message detailingg exception.*/
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