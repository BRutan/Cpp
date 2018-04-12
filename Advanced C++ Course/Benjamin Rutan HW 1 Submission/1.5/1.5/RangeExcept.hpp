/* RangeExcept.hpp
-Description:

-Class Methods:
// Constructors/Destructor:

// Misc. Methods:

*/


#ifndef RANGEEXCEPT_HPP
#define RANGEEXCEPT_HPP

#include <string>
#include "Exception.hpp"

namespace Exceptions
{
	class RangeExcept : public Exception
	{
	public:
		//////////////////////////////
		// Constructors/Destructor
		//////////////////////////////
		RangeExcept(const std::string &message) noexcept : Exception(message)
		{

		}
		explicit RangeExcept(const RangeExcept &copy) noexcept : Exception(copy)
		{

		}
		RangeExcept(RangeExcept &&copy) noexcept : Exception(std::move(copy))
		{

		}
		virtual ~RangeExcept() noexcept
		{

		}
		//////////////////////////
		// Misc. Methods:
		//////////////////////////
		std::string GetMessage() const noexcept override
		{
			return this->message;
		}
		//////////////////////////
		// Overloaded Operators:
		//////////////////////////
		RangeExcept& operator=(const RangeExcept& exception_in) noexcept
		{
			if (this != &exception_in)
			{
				Exception::operator=(exception_in);
			}
			return *this;
		}
		RangeExcept& operator=(RangeExcept&& exception_in) noexcept
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
