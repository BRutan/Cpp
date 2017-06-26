/* GeneratorExcept.hpp
-Description:
	*Derived exception class from BaseExcept used for detailing issues with MeshGenerator class.
-Member Functions:
	// Constructors/Destructor:
	*GeneratorExcept(const string&): Overloaded constructor. Set message detailing issue.
	*GeneratorExcept(const GeneratorExcept&): Copy constructor.
	*~GeneratorExcept(): Destructor.
	// Misc. Methods:
	*string Message() const: Return message detailing issue.
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
			GeneratorExcept(const std::string &in) : BaseExcept(in) 	/* Overloaded Constructor */
			{

			}
			GeneratorExcept(const GeneratorExcept &in) : BaseExcept(in) /* Copy Constructor */
			{

			}
			virtual ~GeneratorExcept() 									/* Destructor. */
			{

			}
			////////////////////////////
			// Misc. Methods:
			////////////////////////////
			std::string Message() const 							   /* Return message detailing issue with MeshGenerator object. */
			{
				return message;
			}
			////////////////////////////
			// Overloaded Operators:
			////////////////////////////
			GeneratorExcept& operator=(const GeneratorExcept &in)	   /* Assignment Operator */
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
