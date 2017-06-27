/* SizeMismatch.hpp
Description:
	*Derived exception class from ArrayException that details size mismatch following an attempted binary operation using 
	derived objects of Array class.
State Variables/Objects:
	*unsigned int leftSize, rightSize: stores the sizes of the left and right operands in binary operation.
Member Functions:
	// Constructors/Destructor:
	*SizeMismatch(): Default constructor.
	*SizeMismatch(unsigned int, unsigned int): Overloaded constructor. Sets leftSize and rightSize respectively.	
	// Misc. Methods:
	string GetMessage() const: Return string description of exception, detailing the mismatched sizes.
*/

#ifndef SIZEMISMATCH_HPP
#define SIZEMISMATCH_HPP

#include"ArrayException.hpp"
#include<string>
#include<sstream>

namespace Containers
{
	class SizeMismatch : public ArrayException
	{
	private:
		unsigned int leftSize, rightSize;
		std::string operatorName;
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		SizeMismatch(unsigned int lSize_in, unsigned int rSize_in, std::string opName_in): ArrayException(), /* Overloaded Constructor. */
		leftSize(lSize_in), rightSize(rSize_in), operatorName(opName_in)	
		{

		}
		SizeMismatch(const SizeMismatch& except_in): ArrayException(), leftSize(except_in.leftSize),	     /* Copy Constructor. */
		rightSize(except_in.rightSize), operatorName(except_in.operatorName)	   
		{

		}
		virtual ~SizeMismatch()											/* Destructor. */
		{

		}
		////////////////////////////
		// Misc. Methods:
		////////////////////////////
		std::string GetMessage() const							/* Give description of exception. */
		{
			std::stringstream ss;
			ss << "Left Array's size (" << leftSize << ") does not equal Right Array's size (" << rightSize << "). ";
			ss << operatorName << " cancelled. ";
			return ss.str();
		}
		////////////////////////////
		// Overloaded Operators:
		////////////////////////////
		SizeMismatch& operator=(const SizeMismatch& except_in)	/* Assignment operator. */
		{
			// Preclude self-assignment:
			if (this != &except_in)
			{
				leftSize = except_in.leftSize;
				rightSize = except_in.rightSize;
				ArrayException::operator=(except_in);
			}
			return *this;
		}
	};
}


#endif