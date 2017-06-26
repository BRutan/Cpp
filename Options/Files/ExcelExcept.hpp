/* ExcelExcept.hpp
-Description:
	*Derived exception class from BaseExcept base class to inform user of issue with writing Option data to
	Excel.
-Member Functions:
	// Constructors/Destructor:
	*ExcelExcept(const string&): Overloaded constructor. Set value of message state object.
	*ExcelExcept(const ExcelExceptn&): Copy constructor.
	*~ExcelExcept(): Destructor.
	// Misc. Methods:
	string GetMessage() const: Return string detailing issue.
*/
#ifndef EXCELEXCEPT_HPP
#define EXCELEXCEPT_HPP
#undef GetMessage // Undefine GetMessage preprocessor macro defined in WinUser.h to disambiguate with method in Exception classes.

#include <string>
#include "BaseExcept.hpp"

namespace Options
{
	namespace Exceptions
	{
		class ExcelExcept : public BaseExcept 
		{
		public:
			////////////////////////////
			// Constructors/Destructor:
			////////////////////////////
			ExcelExcept(const std::string &message_in) : BaseExcept(message_in) /* Overloaded Constructor. */
			{

			}
			ExcelExcept(const ExcelExcept &in) : BaseExcept(in)					/* Copy Constructor. */
			{

			}
			virtual ~ExcelExcept()												/* Destructor. */
			{

			}
			////////////////////////////
			// Misc. Methods:
			////////////////////////////
			std::string Message() const										/* Return message detailing issue. */
			{
				return message;
			}
			////////////////////////////
			// Overloaded Operators:
			////////////////////////////
			ExcelExcept& operator=(const ExcelExcept &in)						/* Assignment operator. */
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