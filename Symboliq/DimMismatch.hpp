/* DimMismatch.hpp // TODO 5.7.2017


*/

#ifndef DIMMISMATCH_HPP
#define DIMMISMATCH_HPP

#include<string>
#include"PolynomialException.hpp"

namespace Symboliq
{
	namespace Exceptions
	{
		class DimMismatch : public PolynomialException 
		{
		private:
			unsigned long long dim1, dim2;
		public:
			////////////////////////////////
			// Constructors/Destructor:
			////////////////////////////////
			DimMismatch(unsigned long long dim1_in, unsigned long long dim2_in) : dim1(dim1_in), dim2(dim2_in)
			{

			}
			virtual ~DimMismatch()
			{

			}
			////////////////////////////////
			// Accessors:
			////////////////////////////////
			unsigned long long Dim_1() const
			{
				return dim1;
			}
			unsigned long long Dim_2() const
			{
				return dim2;
			}
			////////////////////////////////
			// Misc. Methods:
			////////////////////////////////
			std::string GetMessage() const // TODO
			{
				return "Error: Dimension mismatch ....";
			}
			////////////////////////////////
			// Misc. Methods:
			////////////////////////////////
			DimMismatch& operator=(const DimMismatch &in)
			{
				if (this != &in)
				{
					dim1 = in.dim1;
					dim2 = in.dim2;
				}
				return *this;
			}
		};
	}
}

#endif