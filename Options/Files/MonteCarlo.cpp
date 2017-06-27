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

#include <boost/random/variate_generator.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include "MonteCarlo.hpp"
#include "MonteCarloExcept.hpp"
#include "Option.hpp"
#include "OptionExcept.hpp"

namespace Options
{
	////////////////////////////
	// Constructors/Destructor:
	////////////////////////////
	MonteCarlo::MonteCarlo(double t, double s, double k, double b, double r, double sigma, unsigned long NSIM_in, unsigned long NT_in, bool isCall) : /* Overloaded Constructor. Set all parameters. */
		Option(t, s, k, b, r, sigma, isCall), nT(NT_in), nSIM(NSIM_in)	
	{
		mainRNG = new boost::variate_generator<boost::mt19937, boost::normal_distribution<double> >(boost::mt19937(time(0)), boost::normal_distribution<>(0, 1));
	}
	MonteCarlo::MonteCarlo(const MonteCarlo &in) : Option(in), nT(in.nT), nSIM(in.nSIM) /* Copy Constructor. */
	{
			mainRNG = new boost::variate_generator<boost::mt19937, boost::normal_distribution<double> >(boost::mt19937(time(0)), boost::normal_distribution<>(0, 1));
	}
	MonteCarlo::~MonteCarlo()													/* Destructor. */
	{
		delete mainRNG;
	}
	////////////////////////////
	// Accessors:
	////////////////////////////
	unsigned long MonteCarlo::NSIM() const							/* Return number of simulations run in the Monte Carlo. */
	{
		return nSIM;
	}
	unsigned long MonteCarlo::NT() const								/* Return number of time intervals run in the Monte Carlo path generation. */
	{
		return nT;
	}
	////////////////////////////
	// Mutators:
	////////////////////////////
	void MonteCarlo::NSIM(unsigned long NSIM_in)						/* Set the number of simulations to run in the Monte Carlo. */
	{
		nSIM = NSIM_in;
	}
	void MonteCarlo::NT(unsigned long NT_in)							/* Set the number of time intervals to run in the Monte Carlo path generation. */
	{
		nT = NT_in;
	}
	////////////////////////////
	// Misc. Methods:
	////////////////////////////
	double MonteCarlo::Price() const		/* Get price of option using Monte Carlo method with Euler-Maruyama pdf. */
	{
		// NSIM is number of , 1/NT is the time divisor (discretizes "t" into number of subintervals).
		// As NSIM AND NT approach infinity, GeneratePrice approaches the exact price given by the Black-Scholes equation or the American Perpetual Option pricing method. 
		double S_0, output = 0, payoff = 0;
		for (unsigned long currTrial = 0; currTrial < nSIM; currTrial++)
		{
			// Reset the path:
			S_0 = Param("s");
			// Generate path using Euler-Maruyama partial differentiation scheme:
			for (unsigned long currTimeInterval = 0; currTimeInterval < nT; currTimeInterval++)
			{
				S_0 += (Param("r") * S_0 * (1 / nT)) + (Param("sigma") * std::sqrt(1 / nT) * (*mainRNG)());
			}
			// Calculate payoff of option at expiry depending on type:
			if (Option::Type())
			{
				payoff += std::max(S_0 - Param("k"), 0.0);
			}
			else
			{
				payoff += std::max(Param("k") - S_0, 0.0);
			}
			// Discount the payoff back to present and accumulate:
			output += payoff * exp(-Param("r") * Param("t")) / nSIM;
		}
		// Return the average discounted payoff:
		return output;
	}
	////////////////////////////
	// Overloaded Operators:
	////////////////////////////
	MonteCarlo& MonteCarlo::operator=(const MonteCarlo &in)									/* Assignment Operator. */
	{
		if (this != &in)
		{
			Option::operator=(in);
		}
		return *this;
	}
}