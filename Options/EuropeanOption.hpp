/* EuropeanOption.hpp
-Description:
	*Derived option class that uses Black-Scholes formula to give exact price.
-Variable/Object Catalogue:
	*normal_distribution<> normDist: Normal Distribution RNG object.
-Member Functions:
	// Constructors/Destructor:
	*EuropeanOption(): Default constructor. Set all parameters to 0.
	*EuropeanOption(double, double, double, double, double, bool): Set parameters to corresponding passed values.
	*EuropeanOption(const EuropeanOption&): Copy constructor.
	*~EuropeanOption(): Destructor.
	// Misc. Methods:
	*double D1() const: Return "d1", Z-score used in Black-Scholes model.
	*double D2() const: Return "d2", Z-score used in Black-Scholes model.
	*double Price() const: Return price using Black-Scholes formula.
	*double Delta() const: Return change in Price given change in s.
	*double Gamma() const: Return 2nd order change in Price given change in s.
	*double Theta() const: Return change in Price given change in t.
	*double Vega() const: Return change in Price given change in sigma.
*/

#ifndef EUROPEANOPTION_HPP
#define EUROPEANOPTION_HPP

#include<boost\math\distributions\normal.hpp>
#include<cmath>
#include<string>
#include"Option.hpp"

namespace Options 
{
	class EuropeanOption : public Option
	{
	private:
		////////////////////////////
		// State Variables:
		////////////////////////////
		boost::math::normal_distribution<> normDist;	  /* Standard normal distribution (N(0,1)) for use in calculating price and greeks. */
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		EuropeanOption(double t, double s, double k, double b, double r, double sigma, bool isCall);	/* Overloaded Constructor. Set all parameters. */
		EuropeanOption(const EuropeanOption&);			  /* Copy Constructor. */
		virtual ~EuropeanOption();						  /* Destructor. */
		////////////////////////////
		// Misc. Methods:
		////////////////////////////
		double AltPrice() const;						  /* Return price of alternative type using Put-Call Parity. */
		double D1() const;								  /* Calculate Z-Score used in Black-Scholes formula. */
		double D2() const;								  /* Calculate Z-Score used in Black-Scholes formula. */
		double Price() const;							  /* Calculate exact price using Black-Scholes formula (where b = r). */
		// Greeks:
		double Delta() const;							  /* Change in price with respect to s (1st order). */
		double Gamma() const;							  /* Change in price with respect to s (2nd order). */
		double Theta() const;							  /* Change in price with respect to t (1st order). */
		double Vega() const;							  /* Change in price with respect to sigma (1st order). */
		////////////////////////////
		// Overloaded Operators: 
		////////////////////////////
		EuropeanOption& operator=(const EuropeanOption&); /* Assignment Operator. */
	};
}
#endif