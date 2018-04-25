/* Exception.hpp
Description:
	* Exception base class for use in other classes in this exercise.
Class Methods:
	// Constructors/Destructor:
	Exception(const Exception&): explicit copy constructor. Assigns message using passed Exception's message.
	Exception(Exception&& exception_in): move copy constructor.
	Exception(const string&): overloaded constructor. Assigns message to passed message.
	~Exception(): destructor.
	// Getters:
	string GetMessage() const: return stored message. PVMF to be overloaded in derived exceptions.
	// Setters:
	void SetMessage(const string&): assign stored message to passed message.
	// Overloaded Operators:
	Exception& operator=(const Exception&): assignment operator.
	Exception& operator=(Exception&&): move assignment operator.
*/
#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

namespace Exceptions
{
	class Exception
	{
	protected:
		std::string message;
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		explicit Exception(const Exception& exception_in) noexcept : message(exception_in.message)					/* Explicit copy constructor. */
		{

		}
		Exception(Exception&& exception_in) noexcept : message(std::move(exception_in.message))						/* Move copy constructor. */
		{

		}
		Exception(const std::string &message_in) noexcept : message(message_in)										/* Overloaded constructor. */
		{

		}
		virtual ~Exception() noexcept																				/* Destructor. */
		{

		}
		//////////////////////////
		// Misc. Methods:
		//////////////////////////
		virtual std::string GetMessage() const noexcept = 0;														/* PVMF to make Exception the base class to all derived exception objects. */
		void SetMessage(const std::string &message_in) noexcept														/* Set the member message. */
		{
			this->message = message_in;
		}
		//////////////////////////
		// Overloaded Operators:
		//////////////////////////
		Exception& operator=(const Exception& exception_in) noexcept												/* Assignment operator. */
		{
			if (this != &exception_in)
			{
				this->message = exception_in.message;
			}
			return *this;
		}
		Exception& operator=(Exception&& exception_in) noexcept
		{
			if (this != &exception_in)
			{
				this->message = std::move(exception_in.message);
			}
			return *this;
		}
	};
}

#endif
