/* PolyLLException.cpp
Description:
	*Used as abstract base class for derived exceptions pertaining only to PolyLinkedList class.
Class Methods:


*/

#ifndef POLYLLEXCEPTION_HPP
#define POLYLLEXCEPTION_HPP

#include<string>
#include<vector>

namespace Symboliq
{
	namespace Exceptions
	{
		//////////////////////////////
		// Base Class:
		//////////////////////////////
		class PolyLLException
		{
		public:
			PolyLLException()											  // Default Constructor.
			{

			}
			virtual ~PolyLLException()									  // Destructor.
			{

			}
			virtual std::string GetMessage() const = 0;					  // Pure virtual memory function to be overwritten in derived classes.
			PolyLLException& operator=(const PolyLLException &in)		  // Assignment operator.
			{
				return *this;
			}
		};
		//////////////////////////////
		// Derived Classes:
		//////////////////////////////
		class PolyLLOOB : public PolyLLException
		{
		private:
			unsigned long long index;
		public:
			//////////////////////////////
			// Constructors/Destructor:
			//////////////////////////////
			PolyLLOOB(unsigned long long index_in) : index(index_in)
			{

			}
			PolyLLOOB(const PolyLLOOB &in) : index(in.index)
			{

			}
			virtual ~PolyLLOOB()
			{

			}
			//////////////////////////////
			// Misc. Methods:
			//////////////////////////////
			std::string GetMessage() const
			{
				std::strstream ss;
				ss << "Error: Index " << i << " is out of bounds. ";
				return ss.str();
			}
			//////////////////////////////
			// Overloaded Operators:
			//////////////////////////////
			PolyLLOOB& operator=(const PolyLLOOB &in)
			{
				if (this != &in)
				{
					index = in.index;
				}
				return *this;
			}
	}
}




#endif