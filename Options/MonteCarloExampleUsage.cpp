/* MonteCarloExampleUsage.cpp
-Description:
	* Test the Monte Carlo class and compare output to exact price given by Black-Scholes-Merton equation.
*/

#include <iostream>
#include "MonteCarlo.hpp"
#include "MonteCarloExcept.hpp"
#include "EuropeanOption.hpp"
#include "Option.hpp"
#include "OptionExcept.hpp"

int main()
{
	// Test MonteCarlo class and compare Price output to exact price given by Black-Scholes equation:
	Options::EuropeanOption euroOpt(1, 40, 40, .03, .03, .3, true);
	Options::MonteCarlo newMC(euroOpt, 1000, 100);

	std::cout << "Note: Monte Carlo pricing process takes significant amount of time. " << std::endl;
	double price = newMC.Price();
	std::cout << euroOpt.Description() << std::endl;
	std::cout << "Monte Carlo Generated Price (using Euler-Maruyama): " << price << std::endl;
	std::cout << "Black-Scholes price: " << euroOpt.Price() << std::endl;

	system("pause");

	return 0;

}