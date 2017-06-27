/* MonteCarloExcept.hpp
-Description:
	*Declare and define exception for the MonteCarlo class, derived from BaseExcept.
-Class Methods:
	// Constructors/Destructor:
	*MonteCarloExcept(const &string): Overloaded constructor. Set the message to return to user.
	*MonteCarloExcept(const MonteCarloExcept&): Copy constructor.
	*~MonteCarloExcept(): Destructor.
	// Misc. Methods:
	string Message() const: Return the error message to user.
*/

#ifndef MONTECARLOEXCEPT_HPP
#define MONTECARLOEXCEPT_HPP

#include <string>
#include "BaseExcept.hpp"

namespace Options
{
	namespace Exceptions
	{
		class MonteCarloExcept : public BaseExcept
		{
		public:
			///////////////////////////
			// Constructors/Destructor:
			///////////////////////////
			MonteCarloExcept(const std::string &in) : BaseExcept(in)			/* Overloaded Constructor. */
			{

			}
			MonteCarloExcept(const MonteCarloExcept &in) : BaseExcept(in)       /* Copy Constructor. */
			{

			}
			~MonteCarloExcept()													/* Destructor. */
			{

			}
			///////////////////////////
			// Misc. Methods:
			///////////////////////////
			std::string Message() const											/* Return error message to user. */
			{
				return message;
			}
			///////////////////////////
			// Overloaded Operators:
			///////////////////////////
			MonteCarloExcept& operator=(const MonteCarloExcept &in)				/* Assignment Operator. */
			{
				if(this != &in)
				{
					BaseExcept::operator=(in);
				}
				return *this;
			}
		};
	}
}



#endif
