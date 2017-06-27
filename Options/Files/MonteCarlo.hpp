/* MonteCarlo.hpp
-Description:
	*Declare and define MonteCarlo template class that calculates the price of a financial option using the Euler-Maruyama scheme.
-State Objects:
	*variate_generator rng: Boost implemented normal random number generator for Monte Carlo path generation.
-Class Methods:
	// Constructors/Destructors:
	*MonteCarlo(double t, double s, double k, double b, double r, double sigma, unsigned long NSIM, unsigned long NT, bool isCall): Overloaded Constructor.
	*MonteCarlo(const MonteCarlo&): Copy constructor. 
	*~MonteCarlo(): Destructor.
	// Accessors:
	*unsigned long NSIM() const: Return the number of trials to be run in Monte Carlo.
	*unsigned long NT() const: Return number of sub-intervals in time to be used in generating each path.
	// Mutators:
	*void NSIM(unsigned long): Set number of trials. 
	*void NT(unsigned long): Set number of time sub-intervals.
	// Misc. Methods:
	*double Price() const: Calculate price of associated option using Monte Carlo method with Euler-Maruyama scheme. 
*/
#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include <boost/random/variate_generator.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/math/distributions/normal.hpp>
#include <cmath>
#include <string>
#include <vector>
#include "MonteCarlo.hpp"
#include "MonteCarloExcept.hpp"
#include "Option.hpp"
#include "OptionExcept.hpp"

namespace Options
{
	class MonteCarlo : public Option
	{
	private:
		////////////////////////////
		// State Variables/Objects:
		////////////////////////////
		boost::variate_generator<boost::mt19937, boost::math::normal_distribution<double> > *mainRNG;	/* Random number generator for Monte Carlo path generation. */
		unsigned long nSIM, nT;									/* Number of trials and time intervals for price generator. */
	public:
		////////////////////////////
		// Constructors/Destructor:
		////////////////////////////
		MonteCarlo(double t, double s, double k, double b, double r, double sigma, unsigned long NSIM, unsigned long NT, bool isCall); /* Overloaded Constructor. Set all parameters AND set number of time intervals and simulations to run. */
		MonteCarlo(const MonteCarlo &in);						/* Copy Constructor. */
		virtual ~MonteCarlo();									/* Destructor. */
		////////////////////////////
		// Accessors:
		////////////////////////////
		unsigned long NSIM() const;								/* Return number of simulations run in the Monte Carlo. */
		unsigned long NT() const;								/* Return number of time intervals run in the Monte Carlo path generation. */
		////////////////////////////
		// Mutators:
		////////////////////////////
		void NSIM(unsigned long NSIM_in);						/* Set the number of simulations to run in the Monte Carlo. */
		void NT(unsigned long NT_in);							/* Set the number of time intervals to run in the Monte Carlo path generation. */
		////////////////////////////
		// Misc. Methods:
		////////////////////////////
		double Price() const;									/* Calculate price using Monte Carlo method. */
		////////////////////////////
		// Overloaded Operators:
		////////////////////////////
		MonteCarlo& operator=(const MonteCarlo &in);		    /* Assignment Operator. */
	};
}
#endif