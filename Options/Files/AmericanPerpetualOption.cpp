/* AmericanPerpetualOption.cpp
-Description:
	*Derived class from Option class that values American Perpetual Options, options that do not expire and
	can be exercised at any time.
-Member Functions:
	// Constructors/Destructor:
	*AmericanPerpetualOption(double, double, double, double, double, bool): Overloaded constructor. Set all parameters and type ("true" == Call, false == Put).
	*AmericanPerpetualOption(vonst AmericanPerpetualOption&): Copy constructor.
	*~AmericanPerpetualOption(): Destructor.
	// Misc. Methods:
	*double Y1() const: Calculate and return y1 for use in calculating price.
	*double Y2() const: Calculate and return y2 for use in calculating price.
	*double Price() const: Calculate price of American Perpetual Option.
*/

#include<cmath>
#include"AmericanPerpetualOption.hpp"
#include"Option.hpp"
#include"OptionExcept.hpp"

namespace Options
{
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	AmericanPerpetualOption::AmericanPerpetualOption(double s, double k, double b, double r, double sigma, bool isCall): /* Overloaded Constructor. Set all parameters' values. */
		Option(10000000000.00, s, k, b, r, sigma, isCall) // Set t to extremely high value since option does not expire.
	{

	}
	AmericanPerpetualOption::AmericanPerpetualOption(const AmericanPerpetualOption &in): Option(in) /* Copy Constructor. */
	{

	}
	AmericanPerpetualOption::~AmericanPerpetualOption()		/* Destructor. */
	{

	}
	////////////////////////////
	// Misc. Methods:
	////////////////////////////
	double AmericanPerpetualOption::Y1() const				/* Calculate y1 for use in Price(). */
	{ // y1 = 1/2 - b / sigma^2 + sqrt[(b / sigma^2 - 1/2)^2 + 2r / sigma^2] 
		double y1 = .5 - (Param("b") / pow(Param("sigma"), 2.0));
		y1 += std::sqrt(pow(Param("b") / pow(Param("sigma"), 2.0) - .5, 2.0) + 2.0 * (Param("r") / pow(Param("sigma"), 2.0)));
		return y1;
	}
	double AmericanPerpetualOption::Y2() const				/* Calculate y2 for use in Price(). */
	{ // y2 = 1/2 - b / sigma^2 - sqrt[(b / sigma^2 - 1/2)^2 + 2r / sigma^2]
		double y2 = .5 - Param("b") / pow(Param("sigma"), 2);
		y2 -= std::sqrt(pow(Param("b") / pow(Param("sigma"), 2) - .5, 2.0) + 2.0 * (Param("r") / pow(Param("sigma"), 2.0)));
		return y2;
	}
	double AmericanPerpetualOption::Price() const			/* Compute exact price of American Perpetual Option. */
	{
		if (Type()) // For Call option.
		{
			return Param("k") / (Y1() - 1.0) * pow((Y1() - 1.0) / Y1() * Param("s") / Param("k"), Y1());
		}
		else // For Put option.
		{
			return Param("k") / (1.0 - Y2()) * pow((Y2() - 1.0) / Y2() * Param("s") / Param("k"), Y2());
		}
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	AmericanPerpetualOption& AmericanPerpetualOption::operator=(const AmericanPerpetualOption &in) /* Assignment Operator. */
	{
		if (this != &in)
		{
			Option::operator=(in);
		}
		return *this;
	}
}