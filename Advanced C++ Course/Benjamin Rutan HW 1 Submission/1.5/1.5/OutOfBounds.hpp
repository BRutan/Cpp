/* OutOfBounds.hpp
-Description:

-Class Methods:
// Constructors/Destructor:

// Misc. Methods:

*/


#ifndef OUTOFBOUNDS_HPP
#define OUTOFBOUNDS_HPP

#include <string>
#include <utility>
#include "Exception.hpp"

namespace Exceptions
{
	class OutOfBounds : public Exception
	{
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		OutOfBounds(const std::string &message_in) noexcept : Exception(message_in)
		{

		}
		explicit OutOfBounds(const OutOfBounds &copy) noexcept : Exception(copy)
		{

		}
		OutOfBounds(OutOfBounds &&copy) noexcept : Exception(std::move(copy))
		{

		}
		virtual ~OutOfBounds() noexcept
		{

		}
		//////////////////////////
		// Misc. Methods:
		//////////////////////////
		std::string GetMessage() const noexcept
		{
			return Exception::message;
		}
		//////////////////////////
		// Overloaded Operators:
		//////////////////////////
		OutOfBounds& operator=(const OutOfBounds& exception_in) noexcept
		{
			if (this != &exception_in)
			{
				Exception::operator=(exception_in);
			}
			return *this;
		}
		OutOfBounds& operator=(OutOfBounds &&exception_in) noexcept
		{
			if (this != &exception_in)
			{
				Exception::operator=(exception_in);
			}
			return *this;
		}
	};
}


#endif
