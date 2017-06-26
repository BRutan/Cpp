/* AmericanPerpetualOption.hpp
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

#ifndef AMERICANPERPETUALOPTION_HPP
#define AMERICANPERPETUALOPTION_HPP

#include"Option.hpp"

namespace Options
{
	class AmericanPerpetualOption : public Option
	{
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		AmericanPerpetualOption(double s, double k, double b, double r, double sigma, bool isCall); /* Overloaded Constructor. */
		AmericanPerpetualOption(const AmericanPerpetualOption&);		/* Copy Constructor. */
		virtual ~AmericanPerpetualOption(); /* Destructor. */
		////////////////////////////
		// Misc. Methods:
		////////////////////////////
		double Y1() const;				/* Calculate y1 for use in Price(). */
		double Y2() const;				/* Calculate y2 for use in Price(). */
		double Price() const;			/* Compute exact price of American Perpetual Option. */
		////////////////////////////
		// Overloaded Operators:
		////////////////////////////
		AmericanPerpetualOption& operator=(const AmericanPerpetualOption&); /* Assignment Operator. */
	};
}

#endif