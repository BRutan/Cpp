/* EuropeanOption.cpp
-Description:
	*Derived option class that uses Black-Scholes formula to give exact price.
-Variable/Object Catalogue:
	*normal_distribution<> normDist: Normal Distribution RNG object.
-Member Functions:
	// Constructors/Destructor:
	*EuropeanOption(double, double, double, double, double, bool): Set parameters to corresponding passed values.
	*EuropeanOption(const EuropeanOption&): Copy constructor.
	*~EuropeanOption(): Destructor.
	// Misc. Methods:
	*double AltPrice() const: Return price of alternate form of option using Put-Call Parity.
	*double D1() const: Return "d1", Z-score used in Black-Scholes model.
	*double D2() const: Return "d2", Z-score used in Black-Scholes model.
	*double Price() const: Return price using Black-Scholes formula.
	*double Delta() const: Return change in Price given change in s.
	*double Gamma() const: Return 2nd order change in Price given change in s.
*/

#include <boost\math\distributions.hpp>
#include <string>
#include <iostream>
#include <strstream>
#include "EuropeanOption.hpp"
#include "OptionExcept.hpp"

namespace Options
{
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	EuropeanOption::EuropeanOption(double t, double s, double k, double b, double r, double sigma, bool isCall) :	/* Overloaded Constructor. Set all values of */
	Option(t, s, k, b, r, sigma, isCall) 
	{

	}
	EuropeanOption::EuropeanOption(const EuropeanOption &in) : Option(in)	/* Copy Constructor. */
	{

	}
	EuropeanOption::~EuropeanOption()					/* Destructor. */
	{

	}
	//////////////////////////
	// Misc. Methods:
	//////////////////////////
	double EuropeanOption::AltPrice() const			    /* Return price of alternative type using Put-Call Parity. */
	{
		if (Type()) // Return corresponding price of Put option if option is Call using Put-Call Parity.
		{
			return Price() + Param("k") * exp(-Param("r") * Param("t")) - Param("s");
		}
		else		// Return corresponding price of corresponding Call option if option is Put.
		{
			return Price() - Param("k") * exp(-Param("r") * Param("t")) + Param("s");
		}
	}
	double EuropeanOption::D1()	const					/* Calculate Z-Score used in Black-Scholes formula. */
	{
		// d1 = (ln(s/k) + (b + sigma^2/2) * t) / (sigma * sqrt(t))
		return (log(Param("s") / Param("k")) + (Param("b") + .5 * pow(Param("sigma"), 2)) * Param("t")) / (Param("sigma") * sqrt(Param("t")));
	}
	double EuropeanOption::D2() const					/* Calculate Z-Score used in Black-Scholes formula. */
	{
		// d2 = d1 - sigma * sqrt(t)
		return  D1() - Param("sigma") * sqrt(Param("t"));
	}
	double EuropeanOption::Price() const				/* Return price of option. */
	{
		try
		{
			if (Type())
			{
				return boost::math::cdf(normDist, D1()) * Param("s") * std::exp((Param("b") - Param("r")) * Param("t")) - boost::math::cdf(normDist, D2()) * Param("k") * std::exp(-Param("r") * Param("t"));
			}
			else
			{
				return boost::math::cdf(normDist, -D2()) * Param("k") * std::exp(-Param("r") * Param("t")) - boost::math::cdf(normDist, -D1()) * Param("s") * std::exp((Param("b") - Param("r")) * Param("t"));
			}
		}
		catch (...)
		{
			throw Exceptions::OptionExcept("EuropeanOption::Price() Error: Unhandled exception. ");
		}
	}
	// Greeks:
	double EuropeanOption::Delta() const				/* Change in price with respect to s (1st order). */
	{
		if (Type())
		{
			return boost::math::cdf(normDist, D1()) * std::exp((Param("b") - Param("r")) * Param("t"));  // dC/dS = N(d1) * e^((b - r)t).
		}
		else
		{
			// Using Put-Call Parity, can see that dP/dS = dC/dS - e^((b - r))t = (N(d1) - 1) * e^((b - r)t):
			return (boost::math::cdf(normDist, D1()) - 1) * std::exp((Param("b") - Param("r")) * Param("t"));
		}
	}
	double EuropeanOption::Gamma() const				/* Change in price with respect to s (2nd order). */
	{
		// Following Put-Call Parity, we see that Gamma is the same for both Puts and Calls ((d/dS)^2P = (d/dS)^2C):
		return boost::math::cdf(normDist, D1()) / (Param("s") * Param("sigma") * sqrt(Param("t"))) * exp((Param("b") - Param("r")) * Param("t"));
	}
	//////////////////////////
	// Overloaded Operators: 
	//////////////////////////
	EuropeanOption& EuropeanOption::operator=(const EuropeanOption &in) /* Assignment Operator. */
	{
		if (this != &in)
		{
			Option::operator=(in);
		}
		return *this;
	}
}