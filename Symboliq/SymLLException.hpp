/* SymLLException.hpp


*/

#ifndef SYMLLEXCEPTION_HPP
#define SYMLLEXCEPTION_HPP

#include<string>
namespace Symboliq
{
	namespace Exceptions
	{
		class SymLLException
		{
		public:
			SymLLException()										// Default Constructor.
			{

			}
			virtual ~SymLLException()								// Destructor.
			{

			}
			virtual std::string GetMessage() const = 0;				// Pure virtual memory function to be overwritten in derived classes.
			SymLLException& operator=(const SymLLException &in)		// Assignment operator.
			{
				return *this;
			}
		};
	}
}



#endif