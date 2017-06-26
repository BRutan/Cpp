/* MiscPreds.hpp
Description:
	*File contains predicate functors for use in Symboliq's class methods.
Predicate Classes:
	*WithinN(first, last): Used to determine if numeric type is within <N> units away
*/

#ifndef MISCPREDS_HPP
#define MISCPREDS_HPP

#include<cmath>

namespace Symboliq
{
	namespace Exceptions
	{
		class WithinN
		{
		private:
			unsigned long long N, checkVal;
		public:
			/////////////////////////////
			// Constructors/Destructor:
			/////////////////////////////
			WithinN(unsigned long long N_in) : N(N_in)			// Overloaded Constructor.
			{
				
			}
			explicit WithinN(unsigned long long N_in) : N(N_in) // Conversion Constructor.
			{

			}
			WithinN(const WithinN &in) : N(in.N)				// Copy Constructor.
			{

			}
			virtual ~WithinN()									// Destructor.
			{

			}
			/////////////////////////////
			// Accessors/Mutators:
			/////////////////////////////
			unsigned long long N()								// Access N.
			{
				return N;
			}
			void N(unsigned long long N_in)						// Mutate N.
			{
				N = N_in;
			}
			/////////////////////////////
			// Overloaded Operators:
			/////////////////////////////
			WithinN& operator=(const WithinN &in)				// Assignment operator.
			{
				if (this != &in)
				{
					N = in.N;
				}
				return *this;
			}
			bool operator()(unsigned long long compare)	// Functor operator overloading.
			{
				return compare - checkVal <= N || checkVal - compare <= N;
			}
		};
	}
}

#endif
