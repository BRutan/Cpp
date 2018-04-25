/* SizeExcept.hpp
Description:
	* Derived exception class to denote a container is too small or large.
Member Functions:
	// Constructors/Destructor:
	* SizeExcept(const string&): overloaded constructor. Set the message to display to user.
	* SizeExcept(const SizeExcept&): copy constructor. 
	* SizeExcept(SizeExcept&&): move copy constructor.
	* ~SizeExcept(): destructor.
	// Misc. Functions:
	string GetMessage() const: return the error message.
	// Overloaded Operators:
	SizeExcept& operator=(const SizeExcept&): assignment operator.
*/



#ifndef SIZEEXCEPT_HPP
#define SIZEEXCEPT_HPP

#include <string>
#include <utility>
#include "Exception.hpp"

namespace Exceptions
{
	class SizeExcept : public Exception
	{
	public:
		//////////////////////////////
		// Constructors/Destructor
		//////////////////////////////
		SizeExcept(const std::string &message) noexcept : Exception(message)
		{
			
		}
		explicit SizeExcept(const SizeExcept &copy) noexcept : Exception(copy)
		{

		}
		SizeExcept(SizeExcept &&copy) noexcept : Exception(std::move(copy))
		{

		}
		virtual ~SizeExcept() noexcept override
		{

		}
		//////////////////////////
		// Misc. Methods:
		//////////////////////////
		std::string GetMessage() const noexcept override
		{
			return message;
		}
		//////////////////////////
		// Overloaded Operators:
		//////////////////////////
		SizeExcept& operator=(const SizeExcept& exception_in) noexcept
		{
			if (this != &exception_in)
			{
				Exception::operator=(exception_in);
			}
			return *this;
		}
		SizeExcept& operator=(SizeExcept&& exception_in) noexcept
		{
			if (this != &exception_in)
			{
				Exception::operator=(std::move(exception_in));
			}
			return *this;
		}
	};
}


#endif
