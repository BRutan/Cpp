/* LessThan.hpp
Description:
	*Predicate class that returns true if passed value is less than stored double.
State Variables:
	*double stored: Value to be used in comparison.
Member Functions:
	// Constructors/Destructor:
	*LessThan(): Default constructor. Set stored to 0.
	*LessThan(double): Overloaded constructor. Set stored to passed double value.
	*LessThan(const LessThan&): Copy constructor.
	*~LessThan(): Destructor.
*/
#ifndef LESSTHAN_HPP
#define LESSTHAN_HPP

class LessThan
{
private:
	////////////////////////////
	// State Variables:
	////////////////////////////
	double stored;
public:
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	LessThan() : stored(0)						// Default Constructor.
	{

	}
	LessThan(double double_in) : stored(double_in)			// Overloaded Constructor.
	{

	}
	LessThan(const LessThan &lt_in) : stored(lt_in.stored)		// Copy Constructor.
	{

	}
	virtual ~LessThan()						// Destructor.
	{

	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	LessThan& operator=(const LessThan &lt_in)			// Assignment operator.
	{
		if (this != &lt_in)
		{
			stored = lt_in.stored;
		}
		return *this;
	}
	bool operator()(double in)					// Overloaded parentheses operator (functor operator).
	{
		return in < stored;
	}
};
#endif
