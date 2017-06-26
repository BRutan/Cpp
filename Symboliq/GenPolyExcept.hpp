/*

*/

#ifndef GENPOLYEXCEPT_HPP
#define GENPOLYEXCEPT_HPP

#include"PolynomialException.hpp"
namespace Symboliq
{
	namespace Exceptions
	{
		class GenPolyExcept : public PolynomialException
		{
		private:
			////////////////////////////////
			// State Variables:
			////////////////////////////////
			std::string message;
		public:
			////////////////////////////////
			// Constructors/Destructor:
			////////////////////////////////
			GenPolyExcept(const std::string &in) : message(in)
			{

			}
			GenPolyExcept(const GenPolyExcept &in) : message(in.message)
			{

			}
			////////////////////////////////
			// Misc. Methods:
			////////////////////////////////
			std::string GetMessage() const
			{
				return message;
			}
			////////////////////////////////
			// Overloaded Operators:
			////////////////////////////////
			GenPolyExcept& operator=(const GenPolyExcept &in)
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