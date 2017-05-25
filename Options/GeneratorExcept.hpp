/* GeneratorExcept.hpp
-Description:
	*Derived exception class from BaseExcept use for detailing issues with MeshGenerator class.
-Member Functions:
	// Constructors/Destructor:
	*GeneratorExcept(const std::string&): Overloaded constructor. Set message detailing issue.
	*GeneratorExcept(const GeneratorExcept&): Copy constructor.
	*~GeneratorExcept(): Destructor.
	// Misc. Methods:
	*string GetMessage() const: Return message detailing issue.
*/

#ifndef GENERATOREXCEPT_HPP
#define GENERATOREXCEPT_HPP
#include"BaseExcept.hpp"

namespace Options
{
	namespace Exceptions
	{
		class GeneratorExcept : public BaseExcept
		{
		public:
			////////////////////////////
			// Constructors/Destructor:
			////////////////////////////
			GeneratorExcept(const std::string &in) : BaseExcept(in)
			{

			}
			GeneratorExcept(const GeneratorExcept &in) : BaseExcept(in)
			{

			}
			virtual ~GeneratorExcept()
			{

			}
			////////////////////////////
			// Misc. Methods:
			////////////////////////////
			std::string GetMessage() const
			{
				return message;
			}
			////////////////////////////
			// Overloaded Operators:
			////////////////////////////
			GeneratorExcept& operator=(const GeneratorExcept &in)
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
