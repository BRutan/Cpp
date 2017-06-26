/* Except.hpp
-Description:
	*



*/


#ifndef EXCEPT_HPP
#define EXCEPT_HPP

#include<string>

namespace Symboliq
{
	namespace Exceptions
	{
		class Except
		{
		private:
			///////////////////////////////
			// State Variables/Objects:
			///////////////////////////////
			std::string message;
		public:
			///////////////////////////////
			// Constructors/Destructor:
			///////////////////////////////
			Except(std::string message_in): message(message_in)
			{

			}
			Except(const Except &in) : message(in.message)
			{

			}
			virtual ~Except()
			{

			}
			///////////////////////////////
			// Misc. Methods:
			///////////////////////////////
			virtual std::string Message() const = 0;
			///////////////////////////////
			// Overloaded Operators:
			///////////////////////////////
			Except& operator=(const Except &in)
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